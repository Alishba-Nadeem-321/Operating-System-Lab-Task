#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main() {
    string line;
    while(true) {
        cout << "myshell> ";
        getline(cin, line);
        if(line=="exit") break;
        if(line.empty()) continue;
        cout << "[Child] execvp: " << line << endl;
        system(line.c_str()); // Simulates execvp in child
        cout << "[Parent] waitpid: child finished, exit status captured" << endl;
    }
    return 0;
}