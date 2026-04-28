#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

SemaphoreHandle_t xBinarySemaphore;

// Task 1: Waits for semaphore (like waiting for an event)
void Task_Wait(void *pvParameters)
{
    for (;;)
    {
        if (xSemaphoreTake(xBinarySemaphore, portMAX_DELAY) == pdTRUE)
        {
            printf("Task_Wait: Received signal! Processing...\n");
        }
    }
}

// Task 2: Gives semaphore (signals event)
void Task_Signal(void *pvParameters)
{
    for (;;)
    {
        vTaskDelay(pdMS_TO_TICKS(2000));  // Simulate some work
        printf("Task_Signal: Sending signal...\n");
        xSemaphoreGive(xBinarySemaphore);  // Signal other task
    }
}

int main(void)
{
    // Create binary semaphore
    xBinarySemaphore = xSemaphoreCreateBinary();

    // Create two tasks
    xTaskCreate(Task_Wait, "WaitTask", 1000, NULL, 1, NULL);
    xTaskCreate(Task_Signal, "SignalTask", 1000, NULL, 1, NULL);

    // Start scheduler
    vTaskStartScheduler();

    for (;;);
}

