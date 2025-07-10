#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node {
    int data;             
    struct Node* next;    
} Node;
typedef struct Stack {
    Node* top;           
} Stack;
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
void initStack(Stack* stack) {
    stack->top = NULL;
}
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d onto the stack\n", data);
}
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->top->data;
}
void printStack(Stack* stack) {
    Node* current = stack->top;
    printf("Created by EKTA IT-1");
    printf("Stack (top to bottom): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printStack(&stack);
    printf("Top item is %d\n", peek(&stack));
    printf("Popped item is %d\n", pop(&stack));
    printStack(&stack);
    printf("Popped item is %d\n", pop(&stack));
    printStack(&stack);
    printf("Popped item is %d\n", pop(&stack));
    printStack(&stack);
    return 0;
}
