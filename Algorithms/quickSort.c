#include <stdio.h>

void swapnums(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int l, int h){
	int pivot = arr[l];
	int i = l;
	int j = h;
	while( i < j){
		while(arr[i] <= pivot){
			i++;
		}
		while(arr[i] > pivot){
			j--;
		}
		if(i < j){
			swapnums(&arr[i], &arr[j]);
		}
		swapnums(&arr[j], &arr[l]);
	}
	return j;
}

int quickSort(int arr[], int l, int h){
	if(l < h){
		int pivot = partition(arr, l, h);
		quickSort(arr, l, pivot-1);
		quickSort(arr, pivot+1, h);
	}
}

int main(){
	int n = 0;
	printf("Enter size for the array: ");
	scanf("%d", &n);

	int h = n - 1, l=0;
	int arr[n];

	printf("Enter elements for array: ");
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	quickSort(arr, l, h);

	printf("Sorted array is: \n");
	for(int i = 0; i<n; i++){
		printf("%d\t", arr[i]);
	}

return 0;
}
