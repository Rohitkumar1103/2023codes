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
struct Node* findMinNode(struct Node *root) {
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}
struct Node* deleteNode(struct Node *root, int data) {
    if(root == NULL) {
        printf("Element Not Found\n");
    } else if(data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if(data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if(root->right && root->left) {
            struct Node *temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        } else {
            struct Node *temp = root;
            if(root->left == NULL)
                root = root->right;
            else if(root->right == NULL)
                root = root->left;
            free(temp);
        }
    }
    return root;
}
struct Node* searchNode(struct Node* root,int skey){
    if(root==NULL){
        printf("Element not found.!\n");
    }
    else if(skey<root->data){
        searchNode(root->left,skey);
    }
    else if(skey>root->data){
        searchNode(root->right,skey);
    }
    else 
        printf("Element Found\n");
}
void preOrder(struct Node* root){
    if(root==NULL)
        return;
    else 
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(struct Node* root){
    if(root==NULL)
        return ;
    else 
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
void postOrder(struct Node* root){
    if(root==NULL)
        return ;
    else 
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}
int main(){
    struct Node* root=NULL;
    int choice,data;
    while(1){
        printf("\nMENU\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. PreOrder Traversal\n");
        printf("5. InOrder Traversal\n");
        printf("6. PostOrder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
    
    switch(choice){
        case 1:
            printf("Enter the Data to Insert: ");
            scanf("%d",&data);
            root=insertNode(root,data);
        break;

        case 2:
            printf("Enter the Node to Delete: ");
            scanf("%d",&data);
            root=deleteNode(root,data);
        break;

        case 3: 
            printf("Enter the Elemnt to search: ");
            scanf("%d",&data);
            root=searchNode(root,data);
        break;

        case 4:
            printf("PreOrder Traversal: ");
            preOrder(root);
            printf("\n");
        break;

        case 5:
            printf("InOrder Traversal: ");
            inOrder(root);
            printf("\n");
        break;

        case 6:
            printf("PostOrder Traversal: ");
            postOrder(root);
            printf("\n");
        break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice");
        break;
    }
    }
}
