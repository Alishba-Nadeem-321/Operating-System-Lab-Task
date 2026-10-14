#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
    cout << "Child executing 'ls -la'... [In Windows: dir]" << endl;
    // execlp replaces process image - if success next lines are unreachable
    int ret = system("dir");
    if(ret!= 0) {
        cout << "execlp failed" << endl;
    }
    cout << "Parent: Child execution completed." << endl;
    return 0;
}