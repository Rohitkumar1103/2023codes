#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node*left;
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

struct Node* insert(struct Node* root, int ikey){
    if(root==NULL){
        root=createNode(ikey);
    }
    else if(ikey<root->data){
        root->left= insert(root->left,ikey);
    }
    else if(ikey>root->data){
        root->right=insert(root->right,ikey);
    }
    else 
        printf("DUPLICATE KEY!");
        return root;
}

struct Node* search(struct Node* root,int skey){
    if(root==NULL){
        printf("Element Not Found\n");
    }
    else if(skey<root->data){
        return search(root->left,skey);
    }
    else if(skey>root->data){
        return search(root->right,skey);
    }
    else 
        return root;
}
void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    else 
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int countLeafNode(struct Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    return countLeafNode(root->left) + countLeafNode(root->right);
}

int height(struct Node* root){
    if(root==NULL){
        return 0;
    }
    int leftheight=height(root->left);
    int rightheight=height(root->right);

    if(leftheight>rightheight){
        return leftheight +1;
    }
    else {
        return rightheight+1;
    }
}
struct Node* findMinNode(struct Node* root){
    while(root -> left != NULL){
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int dkey){
    if(root==NULL){
        printf("Element Not Found!");
    }
    else if(dkey<root->data){
        root->left=deleteNode(root->left,dkey);
    }
    else if(dkey>root->data){
        root->right=deleteNode(root->right,dkey);
    }
    else{
        if(root->left!=NULL && root->right!=NULL){
            struct Node* temp=findMinNode(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
        else {
            struct Node* temp=root;
            if(root->left==NULL){
                root=root->right;
            }
            else if(root->right==NULL){
                root=root->left;
            }
            free(temp);
        }
    }
    return root;
}

int main(){
    struct Node* root=NULL;
    int choice,data;
    while(1){
        printf("\nMENU\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Count Leaf Node\n");
        printf("6. Height of the Tree\n");
        printf("7. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
    
    switch(choice){
        case 1:
        printf("Enter the data: ");
        scanf("%d",&data);
        root=insert(root,data);
        break;

        case 2:
        printf("Enter the data to Delete: ");
        scanf("%d",&data);
        root=deleteNode(root,data);
        break;

        case 3:
        printf("Enter the data to search: ");
        scanf("%d",&data);
        struct Node* ptr=search(root,data);
        if(ptr==NULL)
            printf("Key Not found.\n");
        else
            printf("Key %d found.\n",ptr->data);
        break;
        
        case 4:
        printf("Inorder Traversal\n");
        inorder(root);
        printf("\n");
        break;

        case 5: 
        int leafNodeCount = countLeafNode(root);
        printf("Number of leaf nodes: %d\n", leafNodeCount);
        break;

        case 6:
        int treeHeight=height(root);
        printf("Height of the tree: %d",treeHeight);
        break;

        case 7:
        exit(0);

        default:
            printf("INVALID CHOICE!!");
        break;
    }
    }
    return 0;
}