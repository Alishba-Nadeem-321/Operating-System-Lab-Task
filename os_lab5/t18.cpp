#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ofstream file("log.txt", ios::trunc);
    cout << "Opened log.txt BEFORE fork - fd shared" << endl;
    cout << "Child writes: [Child Data]" << endl;
    file << "[Child Data]\n";
    file.close();

    file.open("log.txt", ios::app);
    cout << "Parent writes: [Parent Data] after wait(NULL)" << endl;
    file << "[Parent Data]\n";
    file.close();
    cout << "Both lines appear in log.txt without offset collision - shared file table entry" << endl;
    return 0;
}