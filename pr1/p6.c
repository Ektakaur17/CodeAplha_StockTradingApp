#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100  
typedef struct Queue {
    int items[MAX_SIZE];  
    int front;            
    int rear;             
    int size;             
} Queue;
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}


bool isEmpty(Queue* q) {
    return q->size == 0;
}


bool isFull(Queue* q) {
    return q->size == MAX_SIZE;
}

void enqueue(Queue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE; 
    q->items[q->rear] = item;
    q->size++;
    printf("Enqueued %d\n", item);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);  
    }
    int item = q->items[q->front];
    q->front = (q->front + 1) % MAX_SIZE; 
    q->size--;
    return item;
}


int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);  
    }
    return q->items[q->front];
}


void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    printf("Created by EKTA IT-1");
        return;
    }
    printf("Queue (front to rear): ");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % MAX_SIZE;
        printf("%d ", q->items[index]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printQueue(&q);

    printf("Front item is %d\n", peek(&q));
    printf("Dequeued item is %d\n", dequeue(&q));
    printQueue(&q);
    printf("Dequeued item is %d\n", dequeue(&q));
    printQueue(&q);
    printf("Dequeued item is %d\n", dequeue(&q));
    printQueue(&q);
    return 0;
}
