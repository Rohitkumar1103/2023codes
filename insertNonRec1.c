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

struct Node* insert_nonRec(struct Node* root,int ikey){
    struct Node* ptr,* par, *temp;
    ptr=root;
    par=NULL;
    while(ptr!=NULL){
        par=ptr;
        if(ikey<ptr->data)
            ptr=ptr->left;
        else if(ikey>ptr->data)
            ptr=ptr->right;
        else {
            printf("Duplicate Key!\n");
            return root;
        }
    }
    temp=createNode(ikey);
    if(par==NULL)
        root=temp;
    else if(ikey<par->data)
        par->left=temp;
    else
        par->right=temp;
return root;
}
void inorderTrav(struct Node* root){
    if(root==NULL){
        return ;
    }
    inorderTrav(root->left);
    printf("%d ",root->data);
    inorderTrav(root->right);
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

    root=insert_nonRec(root,30);
    inorderTrav(root);
    

return 0;
}