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

struct Node* delFirst(struct Node* head){
    head=head->next;
    free(head->prev);
    head->prev=NULL;

}
    
int main(){

    struct Node* head=NULL;
    head=create(head);
    traverse(head);

    printf("After deleting the first Node:\n");
    head=delFirst(head);
    traverse(head);



    return 0;
}