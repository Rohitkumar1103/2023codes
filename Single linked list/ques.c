#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insert_at_last(struct Node **head, int data)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

void traverse(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Linked list: ");
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    insert_at_last(&head, 10);
    insert_at_last(&head, 20);
    insert_at_last(&head, 30);

    traverse(head);

    return 0;
}