#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct CircularLinkedList {
  struct Node *head;
};

void insertAtBeginning(struct CircularLinkedList *list, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = list->head;

  if (list->head == NULL) {
    list->head = newNode;
    newNode->next = newNode;
  } else {
    struct Node *temp = list->head;
    while (temp->next != list->head) {
      temp = temp->next;
    }
    temp->next = newNode;
    list->head = newNode;
  }
}

void printList(struct CircularLinkedList *list) {
  struct Node *temp = list->head;
  if (list->head == NULL) {
    printf("List is empty.\n");
    return;
  }

  while (temp->next != list->head) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("%d ", temp->data);
  printf("\n");
}

int main() {
  struct CircularLinkedList *list = (struct CircularLinkedList *)malloc(sizeof(struct CircularLinkedList));
  list->head = NULL;

  int choice, data;


  while (1) {
      printf("Enter your choice:\n");
  printf("1. Insert at beginning\n");
  printf("2. Print list\n");
  printf("3. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the data to insert: ");
        scanf("%d", &data);
        insertAtBeginning(list, data);
        break;
      case 2:
        printList(list);
        break;
      case 3:
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}