#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;             
    struct Node* next;    
} Node;

typedef struct Queue {
    Node* front;          
    Node* rear;           
} Queue;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}


void enqueue(Queue* q, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued %d\n", data);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;  
    }
    free(temp);
    return data;
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);
    }
    return q->front->data;
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        printf("Created by EKTA IT-1");
        return;
    }
    Node* current = q->front;
    printf("Queue (front to rear): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
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
