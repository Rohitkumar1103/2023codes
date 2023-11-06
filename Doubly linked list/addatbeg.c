#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* create(struct Node* head,int data){
    struct Node* temp=malloc(sizeof(struct Node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}
struct Node* addatbeg(struct Node* head,int data){
    struct Node* temp=malloc(sizeof(struct Node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}

int main(){
        struct Node* head=NULL;
        head=create(head,76);
        head=addatbeg(head,23);

    struct Node* ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        printf("%d-> ",ptr->data);
        ptr=ptr->next;
    }
return 0;
}