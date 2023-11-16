#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* link;
    int data;
} *top=NULL;

void push(data){
    struct Node* newNode;
        newNode=malloc(sizeof(newNode));

        if(newNode==NULL){
            printf("Stack Overflow");
            exit(1);
        }
        newNode->data=data;
        newNode->link=NULL;
        
        newNode->link=top;
        top=newNode;    
}
 void print(){
    struct Node* temp;
    temp=top;

    while(temp){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
 }

int main(){
    int choice,data;
    while(1){
        printf("1. Push\n");
        printf("2. Print\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d",&data);
            push(data);
            break;

            case 2:
            print();
            break;

            case 3:
            exit(1);

            default:
            printf("Wrong Choice\n");
            break;
        }
    }
    return 0;
}