#include <iostream>
#include <thread>
using namespace std;
void worker(int val, int &ref){
    val += 10; ref += 10;
    cout << "Inside thread val=" << val << " ref=" << ref << endl;
}
int main(){
    int local_x=5, local_y=5;
    thread t(worker, local_x, ref(local_y));
    t.join();
    cout << "After: x=" << local_x << " [value copy, unchanged] y=" << local_y << " [ref changed]" << endl;
    return 0;
}