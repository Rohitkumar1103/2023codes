#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

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

int main(){
        struct Node* head;

        addAtEnd(head,65);
}
