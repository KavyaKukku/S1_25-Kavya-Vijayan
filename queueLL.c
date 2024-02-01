#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue a new element
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    if (queue->front == NULL)
        return -1; // Queue is empty
    
    struct Node* temp = queue->front;
    int data = temp->data;
    
    queue->front = temp->next;
    
    if (queue->front == NULL)
        queue->rear = NULL;
    
    free(temp);
    return data;
}

// Function to search for an element in the queue
int search(struct Queue* queue, int key) {
    struct Node* current = queue->front;
    int position = 1;
    
    while (current != NULL) {
        if (current->data == key)
            return position;
        
        current = current->next;
        position++;
    }
    
    return -1; // Element not found
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    struct Node* current = queue->front;
    
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();
    int choice, data, result, key;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Search\n4. Display\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;

            case 2:
                result = dequeue(queue);
                if (result != -1)
                    printf("Dequeued element: %d\n", result);
                else
                    printf("Queue is empty\n");
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &key);
                result = search(queue, key);
                if (result != -1)
                    printf("Element found at position %d\n", result);
                else
                    printf("Element not found in the queue\n");
                break;

            case 4:
                display(queue);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
