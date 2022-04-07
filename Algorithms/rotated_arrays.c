// Hint: Just take care of the middle element ie (compare the middle element either
// with the left or the rightmost element in array if middle ele < leftmost element
// then array is left rotated and vice versa. )

// Steps
// 1. First check whether the middle element is smaller than lefmost element or not.
// 2. Then check whether the key is the range ( 0 to middle -1 ).
// 3. If key not found in the respective half discard the entire half and repeat step 1-3

#include <stdio.h>

int b_Search(int arr[], int key, int size)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[low] < arr[mid])
        {
            if (key >= arr[low] && key < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (key > arr[mid] && key <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n, key, result;

    printf("Enter the size for the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter the number for the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nThe list of numbers is: ");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    printf("\n\n-> Enter the element you want to search for? ");
    scanf("%d", &key);

    result = b_Search(arr, key, n);

    if (result == -1)
        printf("\n-> Element doesn't exists!");

    else
        printf("\n-> Element exists at index: %d", result);
    return 0;
}