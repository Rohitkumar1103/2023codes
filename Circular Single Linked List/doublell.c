#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};
struct Node* circularSingle(int data){
    struct Node* temp=malloc(sizeof(struct Node));
    temp->prev=temp;
    temp->data=data;
    temp->next=temp;
return temp;
}

int main(){
        struct Node* tail=NULL;
        int data=76;

        tail=circularSingle(data);
        printf("%d\n",tail->data);
        return 0;


}