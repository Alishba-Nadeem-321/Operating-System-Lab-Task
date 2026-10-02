#include <iostream>
#include <thread>

int counter = 0;

void increment_task() {
    for (int i = 0; i < 100000; ++i) {
        counter++;
    }
}

int main() {
    std::thread thread1(increment_task);
    std::thread thread2(increment_task);

    thread1.join();
    thread2.join();

    std::cout << "Expected : 200000 | Actual counter : " << counter << std::endl;
    return 0;
}