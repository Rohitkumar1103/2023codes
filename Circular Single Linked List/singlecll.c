#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* circularSingle(int data){
    struct Node* temp=malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=temp;
return temp;
}

int main(){
        struct Node* head=NULL;
        int data=76;

        head=circularSingle(data);
        printf("%d\n",head->data);
        return 0;


}