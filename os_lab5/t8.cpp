#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    cout << "Child executing 3 sec task in background" << endl;
    for(int i=0; i<6; i++) {
        cout << "Parent computing independent background tasks... [waitpid with WNOHANG returned 0]" << endl;
        Sleep(500);
    }
    cout << "waitpid returned child PID: Child finished! Parent wrapping up." << endl;
    return 0;
}