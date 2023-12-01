#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};

int height(struct Node* root){
    if(root==NULL){
        return -1;
    }
    if(root->left==NULL && root->right==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    if(left>right)
        return left+1;
    else    
        return right+1;
}

struct Node* createNode(int data){
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

int isBalanaced(struct Node* root){
    int l=0,r=0,diff=0;
    int lh=0,rh=0;

    if(root==NULL)
        return 1;

    l=isBalanaced(root->left);
    r=isBalanaced(root->right);

    if(l && r){
        lh=isBalanaced(root->left);
        rh=isBalanaced(root->right);
        diff=abs((lh+1)-(rh+1));
        if(diff<=1)
        return 1;
    }
    return 0;    
}

int main(){
    struct Node* root=NULL;
    root=createNode(50);
    root->left=createNode(40);
    root->right=createNode(60);
    root->right->left=createNode(55);
    root->right->left->right=createNode(57);

    if(isBalanaced(root))
        printf("Tree is Height Balanced.");
    else    
        printf("Tree is not Height UnBalanced.");
    return 0;
}