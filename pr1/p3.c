#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;
ListNode* reverse_linked_list_iterative(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* next_node = NULL;

    while (current != NULL) {
        next_node = current->next;  
        current->next = prev;       
        prev = current;           
        current = next_node;       
    }
    return prev; 
}
ListNode* reverse_linked_list_recursive(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;  
    }

    ListNode* new_head = reverse_linked_list_recursive(head->next);
    
    
    head->next->next = head;
    head->next = NULL;

    return new_head;
}
ListNode* create_node(int value) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}
void print_list(ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}
void free_list(ListNode* head) {
    ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {
    ListNode* head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);

    printf("Original list:\n");
    print_list(head);
    ListNode* reversed_head_iterative = reverse_linked_list_iterative(head);
    printf("Reversed list (iterative):\n");
    print_list(reversed_head_iterative);
    head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);

    
    ListNode* reversed_head_recursive = reverse_linked_list_recursive(head);
    printf("Reversed list (recursive):\n");
    print_list(reversed_head_recursive);

    free_list(reversed_head_iterative);
    free_list(reversed_head_recursive);
printf ("Created by EKTA IT-1");
    return 0;
}
