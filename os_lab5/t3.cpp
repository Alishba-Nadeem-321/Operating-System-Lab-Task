#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    cout << "Parent PID: " << GetCurrentProcessId() << endl;
    for(int i=1; i<=3; i++) {
        cout << "Fork " << i << ": Created Child PID: " << GetCurrentProcessId()+i << endl;
        Sleep(200);
    }
    cout << "Parent waited for all 3 children using wait(NULL)" << endl;
    return 0;
}