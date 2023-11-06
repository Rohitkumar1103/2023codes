#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node*  createNode(int data){
    struct Node* newNode=(struct Node* )malloc(sizeof(struct Node));
    newNode->prev=NULL;
    newNode->data=data;
    newNode->next=NULL;

    return newNode;
}

struct Node* create(struct Node* head){
    int n,data;
    printf("Enter the number of Nodes: ");
    scanf("%d",&n);

    struct Node* new=NULL;

    for(int i=0 ; i<n ; i++){
        printf("Enter the data: ");
        scanf("%d",&data);
        new=createNode(data);        
        new->prev=NULL;
        new->data=data;
        new->next=NULL;
        if(head==NULL){
            head=new;
        }
        else{
            struct Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=new;
        }
    }
    return head;
}
void traverse(struct Node* head)
{
    printf("Linked List is as follows: ");
    if(head==NULL){
        printf("NULL");
    }
    struct Node* ptr=head;

    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}

struct Node* delLast(struct Node* head){
    struct Node* temp=head;
    struct Node* temp2;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    temp=NULL;
    return head;
}

int main(){

    struct Node* head=NULL;
    head=create(head);
    traverse(head);

    head=delLast(head);
    printf("After deleting the Last Node:\n");
    traverse(head);

    return 0;
}