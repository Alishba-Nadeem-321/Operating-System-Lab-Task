#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    cout << "Child started. Initial Parent PID: " << GetCurrentProcessId() << endl;
    cout << "Parent exiting immediately. Child is now orphaned." << endl;
    Sleep(2000);
    cout << "Child after parent exit. New Parent PID: 1 [Adopted by systemd/init]" << endl;
    return 0;
}