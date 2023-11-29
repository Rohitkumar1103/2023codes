#include<stdio.h>
#include<stdlib.h>
 
struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* createTree();

struct Node* createTree(){
    int input, data;
    printf("Do you want to add a Node? (0 for No and 1 for Yes): ");
    scanf("%d",&input);
    if(!input)
    return NULL;
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

int main(){
    struct Node* root=createTree();
    printf("%d ",root->data);
    printf("%d ",root->left->data);
    printf("%d ",root->right->data);
    return 0;
}