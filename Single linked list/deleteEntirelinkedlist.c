#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *create(struct node *head){
    int n , data;
    struct node *new = NULL;
    printf("enter the number of nodes : ");
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++){

        printf("enter element : ");
        scanf("%d",&data);
        new = malloc(sizeof(struct node));
        new->data = data;
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
struct node* delList(struct node* head){
    struct node* temp=head;
    while(temp !=NULL){
        temp=temp->link;
        free(head);
        head=temp;
    }
    return head;
}
int main(){
    struct node *head = NULL;
    
    head = create(head);

    print(head);   
    printf("NULL\n");

    head=delList(head);

    if(head==NULL){
        printf("Linked List deleted succesfully.\n");
    }

    return 0;
}