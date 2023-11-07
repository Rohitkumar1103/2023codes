#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* create(int data){
    struct Node* temp=malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=temp;
return temp;
}
struct Node* addAtBeg(struct Node* tail,int data){
    struct Node* new;
    new=malloc(sizeof(struct Node));
    new->data=data;
    new->next=tail->next;
    tail->next=new;
    return tail;
}
struct Node* createlist(struct Node* tail){
    int n,data;
        printf("Enter the Number of Nodes: ");
        scanf("%d",&n);

        if(n==0)
        return tail;
    printf("Enter the data 1: ");
    scanf("%d",&data);
    tail=create(data);

    for(int i=1;i<n;i++){
        printf("Enter the data %d: ",i+1);
        scanf("%d",&data);
        tail=addAtBeg(tail,data);
    }
    return tail;
}
void print(struct Node* tail){
    struct Node* ptr=tail->next;
    do{
        printf("%d-> ",ptr->data);
        ptr=ptr->next;
    }
    while(ptr!=tail->next);
}
int main(){
    struct Node* tail;
    tail=createlist(tail);
    print(tail);
    return 0;
}