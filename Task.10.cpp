#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

std::queue<int> buffer;
const size_t CAPACITY = 3;
std::mutex mtx;
std::condition_variable cv_producer, cv_consumer;

void producer() {
    for (int item = 1; item <= 5; ++item) {
        std::unique_lock<std::mutex> lock(mtx);
        cv_producer.wait(lock, []() { return buffer.size() < CAPACITY; });
        buffer.push(item);
        std::cout << "Produced : " << item << std::endl;
        cv_consumer.notify_one();
    }
}

void consumer() {
    for (int i = 1; i <= 5; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv_consumer.wait(lock, []() { return !buffer.empty(); });
        int item = buffer.front();
        buffer.pop();
        std::cout << "Consumed : " << item << std::endl;
        cv_producer.notify_one();
    }
}

int main() {
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}