//Case 2: Deleting the Node with only One child.

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

struct Node* case2(struct Node* root,struct Node* ptr,struct Node* par){
    struct Node* child;

    if(ptr->left!=NULL)
        child=ptr->left;
    else if(ptr->right!=NULL)
        child=ptr->right;
    
    if(par==NULL)
        root=child;
    else if(ptr==par->left)
        par->left=child;
    else    
        par->right=child;
    free(ptr);
return root;
}
struct Node* del_nonRec(struct Node* root,int dkey){
    struct Node* ptr,* par;
    ptr=root;
    par=NULL;

    while(ptr!=NULL){
        if(dkey==ptr->data)
            break;
        par=ptr;
        if(dkey<ptr->data)
            ptr=ptr->left;
        else
            ptr=ptr->right;
    }
    if(ptr->left!=NULL || ptr->right!=NULL)
        root=case2(root,ptr,par);
    return root;
}
void traverse(struct Node* root){
    if(root==NULL)
        return ;
    else 
    traverse(root->left);
    printf("%d ",root->data);
    traverse(root->right);
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
    root->right->left=createNode(70);

    printf("Before Deletion: ");
    traverse(root);

    root=del_nonRec(root,80);

    printf("\nAfter Deletion: ");
    traverse(root);

return 0;
}