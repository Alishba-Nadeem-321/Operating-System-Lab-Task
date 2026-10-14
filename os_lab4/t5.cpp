#include <iostream>
#include <thread>
using namespace std;
int counter=0;
void increment_routine(){ for(int i=0;i<100000;i++) counter++; }
int main(){
    thread t1(increment_routine), t2(increment_routine);
    t1.join(); t2.join();
    cout << "Expected 200000, Got " << counter << " -> Race Condition" << endl;
    return 0;
}