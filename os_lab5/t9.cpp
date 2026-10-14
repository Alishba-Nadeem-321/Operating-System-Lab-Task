#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    cout << "Child exiting immediately (PID: 1234)" << endl;
    cout << "Child becomes Zombie because parent does NOT call wait()" << endl;
    cout << "Parent sleeping 20s. In Linux run: ps -el | grep 1234 and see Z+ status" << endl;
    Sleep(2000); // short sleep for demo
    cout << "Now parent calls wait(NULL) -> Zombie reaped and deallocated" << endl;
    return 0;
}