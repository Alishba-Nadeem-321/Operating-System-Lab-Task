#include <iostream>
#include <thread>
#include <shared_mutex>
using namespace std;
shared_mutex rw_mtx;
int data=0;
void reader(int id){ shared_lock<shared_mutex> r(rw_mtx); cout << "Reader " << id << " reads " <<data << endl; }
void writer(int id){ unique_lock<shared_mutex> w(rw_mtx); data++; cout << "Writer " << id << " writes " << data << endl; }
int main(){ thread r1(reader,1), r2(reader,2), w1(writer,1); r1.join(); r2.join(); w1.join(); return 0; }