//Case 2: Deleting the Node with two children.

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

void traverse(struct Node* root){
    if(root==NULL)
        return ;
    else 
    traverse(root->left);
    printf("%d ",root->data);
    traverse(root->right);
}
struct Node* case1(struct Node* root,struct Node* ptr, struct Node* par){
        if(par==NULL)
            root=NULL;
        else if(ptr==par->left)
            par->left=NULL;
        else 
            par->right=NULL;
        free(ptr);
    return root;        
}
struct Node* case2(struct Node* root,struct Node* ptr, struct Node* par){
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
struct Node* case3(struct Node* root,struct Node* ptr,struct Node* par){
    struct Node* successor,* parsuccessor; //Successor will point to the right child of the node to be deleted & Parsuccessor will point to the parent node of successor
    parsuccessor=ptr;
    successor=ptr->right;
    while(successor->left!=NULL){
        parsuccessor=successor;
        successor=successor->left;
    }
    ptr->data=successor->data;
    if(successor->left==NULL && successor->right==NULL)
        root=case1(root,successor,parsuccessor);
    else 
        root=case2(root,successor,parsuccessor);
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
        root=case3(root,ptr,par);
    return root;
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

    root=del_nonRec(root,34);

    printf("\nAfter Deletion: ");
    traverse(root);

return 0;
}