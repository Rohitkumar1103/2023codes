#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * link;
};

struct Node *createNode(int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->link=NULL;
    return newNode;

};

struct Node *insertNode(struct Node *head, int data){
    struct Node* newNode=createNode(data);
    newNode->link=head;
    return newNode;

    
}

int main(){
    struct node* head= NULL;
    int data,choice;

    while (1)
    {

	printf("\nMENU\n");
    printf("1. Insert Node At Beginning.\n");
    printf("Enter the choice:");
    scanf("%d",&choice);


        
        switch (choice)
        {
        case 1:
            printf("enter the number to be inserted: ");
            scanf("%d",&data);
            head=insertNode(head,data);
            break;

            case 2:
            exit(0);
        
        default:
        printf("invalid choice");
        }

        return 0;

}

