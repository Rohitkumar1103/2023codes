#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node* createNode(int data){
struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->link=NULL;

    return newNode;
}
void addAtEnd(struct Node* head, int data){
    struct Node* ptr,*temp;
    ptr=head;
    temp=(struct Node*)malloc(sizeof(struct Node));

    temp->data=data;
    temp->link=NULL;

    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
}

void addAtPos(struct Node* head,int data,int pos){
    struct Node* ptr=createNode(data);
    ptr=head;
    struct Node* temp;
    temp->link=data;
    temp->link=NULL;

    pos--;
    while(pos !=1)
    {
        ptr=ptr->link;
        pos--;
    }
    temp->link=ptr;
    ptr->link=temp;
}
 
int main(){
;
    struct Node* head=createNode(76);
    head->data=76;
    head->link=NULL;

    addAtEnd(head,43);
    addAtEnd(head,89);

    int data=67,position =3;

    addAtPos(head,data,position);
    struct Node* ptr=head;

    while(ptr !=NULL){
        printf("%d",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}