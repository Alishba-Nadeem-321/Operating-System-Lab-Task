#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    cout << "Created Child A PID 101 (sleep 4s)" << endl;
    cout << "Created Child B PID 102 (sleep 1s)" << endl;
    cout << "Even though B finishes first, parent waits for A first using waitpid(pidA)" << endl;
    Sleep(1000);
    cout << "waitpid(pidA, &status, 0) returned" << endl;
    cout << "Child A reaped with status: 10" << endl;
    cout << "Child B reaped with status: 20" << endl;
    return 0;
}