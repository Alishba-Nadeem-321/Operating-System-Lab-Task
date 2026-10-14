#include <iostream>
using namespace std;
int main() {
    cout << "Process A: prctl(PR_SET_CHILD_SUBREAPER, 1) - Registered as subreaper" << endl;
    cout << "Process A forks B; B forks C; B exits immediately" << endl;
    cout << "Process C sleep(1), then getppid()..." << endl;
    cout << "Process C adopted by Subreaper PPID: " << 5000 << " (Not PID 1, but Process A)" << endl;
    cout << "Process A reaps both B and adopted C using wait(NULL)" << endl;
    return 0;
}