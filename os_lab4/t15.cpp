#include <iostream>
#include <future>
#include <chrono>
using namespace std;
int heavy_calc(int x){ this_thread::sleep_for(chrono::seconds(1)); return x*x; }
int main(){
    future<int> fut = async(launch::async, heavy_calc, 10);
    cout << "Main doing concurrent work..." << endl;
    cout << "Result: " << fut.get() << endl;
    return 0;
}