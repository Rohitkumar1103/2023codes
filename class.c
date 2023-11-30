#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct node *insertNode(struct node *root, int data) {
  if (root == NULL) {
    return createNode(data);
  } else if (data < root->data) {
    root->left = insertNode(root->left, data);
  } else {
    root->right = insertNode(root->right, data);
  }
  return root;
}

void preorderTraversal(struct node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void postorderTraversal(struct node *root) {
  if (root == NULL) {
    return;
  }
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ", root->data);
}

void inorderTraversal(struct node *root) {
  if (root == NULL) {
    return;
  }
  inorderTraversal(root->left);
  printf("%d ", root->data);
  inorderTraversal(root->right);
}

struct node *searchElement(struct node *root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (data < root->data) {
    return searchElement(root->left, data);
  } else if (data > root->data) {
    return searchElement(root->right, data);
  } else {
    return root;
  }
}
int main()
{
    struct BSTNode *root = NULL;

    int n;
    int element;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int data;
    printf("Enter elements of BST: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insertNode(&root, data);
    }

    printf("\nBST Created\n");

    printf("\nMAIN MENU\n");
    printf("1. Preorder\n");
    printf("2. Postorder\n");
    printf("3. Inorder\n");
    printf("4. Search\n");
    printf("5. Exit\n");

    int option;
    printf("\nEnter option: ");
    scanf("%d", &option);

    while (option != 5)
    {
        switch (option)
        {
        case 1:
            printf("\nPreorder: ");
            preorderTraversal(root);
            break;
        case 2:
            printf("\nPostorder: ");
            postorderTraversal(root);
            break;
        case 3:
            printf("\nInorder: ");
            inorderTraversal(root);
            break;
        case 4:
            
            printf("\nEnter element to search: ");
            scanf("%d", &element);
            if (searchElement(root, element))
            {
                printf("\nElement found\n");
            }
            else
            {
                printf("\nElement not found\n");
            }
            break;
        default:
            printf("\nInvalid option\n");
            break;
        }

        printf("\nEnter option: ");
        scanf("%d", &option);
    }

    return 0;
}