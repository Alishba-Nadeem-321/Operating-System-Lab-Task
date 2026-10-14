#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex mtxA, mtxB;
void transfer_funds(){ scoped_lock lock(mtxA, mtxB); cout << "Funds transferred - both locks atomically acquired" << endl; }
int main(){ thread t1(transfer_funds), t2(transfer_funds); t1.join(); t2.join(); return 0; }