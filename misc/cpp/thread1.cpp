#include <iostream>
#include <thread>
#include <mutex>

void task() {
    std::cout << "Hello from thread\n";
}
int cnt =0;

void increment()
{
    std::mutex m;
    for(int i=0; i<1000; i++)
    {
        std::lock_guard<std::mutex> lock(m);
        cnt++;
    }
}

int main() {
    std::thread t(task);   // start thread
    t.join();              // wait for completion

    std::thread t2([](){
        std::cout << "Lambda thread\n";
    });
    t2.join();

    std::thread t3(increment);
    std::thread t4(increment);

    t3.join();
    t4.join();
    std::cout << cnt << "\n";

    return 0;
}


