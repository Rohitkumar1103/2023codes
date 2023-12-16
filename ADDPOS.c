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
    temp=createNode(data);

    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
}

void addAtPos(struct Node* head,int data,int pos){
    struct Node* ptr=head;
    struct Node* temp=createNode(data);

    while(pos!=2)
    {
        ptr=ptr->link;
        pos--;
    }
    if (ptr == NULL) {
        printf("Invalid position\n");
        free(temp);
        return; 
    }

    temp->link = ptr->link;
    ptr->link = temp;
}
int main(){
    struct Node* head=createNode(76);
    head->data=76;
    head->link=NULL;

    addAtEnd(head,43);
    addAtEnd(head,89);
    addAtEnd(head,34);
    addAtEnd(head,90);

    int data=67,position =5;

    addAtPos(head,data,position);
    struct Node* ptr=head;

    while(ptr !=NULL){
        printf("%d-> ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}