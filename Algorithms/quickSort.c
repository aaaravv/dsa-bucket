#include <stdio.h>

void swapnums(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int l, int h)
{
	int pivot = arr[l];
	int i = l;
	int j = h;
	while (i < j)
	{
		while (arr[i] <= pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i < j)
			swapnums(&arr[i], &arr[j]);
	}
	swapnums(&arr[j], &arr[l]);
	return pivot;
}

int quickSort(int arr[], int l, int h)
{
	if (l < h)
	{
		int pivot = partition(arr, l, h);
		quickSort(arr, l, pivot - 1);
		quickSort(arr, pivot + 1, h);
	}
}

int main()
{
	int n = 0;
	printf("\nEnter size for the array: ");
	scanf("%d", &n);

	int l = 0;
	int arr[n];

	printf("\nEnter elements for array: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("\nThe array elements before sorting are: ");
	for (int i = 0; i < n; i++)
		printf("%d\t", arr[i]);

	quickSort(arr, l, n - 1);

	printf("\n\nSorted array is: ");
	for (int i = 0; i < n; i++)
		printf("%d\t", arr[i]);

	return 0;
}
