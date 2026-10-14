#include <iostream>
using namespace std;
int main() {
    int status = 42; // child called exit(42)
    cout << "Child called exit(42)" << endl;
    // Simulating WIFEXITED and WEXITSTATUS macros
    bool WIFEXITED = true;
    int WEXITSTATUS = status;
    if(WIFEXITED) cout << "Child exited normally with status: " << WEXITSTATUS << endl;
    return 0;
}