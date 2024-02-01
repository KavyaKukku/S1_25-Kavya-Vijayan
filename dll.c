#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
struct node*prev;
};
struct node*head,*tail;

static int size=0;
void insert_head()
{
int element;
struct node*newnode;
newnode=(struct node*)malloc(sizeof(struct node));
printf("\nenter the elememnt");
scanf("%d",&element);
newnode->data=element;
newnode->next=0;
newnode->prev=0;
if(head==0)
{
head=tail=newnode;
}
else{
head->prev=newnode;
newnode->next=head;
head=newnode;}
size++;
}
void insert_end()
{
int element;
struct node*newnode;
newnode=(struct node*)malloc(sizeof(struct node));
printf("\nenter the element");
 scanf("%d",&element);
newnode->data=element;
newnode->next=0;
newnode->prev=0;
if(tail==0)
{
head=newnode;
tail=newnode;
}
else{
tail->next=newnode;
newnode->prev=tail;
tail=newnode;}
size++;
}
void insert_pos()
{
struct node*newnode;
struct node*temp;
int i=1,element;
int position;

printf("\n enter the position");
scanf("%d",&position);

if(position<0 || position>size)
{
printf("position is invalid");
}


else if (position==0){
printf("\nenter the element");
scanf("%d",&element);

insert_head();


}
else if(position==size)
{printf("\nenter the element");
scanf("%d",&element);

insert_end();
}
else{
printf("\nenter the element");
scanf("%d",&element);
temp=head;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=element;
while(i<position-1)
{
temp=temp->next;
i++;
}
newnode->next=temp->next;
temp->next=newnode;
(temp->next)->prev=newnode;
newnode->prev=temp;
size++;}}
void delete_head()
{
struct node*temp;
if(head==0){
printf("link is empty");}
else{
printf("\ndeleted node is:%d",temp->data);
temp=head;
head=head->next;
if(head!=0)
{
head->prev=0;}
else{
tail=0;
free(temp);
size--;
}}}
void delete_end()
{struct node*temp;
if(tail==0){
printf("linked list is empty");
}
else{
temp=tail;
printf("deleted node is:%d",temp->data);
tail=tail->prev;
if(tail==0)
 {
head==0;}
else{
tail->next=0;
free(temp);
size--;}}}
void delete_pos(){
struct node*temp;
int pos,i=1;
printf("enter the position");
scanf("%d",&pos);
if(pos<0||pos>size)
{
printf("invalid");
}
else if(pos==0)
{
delete_head();
}
else if(pos==size-1)
{
delete_end();
}else{
temp=head;
while(i<pos){
temp=temp->next;
i++;
}
printf("\ndeleted node is:%d",head->data);
(temp->prev)->next=temp->next;
(temp->next)->prev=temp->prev;
free(temp);size--;
}}
void display()
{
struct node*temp;
if(head==0){
printf("\nlinked list is empty");}
else{
printf("\nlinked list is:\n");
temp=head;
while(temp!=0)
{
printf("%d",temp->data);
 temp=temp->next;}
}
}
void search(){
int element,count=1;
struct node*temp;

scanf("%d",&element);
if(head==0){
printf("\nthe link is empty");
}
else{
printf("\nenter the value to search");
scanf("%d",&element);
temp=head;
do{
if(temp->data==element)
{
printf("\nthe element is found %d at position %d",temp->data,count);
}
count++;
temp=temp->next;
}
while(temp!=0);
printf("\nthe element is not found");
}}
void main()
{
int choice,element;
do{
printf("\n1.Insert Head\n2.-Insert End\n3-Insert Position\n4.Delete Head\n5.Delete End\n6.Delete Position\n7.Display\n8.Search\n9.exit");
printf("\nEnter a choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:

insert_head();
break;
case 2:
insert_end();
break;
case 3:
insert_pos();
break;
case 4:
delete_head();
break;
case 5:
delete_end();
break;
case 6:

delete_pos();
break;
case 7:
display();
break;
case 8:
search();
break;

case 9:
printf("exit");
break;
default:
printf("not valid");
}}while(choice!=9);
}
                         
                                                                          
