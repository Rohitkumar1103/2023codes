#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* create(int data){
    struct Node* temp=malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=temp;
    return temp;
}
struct Node* addAtBeg(struct Node* tail,int data){
    struct Node* new;
    new=malloc(sizeof(struct Node));
    new->data=data;
    new->next=tail->next;
    tail->next=new;
    return tail;
}
void print(struct Node* tail){
    struct Node* ptr=tail->next;
    do{
        printf("%d-> ",ptr->data);
        ptr=ptr->next;
    }
    while(ptr!=tail->next);
}
int main(){
    struct Node* tail;
    tail=create(67);
    tail=addAtBeg(tail,23);
    tail=addAtBeg(tail,76);
    print(tail);
    return 0;
}