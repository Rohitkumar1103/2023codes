#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};
struct Node* createNode(int data){
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->left=NULL;
    newNode->data=data;
    newNode->right=NULL;
    return newNode;
}
struct Node* recMax(struct Node* root){
    if(root==NULL)
        return NULL;
    else if(root->right==NULL)
        return root;
    else 
        return recMax(root->right);
}
int main(){
    struct Node* root=NULL;
    root=createNode(67);
    root->left=createNode(34);
    root->right=createNode(80);
    root->left->left=createNode(10);
    root->left->right=createNode(55);
    root->left->right->left=createNode(45);
    root->left->right->right=createNode(60);
    root->right->right=createNode(83);
    root->right->left=createNode(78);

    struct Node* ptr=recMax(root);
    if(ptr==NULL)
        printf("No Maximum Element.\n");
    else 
        printf("Maximum Element is %d.\n",ptr->data);
return 0;
}