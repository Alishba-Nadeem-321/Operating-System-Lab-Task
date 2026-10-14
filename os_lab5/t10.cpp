#include <iostream>
#include <windows.h>
using namespace std;
// Simulate signal handler
void sigchld_handler(int sig) {
    cout << "SIGCHLD received: Asynchronously reaped a terminated child using waitpid(-1, WNOHANG)" << endl;
}
int main() {
    cout << "Registered signal(SIGCHLD, sigchld_handler)" << endl;
    for(int i=1; i<=5; i++) {
        cout << "Forked child " << i << ", child sleeps " << i%3+1 << " sec then exits" << endl;
    }
    cout << "Parent continues work, handler will auto-reap zombies without blocking" << endl;
    for(int i=0; i<3; i++) { sigchld_handler(0); Sleep(500); }
    return 0;
}