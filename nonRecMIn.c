#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct Node* recSearch(struct Node* root,int skey){
    if(root==NULL)
        return NULL;
    else if(skey<root->data)
        return recSearch(root->left,skey);
    else if(skey>root->data)
        return recSearch(root->right,skey);
    else    
        return root;

}
struct Node* nonRecMin(struct Node* root){
    if(root!=NULL){
        while(root->left!=NULL)
            root=root->left;
    }
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

    struct Node* ptr=nonRecMin(root);
    if(ptr==NULL)
        printf("No Minimum Element.\n");
    else
    printf("Minimum Value is %d",ptr->data);



    return 0;
}