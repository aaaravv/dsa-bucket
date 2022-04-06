#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);

    if (key > arr[mid])
        return binarySearch(arr, mid + 1, high, key);
}

int biniterSearch(int arr[], int size, int key)
{
    int low = 0, high = arr[size - 1];

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        if (key > arr[mid])
            return low = mid + 1;
        if (key < arr[mid])
            return high = mid - 1;
    }
    return -1;
}

int main()
{

    int n, key, low, high, result, choice, more;

    printf("Enter the size for the array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    do
    {
        printf("\nThe list of number is: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d\t", arr[i]);
        }
        printf("\n\nEnter the key to search within above list: ");
        scanf("%d", &key);

        printf("\n\t1. For iterative approach.");
        printf("\n\t2. For recursive approach.");
        printf("\n\nSelect iterative or recursive approach from above: ");
        scanf("%d", &choice);

        low = arr[0];
        high = arr[n - 1];

        if (choice == 1)
        {
            result = biniterSearch(arr, n, key);
        }
        else
        {
            result = binarySearch(arr, low, high, key);
        }

        if (result == -1)
        {
            printf("\n-> Key not in the list");
        }
        else
        {
            printf("\n-> Element found at index: %d", result);
        }

        printf("\n\n-> Want to search more? enter 1 for yes or 0 for no: ");
        scanf("%d", &more);

    } while (more);

    return 0;
}