#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* createNode(struct Node* head,int data){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}

int main(){
    struct Node* head=NULL;
    head=createNode(head,67);
    printf("%d",head->data);
    return 0;
}