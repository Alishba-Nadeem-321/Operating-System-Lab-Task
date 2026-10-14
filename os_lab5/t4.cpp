#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    cout << "Current Process PID: " << GetCurrentProcessId() << endl;
    cout << "Parent Process PPID: " << GetCurrentProcessId()-100 << " [Simulated]" << endl;
    cout << "Fork returned 0 in child, child PID in parent" << endl;
    return 0;
}