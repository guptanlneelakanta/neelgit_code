#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t binSem; // Binary semaphore

void* threadFunc1(void* arg) {
    for (int i = 0; i < 5; ++i) {
        sem_wait(&binSem); // Wait (take) the semaphore
        std::cout << "Thread 1: Got semaphore, working..." << std::endl;
        sleep(1); // Simulate work
        std::cout << "Thread 1: Releasing semaphore" << std::endl;
        sem_post(&binSem); // Release semaphore
        sleep(1);
    }
    return nullptr;
}

void* threadFunc2(void* arg) {
    for (int i = 0; i < 5; ++i) {
        sem_wait(&binSem);
        std::cout << "Thread 2: Got semaphore, working..." << std::endl;
        sleep(1);
        std::cout << "Thread 2: Releasing semaphore" << std::endl;
        sem_post(&binSem);
        sleep(1);
    }
    return nullptr;
}

int main() {
    pthread_t t1, t2;

    // Initialize binary semaphore with value 1
    sem_init(&binSem, 0, 1);

    pthread_create(&t1, nullptr, threadFunc1, nullptr);
    pthread_create(&t2, nullptr, threadFunc2, nullptr);

    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);

    sem_destroy(&binSem);
    return 0;
}

