#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
using namespace std;
vector<mutex> forks(5);
void dine(int id){
    int left=id, right=(id+1)%5;
    int first=min(left,right), second=max(left,right);
    unique_lock<mutex> l1(forks[first]); unique_lock<mutex> l2(forks[second]);
    cout << "Philosopher " << id << " eating with forks " << first << " " << second << endl;
    this_thread::sleep_for(chrono::milliseconds(300));
    cout << "Philosopher " << id << " finished" << endl;
}
int main(){ thread p[5]; for(int i=0;i<5;i++) p[i]=thread(dine,i); for(int i=0;i<5;i++) p[i].join(); return 0; }