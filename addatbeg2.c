#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};
struct Node* createNode(int data){
    struct Node* temp=malloc(sizeof(struct Node));
    temp->data=data;
    temp->prev=temp;
    temp->next=temp;
    return temp;
}
struct Node* addAtBeg(struct Node* tail,int data){
    struct Node* new=createNode(data);
    if(tail==NULL){
    return new;
    }
    else{
        struct Node* temp=tail->next;
        new->prev=tail;
        new->next=temp;
        temp->prev=new;
        tail->next=new;
    }
    return tail;
}
void print(struct Node* tail){
    if(tail==NULL)
        printf("Linked List is Empty.");
    else{
    struct Node* ptr=tail->next;
    do{
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=tail->next);
}
    printf("\n");
}
int main(){
    struct Node* tail;
    int data;
    tail=createNode(89);
    tail=addAtBeg(tail,67);
    print(tail);
    return 0;
}
