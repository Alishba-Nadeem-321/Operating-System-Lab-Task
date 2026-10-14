#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
using namespace std;

atomic<bool> stop_requested(false);

void worker_func(){
    while(!stop_requested){
        cout << "do_work()" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << "cleanup_resources()" << endl;
}

int main(){
    thread my_thread(worker_func);
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Manager: request_stop()" << endl;
    stop_requested = true;
    my_thread.join();
    return 0;
}