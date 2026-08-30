#include <stdio.h>

int queue[100];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == 99)
        printf("Queue is full\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = x;
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue is empty\n");
    else
        printf("Deleted: %d\n", queue[front++]);
}

void display() {
    int i;

    if (front == -1 || front > rear)
        printf("Queue is empty\n");
    else {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, x;

    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            enqueue(x);
        }
        else if (choice == 2)
            dequeue();
        else if (choice == 3)
            display();
        else
            break;
    }

    return 0;
}
