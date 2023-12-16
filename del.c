#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

void print_data(struct Node* head){
        if(head == NULL)
            printf("Linked list is empty.");
        struct Node* ptr=NULL;
        ptr = head;
        while(ptr != NULL){
            printf(" %d ->",ptr->data);
            ptr=ptr->link;
        }  
}
struct Node* del(struct Node* head){
if(head==NULL)
    printf("\nLinked list is empty. ");
else{
    struct Node* temp=head;
    head=head->link;
    free(temp);
    temp=NULL;
}
return head;
}
int main(){
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    head->data=45;
    head->link=NULL;
 
    struct Node* current=(struct Node*)malloc(sizeof(struct Node));
    current->data=11;
    current->link=NULL;
    head->link=current;

    current=(struct Node*)malloc(sizeof(struct Node));
    current->data=7;
    current->link=NULL;
    head->link->link=current;
 
    print_data(head);
    printf("NULL\n");
   head= del(head);

    current=head;
    while(current!=NULL){
        printf("%d->",current->data);
        current=current->link;
            }
            printf("NULL");

    return 0;
}