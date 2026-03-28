/*
 * Queue Implementation in C
 * Supports both Array-based and Linked List-based queues
 * Operations: Enqueue, Dequeue, Peek, Display, isEmpty, isFull
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* =============================================
 *  SECTION 1: ARRAY-BASED QUEUE (Circular)
 * ============================================= */

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} ArrayQueue;

// Initialize array queue
void arrayQueue_init(ArrayQueue *q) {
    q->front = 0;
    q->rear  = -1;
    q->size  = 0;
}

// Check if array queue is empty
bool arrayQueue_isEmpty(ArrayQueue *q) {
    return q->size == 0;
}

// Check if array queue is full
bool arrayQueue_isFull(ArrayQueue *q) {
    return q->size == MAX_SIZE;
}

// Enqueue element into array queue
bool arrayQueue_enqueue(ArrayQueue *q, int value) {
    if (arrayQueue_isFull(q)) {
        printf("  [!] Queue Overflow! Cannot enqueue %d.\n", value);
        return false;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;  // Circular increment
    q->data[q->rear] = value;
    q->size++;
    printf("  [+] Enqueued: %d\n", value);
    return true;
}

// Dequeue element from array queue
bool arrayQueue_dequeue(ArrayQueue *q, int *value) {
    if (arrayQueue_isEmpty(q)) {
        printf("  [!] Queue Underflow! Queue is empty.\n");
        return false;
    }
    *value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;  // Circular increment
    q->size--;
    printf("  [-] Dequeued: %d\n", *value);
    return true;
}

// Peek at front element without removing
bool arrayQueue_peek(ArrayQueue *q, int *value) {
    if (arrayQueue_isEmpty(q)) {
        printf("  [!] Queue is empty. Nothing to peek.\n");
        return false;
    }
    *value = q->data[q->front];
    printf("  [~] Front element: %d\n", *value);
    return true;
}

// Display all elements in array queue
void arrayQueue_display(ArrayQueue *q) {
    if (arrayQueue_isEmpty(q)) {
        printf("  [ Queue is empty ]\n");
        return;
    }
    printf("  Front -> ");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % MAX_SIZE;
        printf("[%d]", q->data[index]);
        if (i < q->size - 1) printf(" -> ");
    }
    printf(" <- Rear\n");
    printf("  Size: %d / %d\n", q->size, MAX_SIZE);
}


/* =============================================
 *  SECTION 2: LINKED LIST-BASED QUEUE
 * ============================================= */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int size;
} LinkedQueue;

// Initialize linked queue
void linkedQueue_init(LinkedQueue *q) {
    q->front = NULL;
    q->rear  = NULL;
    q->size  = 0;
}

// Check if linked queue is empty
bool linkedQueue_isEmpty(LinkedQueue *q) {
    return q->front == NULL;
}

// Enqueue element into linked queue
bool linkedQueue_enqueue(LinkedQueue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("  [!] Memory allocation failed!\n");
        return false;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (linkedQueue_isEmpty(q)) {
        q->front = newNode;
        q->rear  = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
    printf("  [+] Enqueued: %d\n", value);
    return true;
}

// Dequeue element from linked queue
bool linkedQueue_dequeue(LinkedQueue *q, int *value) {
    if (linkedQueue_isEmpty(q)) {
        printf("  [!] Queue Underflow! Queue is empty.\n");
        return false;
    }
    Node *temp = q->front;
    *value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;  // Queue became empty
    }
    free(temp);
    q->size--;
    printf("  [-] Dequeued: %d\n", *value);
    return true;
}

// Peek at front element without removing
bool linkedQueue_peek(LinkedQueue *q, int *value) {
    if (linkedQueue_isEmpty(q)) {
        printf("  [!] Queue is empty. Nothing to peek.\n");
        return false;
    }
    *value = q->front->data;
    printf("  [~] Front element: %d\n", *value);
    return true;
}

// Display all elements in linked queue
void linkedQueue_display(LinkedQueue *q) {
    if (linkedQueue_isEmpty(q)) {
        printf("  [ Queue is empty ]\n");
        return;
    }
    printf("  Front -> ");
    Node *curr = q->front;
    while (curr != NULL) {
        printf("[%d]", curr->data);
        if (curr->next != NULL) printf(" -> ");
        curr = curr->next;
    }
    printf(" <- Rear\n");
    printf("  Size: %d\n", q->size);
}

// Free all nodes in linked queue
void linkedQueue_free(LinkedQueue *q) {
    Node *curr = q->front;
    while (curr != NULL) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    q->front = NULL;
    q->rear  = NULL;
    q->size  = 0;
}


