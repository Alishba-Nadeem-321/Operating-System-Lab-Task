#include <iostream>
#include <thread>
using namespace std;
void worker_fn(){ cout << "Worker running" << endl; }
int main(){
    { jthread jt(worker_fn); cout << "Inside scope, jthread created" << endl; }
    cout << "Scope exited, destructor auto called join()" << endl;
    return 0;
}