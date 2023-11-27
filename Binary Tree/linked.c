#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};
struct Node* createNode(){
    int input,data;
    printf("Do you want to add a Node?(0 for No & 1 for YES): ");
    scanf("%d",&input);
    if(!input){
        return NULL;
    }
    else{
        struct Node* newNode=malloc(sizeof(struct Node));
        printf("Enter the data: ");
        scanf("%d",&data);
        newNode->data=data;
        printf("Left Child of %d\n",newNode->data);
        newNode->left=createNode();
        printf("Right child of %d\n",newNode->data);
        newNode->right=createNode();
        return newNode;
    }   
}
int main(){
    struct Node* root=createNode();
    printf("%d ",root->data);
    printf("%d ",root->left->data);
    printf("%d ",root->right->data);
    return 0;
}