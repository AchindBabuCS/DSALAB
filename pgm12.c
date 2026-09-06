#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void display()
{
    struct node *temp = head;

    printf("\nLinked List: ");

    if (head == NULL)
    {
        printf("Empty");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
    printf("\n");
}

void insertFront()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

void insertEnd()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

void insertBetween()
{
    struct node *newnode, *temp;
    int pos, i;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newnode);
    }
    else
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deleteFront()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteEnd()
{
    struct node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        free(temp);
    }
}

void deleteBetween()
{
    struct node *temp, *prev;
    int pos, i;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    temp = head;

    for (i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
    }
    else
    {
        prev->next = temp->next;
        free(temp);
    }
}

int main()
{
    int choice;
    int x = 0;

    printf("\n===== SINGLY LINKED LIST =====\n");
    printf("1. Insert at Front\n");
    printf("2. Insert Between\n");
    printf("3. Insert at End\n");
    printf("4. Delete from Front\n");
    printf("5. Delete from Between\n");
    printf("6. Delete from End\n");
    printf("7. Display\n");
    printf("8. Exit\n");
    
    while (x < 1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertFront();
                display();
                break;

            case 2:
                insertBetween();
                display();
                break;

            case 3:
                insertEnd();
                display();
                break;

            case 4:
                deleteFront();
                display();
                break;

            case 5:
                deleteBetween();
                display();
                break;

            case 6:
                deleteEnd();
                display();
                break;

            case 7:
                display();
                break;

            case 8:
                x = 1;
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
