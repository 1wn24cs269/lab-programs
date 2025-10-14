#include <stdio.h>
#include <stdlib.h>

#define MAX 2

int stack[MAX];
int top = -1;

void push(int value);
void pop();
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("%d is being deleted\n", stack[top]);
        top--;
    }
}

void display() {
    int i;
	if (top == -1) {
        printf("No elements present\n");
    } else {
        printf("Stack elements are:\n");
        for ( i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

