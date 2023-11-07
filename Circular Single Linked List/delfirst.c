#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createfirstnode(int data){
    struct Node* temp=malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=temp;
    return temp;
}
struct Node* addatbeg(struct Node* tail,int data){
    struct Node* new;
    new=malloc(sizeof(struct Node));
    new->data=data;
    new->next=new;
    new->next=tail->next;
    tail->next=new;
    return tail;
}

struct Node* createNode(struct Node* tail){
    int n,data;
    printf("Enter the Numbers of Node: ");
    scanf("%d",&n);

    if(n==0){
        return tail;
    }
    printf("Enter the data 1: ");
    scanf("%d",&data);
    tail=createfirstnode(data);

    for(int i=1;i<n;i++){
        printf("Enter the data %d: ",i+1);
        scanf("%d",&data);
        tail=addatbeg(tail,data);
    }
    return tail;
}
void traverse(struct Node* tail){
    struct Node* ptr=tail->next;
    do{
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    while(ptr!=tail->next);
}
struct Node* delfirst(struct Node* tail){
    struct Node* temp;
    temp=tail->next;
    tail->next=temp->next;
    free(temp);
    temp=NULL;
    return tail;
}
int main(){
    struct Node* tail;
    int data;
    tail=createNode(tail);
    printf("Before deleting the: ");
    traverse(tail);

    tail=delfirst(tail);
    printf("\nAfter deleting the First Node: ");
    traverse(tail);


    return 0;
}