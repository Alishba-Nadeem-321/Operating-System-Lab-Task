#include <iostream>
#include <thread>
using namespace std;
void child_routine(){
    cout << "Child executing with unique thread ID: " << this_thread::get_id() << endl;
}
int main(){
    cout << "Main Thread ID: " << this_thread::get_id() << endl;
    thread t(child_routine);
    t.join();
    cout << "Main after join" << endl;
    return 0;
}