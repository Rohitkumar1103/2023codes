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
struct Node* insertNode(struct Node* root,int ikey){
    if(root==NULL){
        root=createNode(ikey);
    }
    else if(ikey<root->data){
        root->left=insertNode(root->left,ikey);
    }
    else if(ikey>root->data){
        root->right=insertNode(root->right,ikey);
    }
    else 
        printf("DUPLICATE KEY!\n");
    return root;
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
int main(){
    struct Node* root=NULL;
    int data,n;
    printf("Enter the numbe of nodes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter the data: ");
        scanf("%d",&data);
        root=insertNode(root,data);
    }

    struct Node* ptr=recSearch(root,89);
    if(ptr==NULL)
        printf("Key Not found.\n");
    else
        printf("Key %d found.\n",ptr->data);

    return 0;
}