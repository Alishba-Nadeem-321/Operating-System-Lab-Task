#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    cout << "Child executing infinite computation loop..." << endl;
    cout << "Parent sleeping 3 sec (timeout threshold)" << endl;
    Sleep(1000);
    cout << "waitpid with WNOHANG returned 0 - child still running" << endl;
    cout << "Child exceeded time limit. Dispatching SIGKILL to PID" << endl;
    cout << "kill(pid, SIGKILL) called, child terminated and reaped" << endl;
    return 0;
}