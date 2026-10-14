#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
void logger(){
    for(int i=0;i<3;i++){
        cout << "[Daemon] flush_buffer_to_disk()" << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}
int main(){
    thread t(logger);
    t.detach();
    cout << "Main detached logger, continues" << endl;
    this_thread::sleep_for(chrono::seconds(4));
    return 0;
}