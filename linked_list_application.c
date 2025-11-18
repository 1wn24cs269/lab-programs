#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Global pointers for two lists
struct node *head = NULL, *head2 = NULL;

// Function to insert at end of a list
void insertEnd(struct node **head, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Print list
void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Sort the linked list in ascending order
void sortList() {
    if (head == NULL || head->next == NULL) {
        printf("List too short to sort!\n");
        return;
    }
    struct node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted in ascending order.\n");
}

// Reverse the linked list
void reverseList() {
    struct node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed successfully.\n");
}

// Concatenate two linked lists: head (main) and head2 (second list)
void concatenateLists() {
    if (head == NULL) {
        head = head2;
        head2 = NULL;
        printf("Concatenation done.\n");
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    head2 = NULL;
    printf("Concatenation done.\n");
}

// Example usage
int main() {
    // Build first list
    insertEnd(&head, 8);
    insertEnd(&head, 3);
    insertEnd(&head, 7);
    insertEnd(&head, 4);

    // Build second list
    insertEnd(&head2, 10);
    insertEnd(&head2, 2);

    printf("First list: ");
    printList(head);
    printf("Second list: ");
    printList(head2);

    sortList();
    printf("Sorted first list: ");
    printList(head);

    reverseList();
    printf("Reversed first list: ");
    printList(head);

    concatenateLists();
    printf("After concatenation: ");
    printList(head);

    return 0;
}
