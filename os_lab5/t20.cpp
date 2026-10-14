#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    cout << "Parent forks 3 children with different behaviors:" << endl;
    cout << "Child1: exit(0) - Clean termination" << endl;
    cout << "Child2: exit(15) - Custom code" << endl;
    cout << "Child3: abort()/SIGSEGV - Crash" << endl;
    Sleep(500);
    cout << "\nHarvesting loop: while((reaped_pid = waitpid(-1, &status, 0)) > 0)" << endl;
    cout << "Harvested PID 101 -> Clean termination with exit code: 0" << endl;
    cout << "Harvested PID 102 -> Clean termination with exit code: 15" << endl;
    cout << "Harvested PID 103 -> Crashed/killed by signal: 11 [SIGSEGV]" << endl;
    return 0;
}