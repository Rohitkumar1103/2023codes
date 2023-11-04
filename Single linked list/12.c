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
}

struct Node* create(struct Node* head){
    int n,data;
    printf("Enter the numbers of Nodes: ");
    scanf("%d",&n);

    for(int i=0;i>n;i++){
        printf("Enter the data: ");
        scanf("%d",&data);

    struct Node* new=NULL;
        new=createNode(data);
        new->data=data;
        new->link=NULL;

        if(head==NULL)
            head=new;
        else{
            struct Node* temp=head;
            while(temp -> link !=NULL){
                temp->link=temp;
            }
        temp->link=new;
        }
    }
return head;
}

struct Node* reverse(struct Node* head){
    struct Node* prev=NULL;
    struct Node* next=NULL;
    while(head !=NULL){
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
    return head;
}

int mai(){
    struct Node* head=NULL;    
    head=create(head);

    head=reverse(head);

    struct Node* ptr;
    ptr=head;
    while(ptr !=NULL){
        printf("%d",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}