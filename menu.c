#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
} Node;

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node *root, int data) {
    if(root == NULL) {
        root = createNode(data);
    } else if(data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}
//root->right->left

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

void searchNode(struct Node *root, int data) {
    if(root == NULL) {
        printf("Element Not Found\n");
    } else if(data < root->data) {
        searchNode(root->left, data);
    } else if(data > root->data) {
        searchNode(root->right, data);
    } else {
        printf("Element Found\n");
    }
}

void inorderTraversal(struct Node *root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int choice, data;

    while(1) {
        printf("1. Insert\n2. Delete\n3. Search\n4. Traversal\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
            break;

            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
            break;
            
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &data);
                searchNode(root, data);
            break;
            
            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
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