#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* link;
}* top=NULL;
void push(data){
    struct Node* newNode=malloc(sizeof(newNode));
    if(newNode==NULL){
        printf("Stack Overflow");
        exit(1);
    }
    newNode->data=data;
    newNode->link=NULL;

    newNode->link=top;
    top=newNode;

}
int isEmpty(){
    if(top==NULL){
        return 1;
    }
    else 
        return 0;
}
int pop(){
    struct Node* temp;
    int val;
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    }
    temp=top;
    val=top->data;
    top=top->link;
    free(temp);
    temp=NULL;

    return val;
}
void print(){
    struct Node* temp=top;
    if(isEmpty()){
        printf("Stack underflow");
        exit(1);
    }
    while(temp){
        printf("%d-> ",temp->data);
        temp=temp->link;        
    }
    printf("\n");
}
int peek(){
    if(top==NULL){
        printf("Stack Underflow");
        exit(1);
    }
    return top->data;
}
int main(){
    int choice,data;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Peek\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter the data to push: ");
            scanf("%d",&data);
            push(data);
            break;

            case 2:
            data=pop();
            printf("Deleted Element is %d\n",data);
            break;

            case 3:
            printf("Stack element are: ");
            print();
            break;

            case 4:
            peek();
            printf("The topmpst Element is %d \n",peek());
            break;

            case 5:
            exit(1);
        }
    }
}