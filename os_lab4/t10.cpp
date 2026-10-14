#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;
queue<int> q; mutex mtx; condition_variable cv;
void producer(){
    for(int i=0;i<5;i++){ { lock_guard<mutex> l(mtx); q.push(i); cout << "Producer push " << i << endl; } cv.notify_one(); this_thread::sleep_for(chrono::milliseconds(200)); }
}
void consumer(){
    for(int i=0;i<5;i++){ unique_lock<mutex> l(mtx); cv.wait(l,[]{return!q.empty();}); cout << "Consumer pop " << q.front() << endl; q.pop(); }
}
int main(){ thread p(producer), c(consumer); p.join(); c.join(); return 0; }