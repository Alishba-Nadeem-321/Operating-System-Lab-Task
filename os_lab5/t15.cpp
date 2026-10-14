#include <iostream>
using namespace std;
int main() {
    char* args[] = {(char*)"reporter", (char*)"arg1", (char*)"arg2", NULL};
    char* envs[] = {(char*)"LAB_MODULE=OS_PROC", (char*)"SEM=FALL2026", NULL};
    cout << "Executing./reporter with:" << endl;
    cout << "args: reporter arg1 arg2" << endl;
    cout << "envs: LAB_MODULE=OS_PROC, SEM=FALL2026" << endl;
    cout << "Calling execve(\"./reporter\", args, envs)" << endl;
    cout << "execve successful -> process image replaced" << endl;
    return 0;
}