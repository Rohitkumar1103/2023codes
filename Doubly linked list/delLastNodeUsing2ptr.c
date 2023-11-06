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

struct Node* delLast(struct Node* head){
    if(head==NULL)
        printf("Linked List is empty!");
    else if(head->link==NULL)
    {   free(head);
        head=NULL;
    }
    else
    {
        struct Node* temp=head;
        struct Node* temp2=head;
        while(temp->link !=NULL){
            temp2=temp;
            temp=temp->link;
        }
        temp2->link=NULL;
        free(temp);
        temp=NULL;
    }
return head;
}

int main(){
    struct Node* head=NULL;

    head=create(head);
    traverse(head);
    printf("NULL\n");

    head=delLast(head);
    traverse(head);
    printf("NULL");

return 0;
}