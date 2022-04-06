// Menu Driven Program which performs:-
// 1.searching of an element in an array.
// 2.insertion of an element in an array.
// 3.Deletion of an element in an array.
// 4.Reverse of an array.
// 5.Number of Duplicate Values in array.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define s 20
int arr[s], size, num, choice, pos, found = 0;
void srch(int);
void insert(int, int);
void del(int);
void rev(void);
void duplicate(void);
int main()
{

    // Taking input from user for the size of array
    printf("->Enter the Size of the array MAX[SIZE=20]: ");
    scanf("%d", &size);

    // Taking array values from user
    if (size > 0 && size <= s)
    {
        for (int i = 0; i < size; i++)
        {
            printf("\n->Enter the Array value for arr[%d]:", i);
            scanf("%d", &arr[i]);
        }
    }
    // Displaying menu for users to perform operations
    do
    {
        printf("\n\n");
        printf("\n\t1.Search of an element of your choice");
        printf("\n\t2.Insertion of an element of your choice");
        printf("\n\t3.Deletion an element of your choice");
        printf("\n\t4.Reverse of the array");
        printf("\n\t5.Number of duplicate values in the array");
        printf("\n\t6.Fed up doing operations..?,End it up!!\n");
        printf("\n\n->Enter your Choice from the menu Above:-");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("\n\n->Enter the element which U want to search: ");
            scanf("%d", &num);
            srch(num);
            break;
        }
        case 2:
        {
            printf("\n\n->Enter the element which U want to insert: ");
            scanf("%d", &num);
            printf("\n->Enter the positon at which u want to insert the number ");
            scanf("%d", &pos);
            insert(num, pos);
            break;
        }
        case 3:
        {
            printf("\n\n->Enter the position of the Number: ");
            scanf("%d", &pos);
            del(pos);
            break;
        }
        case 4:
        {
            rev();
            break;
        }
        case 5:
        {
            duplicate();
            break;
        }
        case 6:
        {
            printf("\n \t\t------ See yaa! ------");
            exit(1);
        }
        default:
        {
            printf("\n\n->Your array is ...... : ");
            for (int i = 0; i < size; i++)
            {
                printf("\n->value for arr[%d] is: ", i);
            }
            break;
        }
        }

    } while (choice != 6);
    printf("\n");
    return 0;
}

void insert(int num, int pos)
{
    // Checking if position is in the range of array or not
    if (pos >= 0 && pos <= s)
    {
        int j;
        // here this loop will run till size of array is greater than pos of element entered
        for (j = size; j > pos; j--)
        {
            // here rest of elements will get unaffected only one which interfers at that position will get it's position changed with newly inserted element
            arr[j] = arr[j - 1];
        }
        // changing element
        arr[j] = num;
    }

    else
    {
        printf("\n->Wrong position is selected\n");
        exit(1);
    }
    printf("\n->Array after insertion is : ");
    // here used <=size as one element is inserted so size is inreased
    for (int i = 0; i <= size; i++)
    {
        printf("\t%d", arr[i]);
    }
}

void rev(void)
{
    printf("->The Reverse of the array is: ");
    // printing reverse of array while starting index from the end
    for (int k = size - 1; k >= 0; k--)
    {
        printf("\t%d", arr[k]);
    }
}
void srch(int num)
{
    int place;
    for (int a = 0; a < size; a++)
    {
        // checking condiction
        if (arr[a] == num)
        {
            // if number found than changing the value of flag variable for point of refrence
            found = 1;
            place = a;
        }
    }
    // if element entered by user matched one in array then displaying the pos
    if (found == 1)
    {
        printf("\nFound at %d position", place);
    }
    else
    {
        printf("->Not Found try another number\n");
    }
}

void del(int pos)
{
    // checking array upper and lower bounds
    if (pos >= 0 && pos < size)
    {
        // after deleting the elements we need to shif the elemets to the left side of the array
        for (int i = pos; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
    else
    {
        printf("->Wrong position selected\n");
        exit(1);
    }

    printf("->Array after deletion is : ");
    // since on element is deleted so i"<size-1"
    for (int i = 0; i <= size - 1; i++)
    {
        printf("\t%d", arr[i]);
    }
}

void duplicate(void)
{
    // Checking for duplicate values,if there removing them
    int dupli = 0;
    // first loop for need to be compared
    for (int i = 0; i < size; i++)
    {
        // second loop starting from +1 index for the element need to be compared with
        for (int j = i + 1; j < size; j++)
        {
            // condiction for checking for duplicates
            if (arr[i] == arr[j])
            {

                for (int k = j; k < size; k++)
                {
                    // here if duplicates found then shifting elements to left of the array
                    arr[k] = arr[k + 1];
                    // counting duplicates
                }
                size--;
                found = 1;
                dupli += 1;
            }
        }
    }
    if (found == 1)
    {
        printf("\n->Array contains Duplicate Values\n");
    }
    else
    {
        printf("\n->Array doesn't contains duplicate values\n");
        exit(1);
    }
    printf("\n->Array After removal of Duplicate Values is: ");
    for (int i = 0; i < size; i++)
    {
        printf("\t%d", arr[i]);
    }
    printf("\n->Number of duplicates found were: %d \n", dupli);
}
