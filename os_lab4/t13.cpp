#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
using namespace std;

class Latch {
    int count; mutex mtx; condition_variable cv;
public:
    Latch(int c):count(c){}
    void count_down(){ lock_guard<mutex> lock(mtx); count--; if(count<=0) cv.notify_all(); }
    void wait(){ unique_lock<mutex> lock(mtx); cv.wait(lock,[this]{return count<=0;}); }
};

Latch start_flag(1);

void worker(int id){
    cout << "Worker " << id << " waiting for latch" << endl;
    start_flag.wait();
    cout << "Worker " << id << " run benchmark!" << endl;
}
int main(){
    thread t1(worker,1),t2(worker,2);
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Main prepared memory, count_down() -> unblocks all" << endl;
    start_flag.count_down();
    t1.join(); t2.join();
    return 0;
}