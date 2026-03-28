#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Structure to define our Software Timer
typedef struct {
    unsigned long interval;    // Timer duration in milliseconds
    unsigned long last_run;    // Timestamp of the last execution
    bool enabled;              // Is the timer active?
} SoftTimer;

// Function to get current "System Ticks" (Simulating an embedded tick)
unsigned long get_system_ticks() {
    // In standard C, we use clock(). In embedded (like Arduino), you'd use millis().
    return (unsigned long)(clock() * 1000 / CLOCKS_PER_SEC);
}

// Function to check if a timer has expired
bool is_timer_expired(SoftTimer *timer) {
    if (!timer->enabled) return false;

    unsigned long current_time = get_system_ticks();
    
    // Check if enough time has passed
    if (current_time - timer->last_run >= timer->interval) {
        timer->last_run = current_time; // Reset the timer
        return true;
    }
    return false;
}

int main() {
    // 1. Initialize two independent software timers
    SoftTimer blinkTimer = { .interval = 500,  .last_run = 0, .enabled = true };
    SoftTimer logTimer   = { .interval = 2000, .last_run = 0, .enabled = true };

    printf("Starting Software Timers... (Press Ctrl+C to stop)\n\n");

    // 2. The "Super Loop"
    while (1) {
        // Task A: Handling the 500ms timer
        if (is_timer_expired(&blinkTimer)) {
            printf("[TICK] 500ms passed - Toggling LED...\n");
        }

        // Task B: Handling the 2000ms timer
        if (is_timer_expired(&logTimer)) {
            printf("[LOG]  2 seconds passed - Sending Data to Server...\n");
        }

        // Task C: This code runs constantly without being blocked!
        // (Simulating other background CPU work)
    }

    return 0;
}