/* =============================================
 *  SECTION 3: INTERACTIVE MENU
 * ============================================= */

void printSeparator() {
    printf("\n================================================\n");
}

void demoArrayQueue() {
    printSeparator();
    printf("  DEMO: ARRAY-BASED CIRCULAR QUEUE (Max: %d)\n", MAX_SIZE);
    printSeparator();

    ArrayQueue aq;
    arrayQueue_init(&aq);
    int val;

    printf("\n>> Enqueueing 10, 20, 30, 40, 50:\n");
    arrayQueue_enqueue(&aq, 10);
    arrayQueue_enqueue(&aq, 20);
    arrayQueue_enqueue(&aq, 30);
    arrayQueue_enqueue(&aq, 40);
    arrayQueue_enqueue(&aq, 50);

    printf("\n>> Current Queue:\n");
    arrayQueue_display(&aq);

    printf("\n>> Peek at front:\n");
    arrayQueue_peek(&aq, &val);

    printf("\n>> Dequeuing 2 elements:\n");
    arrayQueue_dequeue(&aq, &val);
    arrayQueue_dequeue(&aq, &val);

    printf("\n>> Queue after dequeue:\n");
    arrayQueue_display(&aq);

    printf("\n>> Enqueueing 60, 70 (tests circular wrap):\n");
    arrayQueue_enqueue(&aq, 60);
    arrayQueue_enqueue(&aq, 70);

    printf("\n>> Final Queue:\n");
    arrayQueue_display(&aq);
}

void demoLinkedQueue() {
    printSeparator();
    printf("  DEMO: LINKED LIST-BASED QUEUE (Dynamic Size)\n");
    printSeparator();

    LinkedQueue lq;
    linkedQueue_init(&lq);
    int val;

    printf("\n>> Enqueueing 100, 200, 300, 400:\n");
    linkedQueue_enqueue(&lq, 100);
    linkedQueue_enqueue(&lq, 200);
    linkedQueue_enqueue(&lq, 300);
    linkedQueue_enqueue(&lq, 400);

    printf("\n>> Current Queue:\n");
    linkedQueue_display(&lq);

    printf("\n>> Peek at front:\n");
    linkedQueue_peek(&lq, &val);

    printf("\n>> Dequeuing 3 elements:\n");
    linkedQueue_dequeue(&lq, &val);
    linkedQueue_dequeue(&lq, &val);
    linkedQueue_dequeue(&lq, &val);

    printf("\n>> Queue after dequeue:\n");
    linkedQueue_display(&lq);

    printf("\n>> Dequeuing last element:\n");
    linkedQueue_dequeue(&lq, &val);

    printf("\n>> Attempt dequeue from empty queue:\n");
    linkedQueue_dequeue(&lq, &val);

    printf("\n>> Enqueueing 500, 600:\n");
    linkedQueue_enqueue(&lq, 500);
    linkedQueue_enqueue(&lq, 600);

    printf("\n>> Final Queue:\n");
    linkedQueue_display(&lq);

    linkedQueue_free(&lq);
    printf("\n>> Memory freed.\n");
}

void interactiveMenu() {
    int choice, value, result;
    LinkedQueue lq;
    linkedQueue_init(&lq);

    printf("\n================================================\n");
    printf("  INTERACTIVE QUEUE (Linked List)\n");
    printf("================================================\n");

    while (1) {
        printf("\n  1. Enqueue\n");
        printf("  2. Dequeue\n");
        printf("  3. Peek\n");
        printf("  4. Display\n");
        printf("  5. Exit\n");
        printf("\n  Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("  Enter value to enqueue: ");
                scanf("%d", &value);
                linkedQueue_enqueue(&lq, value);
                break;
            case 2:
                linkedQueue_dequeue(&lq, &result);
                break;
            case 3:
                linkedQueue_peek(&lq, &result);
                break;
            case 4:
                printf("\n  Queue Contents:\n");
                linkedQueue_display(&lq);
                break;
            case 5:
                linkedQueue_free(&lq);
                printf("\n  Goodbye!\n\n");
                return;
            default:
                printf("  [!] Invalid choice. Try again.\n");
        }
    }
}

/* =============================================
 *  MAIN
 * ============================================= */

int main() {    
    printf("\n================================================\n");
    printf("        QUEUE PROGRAM IN C\n");
    printf("================================================\n");
    printf("  Demonstrating two queue implementations:\n");
    printf("  1. Array-Based (Circular Queue)\n");
    printf("  2. Linked List-Based Queue\n");

    // Run demos
    demoArrayQueue();
    demoLinkedQueue();

    // Launch interactive menu
    interactiveMenu();

    return 0;
}