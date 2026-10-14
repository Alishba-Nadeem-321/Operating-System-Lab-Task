#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <chrono>
using namespace std;
queue<function<void()>> tasks; mutex m; condition_variable cv; bool stop=false;
void worker_loop(){ while(true){ function<void()> task; { unique_lock<mutex> l(m); cv.wait(l,[]{return stop||!tasks.empty();}); if(stop&&tasks.empty()) return; task=move(tasks.front()); tasks.pop(); } task(); } }
int main(){
    thread pool[2] = {thread(worker_loop), thread(worker_loop)};
    { lock_guard<mutex> l(m); tasks.push([]{cout<<"Task A executed"<<endl;}); tasks.push([]{cout<<"Task B executed"<<endl;}); }
    cv.notify_all(); this_thread::sleep_for(chrono::seconds(1));
    stop=true; cv.notify_all(); pool[0].join(); pool[1].join(); return 0;
}