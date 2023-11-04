#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data;
    struct Node *link;
};

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof (struct Node));
    newNode ->data=data;
    newNode ->link=NULL;
    return newNode; 
}
//Function to insert Node at the beginning of the list.
struct Node* insertAtBeginning(struct Node* head,int data)
{
    struct Node* newNode=createNode(data);
    newNode -> link = head;
    return newNode;
}
int main()
{
    struct Node* head=NULL;
    int choice,data;

    while(1){
    printf("\nMENU\n");
    printf("1. Insert Node At Beginning.\n");
    printf("Enter the choice:");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            printf("Enter data for the new node: ");
            scanf("%d",&data);
            head = insertAtBeginning(head,data);
        break;

        case 2:
            exit(0);
            
        
        default:
        printf("INVALID CHOICE..PLEASE TRY AGAIN");
    }
    }
return 0;
}