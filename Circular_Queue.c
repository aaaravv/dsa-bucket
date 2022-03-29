// Aarav Mishra DSA (Data Strutures and Algorithms) LAB Practical
// Write a program to implement following operations of Circular Queue using Array-
// a.Check for Overflow and Underflow
// b.Insert Operation in Circular Queue
// c.Delete Operation in Circular Queue
// d.Print the elements of Circular Queue.#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
int cirqueue[20],max,choice,front=-1,rear=-1;
void enqueue(int);
void dequeue(void);
void display(void);
int main()
{
    //clrscr();
    printf("\n-> Enter the size of Circular_Queue[MAX=20]:");
    scanf("%d",&max);
    printf("\n\n-> Implementing Circular Queue using Array\n");
    printf("\n\t--------------------------------");
   
    do
    {
        printf("\n\t 1.Insertion (Enqueue)\n\t 2.Deletion (Dequeue)\n\t 3.DISPLAY\n\t 4.EXIT");
        printf("\n\n-> Enter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                int n;
                printf("\n\n-> Enter a value to be pushed into:");
                scanf("%d",&n);
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
                printf("\n\t-> END Program ");
                break;
            }
            default:
            {
                printf ("\n\t-> Please Enter a Valid Choice mentioned above");
            }
                 
        }
    }
    while(choice!=4);
    return 0;
}
void enqueue(int n)
{
    
    //checking if Circular Queue is overflowed or not....?
    if(front == 0 && rear == max-1)
    {
        printf("\n\t-> Circular Queue is Overflowed");
         
    }
    if (front == -1 && rear == -1)
    {
        front=rear=0;
    }
    else if (rear == max-1 && front!=0)
    {
        rear=0;
    }
    else
    {
        //assigning Number to cir_queue
        rear=rear+1;    
    }
    
    cirqueue[rear]=n;  
}
void dequeue()
{
    if(front == -1)
    {
        //checking if Cir_Queue is empty or not?
        printf("\n\t-> Queue is underflowed");
        return;
    }

    printf("\n\t-> The removed elements is %d",cirqueue[front]);

    if(front == rear)
    {
        front =rear = -1;
    }
    else
    {
        if(front == max-1)
            front=0;
        else
            front = front+1;
    }
}
void display()
{
    if(front==-1)//checking if not underflowed.?
    {
        //if underflowed!
        printf("\n-> The Circular_Queue is empty");  
    }
    else
    {
        int i,counter=1,front_pos=front,rear_pos=rear;
        printf("\n\n-> The elements in Circular_Queue are:  \n");
        printf("\n\t--------");
        
        if(front_pos <= rear_pos)
            while(front_pos <= rear_pos)
            {
                printf("\n\t %d. %d",counter,cirqueue[front_pos]);
                front_pos++;
                counter++;
            }   
        else
        {
            while(front_pos <= max-1)
            {
                printf("\n\t %d. %d",counter,cirqueue[front_pos]);
                front_pos++;
                counter++;
            }    
            front_pos = 0;    
            while(front_pos <= rear_pos)
            {
                printf("\n\t %d. %d",counter,cirqueue[front_pos]);
                front_pos++;
                counter++;
            }
        }
    }    
    printf("\n\n-> choose your next choice");
}