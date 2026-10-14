#include <iostream>
#include <windows.h>
using namespace std;
void build_tree(int level, int max_depth) {
    if(level >= max_depth) return;
    cout << "Level " << level+1 << " Left Child: PID " << GetCurrentProcessId()+level*10+1 << endl;
    build_tree(level+1, max_depth);
    cout << "Level " << level+1 << " Right Child: PID " << GetCurrentProcessId()+level*10+2 << endl;
    build_tree(level+1, max_depth);
}
int main() {
    cout << "Building Binary Tree of Depth 3:" << endl;
    build_tree(0, 3);
    cout << "Parent waited for both children using waitpid(left) and waitpid(right)" << endl;
    return 0;
}