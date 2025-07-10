#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
void insertAtFront(Node** head, int data);
void insertAtEnd(Node** head, int data);
void insertAtPosition(Node** head, int data, int position);
void deleteFirst(Node** head);
void deleteEnd(Node** head);
void deletePosition(Node** head, int position);
void traversal(Node* head);
void display(Node* head);
void menu();

void insertAtFront(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("Node inserted at the front.\n");
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* temp = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted at the end.\n");
}

void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* temp = *head;
    newNode->data = data;

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        for (int i = 0; temp != NULL && i < position - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of range.\n");
            free(newNode);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted at position %d.\n", position);
}

void deleteFirst(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("First node deleted.\n");
}

void deleteEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = *head;
    Node* prev = NULL;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
    } else {
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    printf("Last node deleted.\n");
}

void deletePosition(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = *head;
    Node* prev = NULL;

    if (position == 0) {
        *head = temp->next;
        free(temp);
    } else {
        for (int i = 0; temp != NULL && i < position; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of range.\n");
            return;
        }
        prev->next = temp->next;
        free(temp);
    }
    printf("Node deleted at position %d.\n", position);
}

void traversal(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    traversal(head);
}

void menu() {
    printf("Menu:\n");
    printf("a) Insert at Front\n");
    printf("b) Insert at End\n");
    printf("c) Insert at Position\n");
    printf("d) Delete First\n");
    printf("e) Delete End\n");
    printf("f) Delete at Position\n");
    printf("g) Traversal\n");
    printf("h) Display\n");
    printf("i) Exit\n");
}

int main() {
    Node* head = NULL;
    char choice;
    int data, position;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                break;
            case 'b':
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 'c':
                printf("Enter data and position to insert: ");
                scanf("%d %d", &data, &position);
                insertAtPosition(&head, data, position);
                break;
            case 'd':
                deleteFirst(&head);
                break;
            case 'e':
                deleteEnd(&head);
                break;
            case 'f':
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deletePosition(&head, position);
                break;
            case 'g':
                traversal(head);
                break;
            case 'h':
                display(head);
                break;
            case 'i':
                printf("Exiting...\n");
                printf("Created by EKTA IT-1");
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
