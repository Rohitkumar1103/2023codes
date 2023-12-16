#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;

};

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->link=NULL;
    return newNode;
}
struct Node* addBeg(struct Node* head,int data){
    struct Node* ptr=createNode(data);
    ptr->data=data;
    ptr->link=NULL;

    ptr->link=head;
    head=ptr;

    return head;

}

void traverse(struct Node* head){
    printf("\nLinked List: ");
    while(head !=NULL){
        printf("%d ->",head->data);
        head=head->link;
    }
    printf("NULL");

}

int main(){
    int data;
    struct Node* head=createNode(data);
    head->data=78;
    head->link=NULL;

    struct Node* ptr=createNode(data);
    ptr->data=11;
    ptr->link=NULL;

    head->link=ptr;

    data = 7;

    head = addBeg(head,data);
    ptr=head;
    while(ptr != NULL){
        printf("%d",ptr->data);

        ptr=ptr->link;
    }

    traverse(head);




}