//insert at end

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *create(struct node *head){
    int n , element;
    struct node *new = NULL;
    printf("enter the number of nodes : ");
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++){

        printf("enter element : ");
        scanf("%d",&element);
        new = malloc(sizeof(struct node));
        new->data = element;
        new->link = NULL;

        if(head == NULL){
            head = new;
        }else{
            struct node *temp = head;
            while(temp->link != NULL){
                temp = temp->link;
            }
            temp->link = new;
        }
    }
    return head;
}


void insert(struct node *head){
    int n;
    printf("enter the element to insert at the end : ");
    scanf("%d",&n);

    struct node *new = malloc(sizeof(struct node));
    new->data = n;
    new->link = NULL;
    
    struct node *temp = head;
    while(temp->link != NULL){
        temp = temp->link;
    }
    temp->link = new;

}

void print(struct node *head){
    printf("The linked list is as follows: ");
    if(head == NULL){
        printf("Linked List is Empty.");
    }
    struct node *ptr = head;
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr = ptr->link;
    }
}


int main(){
    struct node *head = NULL;
    
    head = create(head);

    insert(head);

    print(head);   

}