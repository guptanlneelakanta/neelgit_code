#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> counter{0};

void task() {
    for (int i = 0; i < 1000; ++i)
        counter++;
}

int main() {
    std::thread t1(task), t2(task);
    t1.join(); t2.join();
    std::cout << counter << std::endl; // always 2000
}
