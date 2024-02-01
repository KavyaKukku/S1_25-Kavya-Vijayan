#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top;

void push(int value) {
    struct Node* newNode;
    newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    struct Node* temp;
    temp=top;
    if (top==0) {
        printf("underflow\n");
    
    }
    else{
        printf("top element is%d\n",top->data);

    top = top->next;
    free(temp);
}
}
void display() {
    struct Node* temp;
    temp = top;
    
        printf("the elements are.\n");
        if(top==0)
        {
            printf("empty");
        }
        else
    {
    
    while (temp!= 0) {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    }
    printf("NULL\n");
}
void search()
{
    struct Node* temp=top;
    int value;
    int found=0;
    printf("Enter the value to search");
    scanf("%d",&value);
    while (temp!=NULL)
    {
        if(temp->data==value)
        {
            printf("found");
            found=1;
            break;
        }
        temp=temp->next;
    }
        if(!found)
        {
            printf("not found");
        }
    }
   
int main() {
    int choice, element;
    do
    
     {
        printf("Stack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4.search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                search();
                break;
            case 5:
                printf("Exiting...\n");
                
            default:
                printf("Invalid choice. Please try again.\n");
        }}
    while(choice!=5);
    return 0;
   
}
