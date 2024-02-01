#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("%d enqueued successfully.\n", value);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        int dequeuedValue = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        printf("%d dequeued successfully.\n", dequeuedValue);
    }
}

int search(int value) {
    for (int i = front; i <= rear; i++) {
        if (queue[i] == value) {
            return i;
        }
    }
    return -1; // Element not found
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value, result;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                result = search(value);
                if (result != -1) {
                    printf("%d found at position %d.\n", value, result);
                } else {
                    printf("%d not found in the queue.\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
