#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed. Stack Overflow.\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("Pushed %d onto the stack.\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow. No elements to pop.\n");
        return;
    }

    struct Node* temp = top;
    printf("Popped %d from the stack.\n", top->data);
    top = top->next;
    free(temp);
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", top->data);
    }
}

void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d → ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
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
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}