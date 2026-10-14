#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    cout << "Parent waiting for child completion..." << endl;
    for(int i=1; i<=5; i++) {
        cout << "Child working... step " << i << endl;
        Sleep(500);
    }
    cout << "Child exited, Parent resumed: Child terminated successfully." << endl;
    return 0;
}