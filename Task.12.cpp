#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mutexA;
std::mutex mutexB;

void thread1_work() {
    mutexA.lock();
    std::cout << "Thread 1 acquired Lock A , waiting for Lock B ..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mutexB.lock();
    
    mutexB.unlock();
    mutexA.unlock();
}

void thread2_work() {
    mutexB.lock();
    std::cout << "Thread 2 acquired Lock B , waiting for Lock A ..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mutexA.lock();
    
    mutexA.unlock();
    mutexB.unlock();
}

int main() {
    std::thread t1(thread1_work);
    std::thread t2(thread2_work);

    t1.join();
    t2.join();

    return 0;
}