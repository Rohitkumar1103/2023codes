#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};


struct Node* createTree(){
    int input,data;
    printf("Do you want to add a Node?(0 for No and 1 for Yes): ");
    scanf("%d",&input);
    if(!input){
        return NULL;
    }
    else{
        struct Node* newNode=malloc(sizeof(struct Node));
        printf("Enter the data: ");
        scanf("%d",&data);
        newNode->data=data;
        printf("Left child of %d\n",newNode->data);
        newNode->left=createTree();
        printf("Right child of %d\n",newNode->data);
        newNode->right=createTree();  
        return newNode;  
    }
}

int isFullBinTree(struct Node* root){
    int left, right;
    if(root==NULL)
    return 1;
    if(root->left==NULL && root->right==NULL)
    return 1;
    if((root->left)&&(root->right)){
        left=isFullBinTree(root->left);
        right=isFullBinTree(root->right);
        return(left && right);
    }
    return 0;
}

int main(){
    struct Node* root=createTree();
    printf("%d ",root->data);
    printf("%d ",root->left->data);
    printf("%d ",root->right->data);

    if(isFullBinTree(root))
        printf("The given Binary tree is full binary tree.\n");
    else
        printf("The given BInary tree is not full binary tree.\n");

    return 0;
}