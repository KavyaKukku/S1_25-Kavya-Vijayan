#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow! Cannot push.\n");
    } else {
        top++;
        stack[top] = item;
        printf("%d pushed to stack.\n", item);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty! Cannot pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void search(int item) {
    int found = 0;
    for (int i = 0; i <= top; i++) {
        if (stack[i] == item) {
            printf("%d found at position %d in the stack.\n", item, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("%d not found in the stack.\n", item);
    }
}

int main() {
    int choice, item;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter an element to search: ");
                scanf("%d", &item);
                search(item);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
