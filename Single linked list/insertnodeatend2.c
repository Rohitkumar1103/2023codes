#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->link=NULL;

}

struct Node* insertAtEnd(struct Node* head,int data){
    struct Node* newNode=createNode(data);
    if (head=NULL){

        return newNode;
    }

    struct Node* temp=head;
    while(temp->link !=NULL){
        temp=temp->link;
    }
    temp->link=newNode;
    
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
    printf("hello");
    struct Node* head;



    insertAtEnd(head,65);

    traverse(head);
    return 0;
}
