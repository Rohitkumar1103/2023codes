#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode=malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Error creating a new node\n");
        exit(0);   
    }
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct Node* insertNode(struct Node* root,int data){
    if(root==NULL){
    root=createNode(data);
    }
    else if(data < root->data){
        root->left=insertNode(root->left,data);
    }
    else{
        root->right=insertNode(root->right,data);
    }
    return root;
}
void preorder(struct Node* root){
    if(root == NULL){

        return ;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node* root){
    if(root == NULL){

        return ;
    }
    preorder(root->left);
    printf("%d ",root->data);
    preorder(root->right);
}
void postorder(struct Node* root){
    if(root == NULL){

        return ;
    }
    preorder(root->left);
    preorder(root->right);
    printf("%d ",root->data);
}
int main(){
    struct Node* root=NULL;
    int choice,data;
    while(1){
        printf("\n1. Insert.\n2. Inorder Traversal\n3. Preorder traversal\n4. Postorder traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the Element to insert: ");
                scanf("%d",&data);
                root=insertNode(root,data);
            break;

            case 2:
                printf("Inorder Traversal\n");
                inorder(root);
            break;

            case 3:
                printf("Preorder Traversal\n");
                preorder(root);
            break;

            case 4:
                printf("Postorder Traversal\n");
                postorder(root);
            break;

            case 5:
                exit(0);

            default:
            printf("Invalid choice!\n");
            break;
        }
    }
    return 0;
}