#include <stdio.h>
#include <stdbool.h> // For bool type

// Assuming an RTOS environment, these would be provided by the RTOS API
// For demonstration, we'll simulate them.
typedef struct {
    bool value; // true for available, false for taken
} SemaphoreHandle_t;

// Simulate semaphore creation (initializes to available)
void xSemaphoreCreateBinary(SemaphoreHandle_t *sem) {
    sem->value = true; // Initially available
}

// Simulate taking the semaphore
bool xSemaphoreTake(SemaphoreHandle_t *sem, int timeout_ms) {
    // In a real RTOS, this would block if not available
    // and handle timeouts. Here, a simple check.
    if (sem->value == true) {
        sem->value = false; // Take the semaphore
        return true;
    }
    return false; // Not available
}

// Simulate giving the semaphore
void xSemaphoreGive(SemaphoreHandle_t *sem) {
    sem->value = true; // Make the semaphore available
}

// Global semaphore handle
SemaphoreHandle_t xBinarySemaphore;

// Task 1 function
void Task1(void *pvParameters) {
    (void) pvParameters; // Suppress unused parameter warning

    while (1) {
        // Task 1 tries to take the semaphore
        if (xSemaphoreTake(&xBinarySemaphore, 0)) { // 0 timeout for non-blocking check
            printf("Task 1: Taken semaphore, performing work...\n");
            // Simulate some work
            for (volatile int i = 0; i < 100000; i++); 
            printf("Task 1: Work done, giving semaphore.\n");
            xSemaphoreGive(&xBinarySemaphore); // Give the semaphore
        }
        // In a real RTOS, you'd typically have a delay or yield here
        // to prevent busy-waiting if the semaphore isn't immediately available.
        for (volatile int i = 0; i < 50000; i++); // Simulate a small delay
    }
}

// Task 2 function
void Task2(void *pvParameters) {
    (void) pvParameters; // Suppress unused parameter warning

    while (1) {
        // Task 2 tries to take the semaphore
        if (xSemaphoreTake(&xBinarySemaphore, 0)) { // 0 timeout for non-blocking check
            printf("Task 2: Taken semaphore, performing work...\n");
            // Simulate some work
            for (volatile int i = 0; i < 100000; i++); 
            printf("Task 2: Work done, giving semaphore.\n");
            xSemaphoreGive(&xBinarySemaphore); // Give the semaphore
        }
        // In a real RTOS, you'd typically have a delay or yield here
        for (volatile int i = 0; i < 50000; i++); // Simulate a small delay
    }
}

int main() {
    // Initialize the binary semaphore
    xSemaphoreCreateBinary(&xBinarySemaphore);

    // In a real RTOS, you would create and start the tasks here.
    // For this simulation, we'll manually call them a few times.
    printf("Starting semaphore example...\n");
 xSemaphoreGive(&xBinarySemaphore); // Give the semaphore
    // Simulate task execution cycles
    for (int i = 0; i < 10; ++i) {
        Task1(NULL);
        Task2(NULL);
    }

    printf("Semaphore example finished.\n");
    return 0;
}
