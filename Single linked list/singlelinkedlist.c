#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node*createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->link=NULL;
}
void traverse(struct Node *head)
{
    printf("Linked List: ");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->link;
    }
    printf("NULL\n");
}
int main(){
    int data;
    struct Node* head=createNode(data);
    head->data=65;
    head->link=NULL;

    struct Node* current=createNode(data);
    current->data=34;
    current->link=NULL;
    head->link=current;

    current=createNode(data);
    current->data=12;
    current->link=NULL;
    head->link->link=current;

    current=createNode(data);
    current->data=15;
    current->link=NULL;
    head->link->link->link=current;

    traverse(head);

    return 0;
}