#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createfirstnode(int data){
    struct Node* temp=malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=temp;
    return temp;
}
struct Node* addatbeg(struct Node* tail,int data){
    struct Node* new;
    new=malloc(sizeof(struct Node));
    new->data=data;
    new->next=new;
    new->next=tail->next;
    tail->next=new;
    return tail;
}

struct Node* createNode(struct Node* tail){
    int n,data;
    printf("Enter the Numbers of Node: ");
    scanf("%d",&n);

    if(n==0){
        return tail;
    }
    printf("Enter the data 1: ");
    scanf("%d",&data);
    tail=createfirstnode(data);

    for(int i=1;i<n;i++){
        printf("Enter the data %d: ",i+1);
        scanf("%d",&data);
        tail=addatbeg(tail,data);
    }
    return tail;
}
void traverse(struct Node* tail){
    struct Node* ptr=tail->next;
    do{
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    while(ptr!=tail->next);
}
int search(struct Node* tail,int element){
    int position=0;
    struct Node* temp;
    if(tail==NULL){
        return -2;
    }
    temp=tail->next;
    do{
        if(temp->data==element){
            return position;
        }
            temp=temp->next;
            position++;
    }while(temp!=tail->next);
    return -1;
}
int main(){
    struct Node* tail;
    int data,position;
    tail=createNode(tail);
    traverse(tail);

    int element;
    printf("\nEnter the data to search: ");
    scanf("%d",&element);
    search(tail,element);
    if(position==-1){
        printf("Element not found.\n");
    }
    else if(position==-2){
        printf("Linked List is Empty.");
    }
    else{
        printf("Element %d is at position %d.",element,position);
    }
    return 0;
}