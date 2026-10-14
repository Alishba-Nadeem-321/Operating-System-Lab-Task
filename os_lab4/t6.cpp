#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int counter=0;
mutex M;
void safe_increment(){
    for(int i=0;i<100000;i++){ lock_guard<mutex> lock(M); counter++; }
}
int main(){
    thread t1(safe_increment), t2(safe_increment);
    t1.join(); t2.join();
    cout << "With mutex, counter = " << counter << " [Correct]" << endl;
    return 0;
}