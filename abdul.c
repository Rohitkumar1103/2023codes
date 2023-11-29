#include<stdio.h>
#include<stdlib.h>


typedef struct Node {struct Node *lchild;
    int data;
    struct Node *rchild;
} Node;

typedef
 
struct BST {Node *root;} BST;

void BST_Insert(BST *bst, int key) {
  Node *t = bst->root;
  Node *p, *r;

  // Root is empty
  if (bst->root == NULL) {
    p = (Node *)malloc(sizeof(Node));
    p->data = key;
    p->lchild = NULL;
    p->rchild = NULL;
    bst->root = p;
    return;
  }

  while (t != NULL) {
    r = t;
    if (key < t->data) {
      t = t->lchild;
    } else if (key > t->data) {
      t = t->rchild;
    } else {
      return; // Duplicate element
    }
  }

  // Now t points at NULL and r points at insert location
  p = (Node *)malloc(sizeof(Node));
  p->data = key;
  p->lchild = NULL;
  p->rchild = NULL;

  if (key < r->data) {
    r->lchild = p;
  } else {
    r->rchild = p;
  }
}

void BST_Inorder(Node *p) {
  if (p) {
    BST_Inorder(p->lchild);
    printf("%d, ", p->data);
    BST_Inorder(p->rchild);
  }
}

Node *BST_Search(BST *bst, int key) {
  Node *t = bst->root;
  while (t != NULL) {
    if (key == t->data) {
      return t;
    } else if (key < t->data) {
      t = t->lchild;
    } else {
      t = t->rchild;
    }
  }
  return NULL;
}

int main() {
  BST bst;
  bst.root = NULL;

  // Insert
  BST_Insert(&bst, 10);
  BST_Insert(&bst, 5);
  BST_Insert(&bst, 20);
  BST_Insert(&bst, 8);
  BST_Insert(&bst, 30);

  // Inorder traversal
  BST_Inorder(bst.root);
  printf("\n");

  // Search
  Node *temp = BST_Search(&bst, 2);
  if (temp != NULL) {
    printf("%d\n", temp->data);
  } else {
    printf("Element not found\n");
  }

  return 0;
}