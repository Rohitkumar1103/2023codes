#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new Node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a Node at the beginning of the list
struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to delete a Node from the beginning of the list
struct Node *deleteAtBeginning(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to insert a Node at the end of the linked list
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to traverse and print the linked list
void traverse(struct Node *head)
{
    printf("Linked List: ");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to search for a value in the linked list
int search(struct Node *head, int value)
{
    int position = 1;
    while (head != NULL)
    {
        if (head->data == value)
        {
            return position;
        }
        head = head->next;
        position++;
    }
    return -1; // Value not found
}

int main()
{
    struct Node *head = NULL;
    int choice, data, position;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert Node at Beginning\n");
        printf("2. Delete Node at Beginning\n");
        printf("3. Insert Node at Last\n");
        printf("4. Traverse Linked List\n");
        printf("5. Search a Value\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data for the new node: ");
            scanf("%d", &data);
            head = insertAtBeginning(head, data);
            break;
        case 2:
            head = deleteAtBeginning(head);
            break;

        case 3:
            printf("Enter data for the new node: ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
            break;

        case 4:
            traverse(head);
            break;
        case 5:
            printf("Enter the value to search: ");
            scanf("%d", &data);
            position = search(head, data);
            if (position != -1)
            {
                printf("Value found at position %d.\n", position);
            }
            else
            {
                printf("Value not found.\n");
            }
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}