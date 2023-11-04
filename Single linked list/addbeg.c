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

struct Node* insertAtFirst(struct Node* head, int data){
    struct Node* newNode=createNode(data);
    newNode->link=head;

    return newNode;
}

int main(){
        int data;
        struct Node* head;

        printf("Enter the data: ");
        scanf("%d",&data);
        createNode(data);
        insertAtFirst(head,data);

        return data;  
    
}













