#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx;   // Mutex
int sharedCounter = 0;

void taskFunction2(const std::string& name) {
    for (int i = 0; i < 5; ++i) {
        {
            std::lock_guard<std::mutex> lock(mtx);  // Auto lock/unlock
            std::cout << name << " working, counter = " << sharedCounter << std::endl;
            ++sharedCounter;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        } // mutex automatically released here
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}



void taskFunction(const std::string& name) {
    for (int i = 0; i < 5; ++i) {
        mtx.lock();   // Lock mutex (enter critical section)
        std::cout << name << " entering critical section, counter = " << sharedCounter << std::endl;
        ++sharedCounter;
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work
        std::cout << name << " leaving critical section, counter = " << sharedCounter << std::endl;
        mtx.unlock(); // Unlock mutex
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    std::thread t1(taskFunction, "Thread 1");
    std::thread t2(taskFunction2, "Thread 2");

    t1.join();
    t2.join();

    std::cout << "Final counter value = " << sharedCounter << std::endl;
    return 0;
}

