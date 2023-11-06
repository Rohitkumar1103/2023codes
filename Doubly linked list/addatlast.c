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
    struct Node* tem=malloc(sizeof(struct Node));
    tem->prev=NULL;
    tem->data=data;
    tem->next=NULL;
    tem->next=head;
    head->prev=tem;
    head=tem;
    return head;
}

struct Node* addatlast(struct Node* head,int data){
    struct Node* temp;
    struct Node* tp;
    temp=malloc(sizeof(struct Node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    tp=head;
    while(tp->next!=NULL){
        tp=tp->next;
    }
        tp->next=temp;
        temp->prev=tp;
        return head;
}

int main(){
    struct Node* head=NULL;
    head=create(head,65);
    head=addatbeg(head,23);
    head=addatlast(head,78);

    struct Node* ptr=head;
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}