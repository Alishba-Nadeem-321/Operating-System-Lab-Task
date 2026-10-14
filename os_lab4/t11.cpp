#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
using namespace std;

class CountingSemaphore {
    int count; mutex mtx; condition_variable cv;
public:
    CountingSemaphore(int c):count(c){}
    void acquire(){ unique_lock<mutex> lock(mtx); cv.wait(lock,[this]{return count>0;}); count--; }
    void release(){ lock_guard<mutex> lock(mtx); count++; cv.notify_one(); }
};

CountingSemaphore sem(3);

void task(int id){
    sem.acquire();
    cout << "Task " << id << " acquired permit, working..." << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Task " << id << " releasing" << endl;
    sem.release();
}
int main(){
    thread t1(task,1),t2(task,2),t3(task,3),t4(task,4),t5(task,5);
    t1.join(); t2.join(); t3.join(); t4.join(); t5.join();
    return 0;
}