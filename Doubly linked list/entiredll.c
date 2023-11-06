#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* create(struct Node* head){
    int n,data;
    struct Node* new=NULL;
    printf("Enter the Numbers of Nodes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter the data: ");
        scanf("%d",&data);
        new=malloc(sizeof(struct Node));
        new->prev=NULL;
        new->data=data;
        new->next=NULL;

        if(head==NULL){
            head=new;
        }else{
            struct Node* temp=head;
            while(temp->next !=NULL){
                temp=temp->next;
            }
            temp->next=new;
        }

    }
    return head;

}
void print(struct Node *head){
    printf("The linked list is as follows: ");
    if(head == NULL){
        printf("Linked List is Empty.");
    }
    struct Node *ptr = head;
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct Node* head=NULL;
    head=create(head);

    print(head);
    printf("NULL");

    return 0;
}

