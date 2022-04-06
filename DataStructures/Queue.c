// Write a program to implement following operations of Queue using Array-
// a.	Check for Overflow and Underflow
// b.	Insert Operation in Queue
// c.	Delete Operation in Queue
// d.	Print the elements of Queue.

#include <stdio.h>
#include <stdlib.h>
int max, queue[10], choice, front = -1, rear = -1;
void enqueue(int);
void dequeue(void);
void display(void);
int main()
{
    // clrscr();
    printf("\n-> Enter the size of Queue[MAX=10]:");
    scanf("%d", &max);
    printf("\n\n-> Implementing Queue using Array\n");
    printf("\n-> NOTE:Index of array starts from zero\n");
    printf("\n\t--------------------------------");
    printf("\n\t 1.Insertion\n\t 2.Deletion\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\n\n-> Enter your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int n;
            printf("\n-> Enter a value to be pushed:");
            scanf("%d", &n);
            enqueue(n);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("\n-> END Program \n");
            printf("\n\t-******** BYE *******\n");
            break;
        }
        default:
        {
            printf("\n\t-> Please Enter a Valid Choice mentioned above");
        }
        }
    } while (choice != 4);
    return 0;
}
void enqueue(int n)
{

    // checking if Queue is overflowed or not....?
    if (rear == max - 1)
    {
        printf("\n\t-> Queue is Overflowed");
    }
    if (rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    queue[rear] = n;
}
void dequeue()
{
    int value;
    if (front == rear == -1 || front > rear)
    {
        // checking if Queue is empty or not?
        printf("\n\t-> Queue is underflowed");
    }
    else
    {
        value = queue[front];
        front = front + 1;
        printf("\n\t-> The removed elements is %d", value);
    }
}
void display()
{
    if (front == rear == -1) // checking if not underflowed.?
    {
        // if underflowed!
        printf("\n-> The Queue is empty");
    }
    else
    {
        printf("\n-> The elements in Queue are:  \n");
        printf("\n\t--------");
        int counter = 1, pos;
        for (int i = front; i <= rear; i++)
        {
            printf("\n\t %d. %d", counter, queue[i]);
            counter++;
            pos = queue[rear];
        }
        printf("\n\n-> Lastly entered : %d by you", pos);
        printf("\n\n-> choose your next choice");
    }
}
