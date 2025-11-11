#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Utility prototypes */
void insert_front(Node **head, int value);
void insert_back(Node **head, int value);
void insert_at_pos(Node **head, int value, int pos);
void delete_front(Node **head);
void delete_end(Node **head);
void delete_at_pos(Node **head, int pos);
void display_list(Node *head);
int list_length(Node *head);

/* Implementations */
void insert_front(Node **head, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) { puts("Memory allocation failed."); return; }
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insert_back(Node **head, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) { puts("Memory allocation failed."); return; }
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void insert_at_pos(Node **head, int value, int pos) {
    if (pos <= 0) {
        printf("Position should be 1 or greater.\n");
        return;
    }
    if (pos == 1) {
        insert_front(head, value);
        return;
    }
    int len = list_length(*head);
    if (pos > len + 1) {
        printf("Invalid position. List length is %d, so max insert position is %d.\n", len, len + 1);
        return;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) { puts("Memory allocation failed."); return; }
    newNode->data = value;

    Node *temp = *head;
    for (int i = 1; i < pos - 1; ++i) temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_front(Node **head) {
    if (*head == NULL) {
        puts("List is empty. Nothing to delete.");
        return;
    }
    Node *toDel = *head;
    *head = (*head)->next;
    free(toDel);
}

void delete_end(Node **head) {
    if (*head == NULL) {
        puts("List is empty. Nothing to delete.");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node *temp = *head;
    while (temp->next->next) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void delete_at_pos(Node **head, int pos) {
    if (*head == NULL) {
        puts("List is empty. Nothing to delete.");
        return;
    }
    if (pos <= 0) {
        puts("Position should be 1 or greater.");
        return;
    }
    if (pos == 1) {
        delete_front(head);
        return;
    }
    int len = list_length(*head);
    if (pos > len) {
        printf("Invalid position. List length is %d.\n", len);
        return;
    }
    Node *temp = *head;
    for (int i = 1; i < pos - 1; ++i) temp = temp->next;
    Node *toDel = temp->next;
    temp->next = toDel->next;
    free(toDel);
}

void display_list(Node *head) {
    if (head == NULL) {
        puts("List is empty.");
        return;
    }
    printf("List: ");
    Node *temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    puts("NULL");
}

int list_length(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp) { ++count; temp = temp->next; }
    return count;
}

/* Menu-driven main */
int main() {
    Node *head = NULL;
    int choice, value, pos;

    while (1) {
        puts("\n--- Singly Linked List Operations ---");
        puts("1. Insert at front");
        puts("2. Insert at back");
        puts("3. Insert at position (1-based)");
        puts("4. Delete at front");
        puts("5. Delete at end");
        puts("6. Delete at position (1-based)");
        puts("7. Display list");
        puts("0. Exit");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value: "); scanf("%d", &value);
                insert_front(&head, value);
                break;
            case 2:
                printf("Enter value: "); scanf("%d", &value);
                insert_back(&head, value);
                break;
            case 3:
                printf("Enter value: "); scanf("%d", &value);
                printf("Enter position (1-based): "); scanf("%d", &pos);
                insert_at_pos(&head, value, pos);
                break;
            case 4:
                delete_front(&head);
                break;
            case 5:
                delete_end(&head);
                break;
            case 6:
                printf("Enter position (1-based): "); scanf("%d", &pos);
                delete_at_pos(&head, pos);
                break;
            case 7:
                display_list(head);
                break;
            case 0:
                // free remaining nodes before exit
                while (head) delete_front(&head);
                puts("Exiting. Bye!");
                return 0;
            default:
                puts("Invalid choice. Try again.");
        }
    }

    return 0;
}