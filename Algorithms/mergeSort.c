#include <stdio.h>

int merge(int arr[], int mid, int l, int r, int size)
{
	int i = l;
	int j = mid + 1;
	int k = l;
	int b[size];

	while (i <= mid && j <= r)
	{
		if (arr[i] < arr[j])
		{
			b[k] = arr[k];
			i++;
		}
		else
		{
			b[k] = arr[j];
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		while (j <= r)
		{
			b[k++] = arr[j++];
		}
	}
	else
	{
		while (i <= mid)
		{
			b[k++] = arr[i++];
		}
	}

	for (k = l; k <= r; k++)
	{
		arr[k] = b[k];
	}
}

int mergeSort(int arr[], int l, int r, int size)
{
	if (l < r) // for atleast two elements in the array
	{
		int mid = (l + r) / 2;
		mergeSort(arr, l, mid, size);
		mergeSort(arr, mid + 1, r, size);
		merge(arr, mid, l, r, size);
	}
}

int main()
{
	int n = 6, arr[n];
	int l = 0;
	
	printf("Enter size for the array: ");
	scanf("%d", &n);
	
	int r = n - 1;
	
	printf("\nEnter elements for array: ");
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	mergeSort(arr, l, r, n);

	printf("\nSorted array is: ");
	for(int i = 0; i<n; i++){
		printf("%d\t", arr[i]);
	}
	return 0;
}
