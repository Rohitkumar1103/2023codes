//NON RECURSIVE CODE OF INSERTING NODE BY TAKING DATA FROM USER.
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
    int choice,data;
    while(1){
    printf("\nMENU\n");
    printf("1. Insert\n");
    printf("2: Traverse\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        printf("Enter the element to Insert:\n");
        scanf("%d",&data);
        root=insert_nonRec(root,data);
        break;

        case 2:
        printf("Traversal:\n");
        inorderTrav(root);
        break;

        case 3:
        exit(0);

        break;
        default:
            printf("INVALID CHOICE");
        break;
    }
}
    

return 0;
}