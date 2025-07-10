#include <stdio.h>
#include <stdlib.h>

#define MAX 100 
typedef struct {
    int arr[MAX];
    int top;
} Stack;
void initialize(Stack* stack) {
    stack->top = -1;
}
int is_full(Stack* stack) {
    return stack->top == MAX - 1;
}
int is_empty(Stack* stack) {
    return stack->top == -1;
}
void push(Stack* stack, int value) {
    if (is_full(stack)) {
        printf("Stack is full. Cannot push %d\n", value);
    } else {
        stack->arr[++stack->top] = value;
        printf("%d pushed to stack\n", value);
    }
}
int pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty. Cannot pop\n");
        return -1;  
    } else {
        return stack->arr[stack->top--];
    }
}
void show(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d\n", stack->arr[i]);
        }
    }
}
void menu() {
    Stack stack;
    int choice, value;

    initialize(&stack);

    do {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Show\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("%d popped from stack\n", value);
                }
                break;

            case 3:
                show(&stack);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
}
int main() {
    menu();
    printf ("Created by EKTA IT-1");
    return 0;
}
