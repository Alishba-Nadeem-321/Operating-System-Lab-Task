#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;
int main(){
    promise<int> prom; future<int> fut = prom.get_future();
    thread t([&prom]{ this_thread::sleep_for(chrono::seconds(1)); prom.set_value(42); });
    cout << "Main waiting fut.get()..." << endl;
    cout << "Result: " << fut.get() << endl;
    t.join(); return 0;
}