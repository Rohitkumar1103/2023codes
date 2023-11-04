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
    printf("Enter the element ");
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        printf("Enter the data: ");
        scanf("%d",&data);

    struct Node* new=NULL;
        new=createNode(data);
        new->data=data;
        new->link=NULL;

        if(head==NULL){
            head=new;
        }else{
        struct Node* temp=head;
        while(temp->link !=NULL){
            temp=temp->link;
        }
        temp->link=new;
    }  
}
return head;
}

void traverse(struct Node* head){
    if(head==NULL){
        printf("Linked List is empty.");
    }
    struct Node* ptr=head;
        printf("Linked list: ");
    while(ptr !=NULL){
        printf(" %d -> ",ptr->data);
        ptr=ptr->link;
    }

}

int main(){
    struct Node* head=NULL;
    struct Node* ptr=head;
    head=create(head);

    traverse(head);

    printf("NULL\n");   
    return 0;
}