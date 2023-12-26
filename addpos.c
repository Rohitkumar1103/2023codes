#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};
struct Node* create(int data){
    struct Node*temp=malloc(sizeof(struct Node));
    temp->prev=temp;
    temp->data=data;
    temp->next=temp;
    return temp;
}
struct Node* addAtEnd(struct Node* tail,int data){
    struct Node* temp=tail->next;
    struct Node* new=create(data);
    new->next=temp;
    tail->next=new;
    new->prev=tail;
    temp->prev=new;
    tail=new;
    return tail;
}
struct Node* addAfterpos(struct Node* tail,int data,int pos){
    struct Node* new=create(data);
    if(tail==NULL){
        return new;
    }
    struct Node* temp=tail->next;
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    new->prev=temp;
    new->next-temp->next;
    temp->next->prev=new;
    temp->next=new;
    if (temp==tail){
        tail=tail->next;
    }
    return tail;
}
struct Node* createNode(struct Node* tail){
    int n,data;
    printf("Enter the number of Nodes: ");
    scanf("%d",&n);

    if(n==0){
        return tail;
    }
    printf("Enter the data 1: ");
    scanf("%d",&data);
    tail=create(data);

    for(int i=1;i<n;i++){
        printf("Enter the data %d: ",i+1);
        scanf("%d",&data);
        tail=addAtEnd(tail,data);
    }
    return tail;
}
void print(struct Node* tail){
    struct Node* ptr=tail->next;
    do{
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=tail->next);
}
int main(){
    struct Node* tail;
    tail=createNode(tail);
    print(tail);
    tail=addAfterpos(tail,56,4);
    print(tail);
    return 0;
}