#include <stdio.h>
#include "binarySearch.c"

int searchInfinite(int arr[], int key)
{
    int low = 0, high = 1;
    while (arr[high] < key)
    {
        low = high;
        high = 2 * high;
    }
    return binarySearch(arr, low, high, key);
}

int main()
{

    int n, result, key;

    printf("Enter the size for the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter the elemets for the array: ");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nThe list of numbers is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    printf("\n\nEnter the key to search within the array: ");
    scanf("%d", &key);

    result = searchInfinite(arr, key);

    if (result == -1)
        printf("\n-> Element not in the list!");

    else
        printf("\n-> Element found at index: %d", result);

    return 0;
}