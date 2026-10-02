#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void safe_increment() {
    for (int i = 0; i < 100000; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        counter++;
    }
}

int main() {
    std::thread thread1(safe_increment);
    std::thread thread2(safe_increment);

    thread1.join();
    thread2.join();

    std::cout << "Final counter with Mutex : " << counter << std::endl;
    return 0;
}