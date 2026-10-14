#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class Barrier {
    int threshold, count, generation;
    mutex mtx; condition_variable cv;
public:
    Barrier(int n):threshold(n),count(0),generation(0){}
    void arrive_and_wait(){
        unique_lock<mutex> lock(mtx);
        int gen = generation;
        count++;
        if(count == threshold){
            count = 0;
            generation++;
            cv.notify_all();
        } else {
            cv.wait(lock,[this,gen]{return gen!= generation;});
        }
    }
};

Barrier sync_point(3);

void worker(int id){
    cout << "Worker " << id << " Phase 1 done" << endl;
    sync_point.arrive_and_wait();
    cout << "Worker " << id << " Phase 2 started" << endl;
}
int main(){
    thread t1(worker,1),t2(worker,2),t3(worker,3);
    t1.join(); t2.join(); t3.join();
    return 0;
}