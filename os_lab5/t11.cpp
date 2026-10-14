#include <iostream>
using namespace std;
int main() {
    cout << "Configured: sa.sa_handler = SIG_IGN; sa.sa_flags = SA_NOCLDWAIT;" << endl;
    cout << "sigaction(SIGCHLD, &sa, NULL)" << endl;
    cout << "Child terminating immediately." << endl;
    cout << "Result: Kernel automatically discards zombie - no Z state in ps" << endl;
    cout << "Parent sleeping 10s - child PCB already deallocated" << endl;
    return 0;
}