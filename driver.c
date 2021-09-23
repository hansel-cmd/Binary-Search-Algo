#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
int binarySearchNR(int arr[], int count, int x);
int binarySearchR(int arr[], int start, int end, int x);
int insert(int arr [], int size, int x);
int deleteElem(int arr[], int size, int x);
void display(int arr[], int size);

int main()
{
	int arr[] = {1,3,4,5,7,9,10,12,13,14};
	int count = 10;
	int start = 0, end = count - 1;
	
	display(arr, count);
	
	
	int lookFor = 14;
	printf("%d %s\n", lookFor, (binarySearchNR(arr, count, lookFor) != -1) ? "is found" : "is not found");
	
	int lookFor1 = 9;
	printf("%d %s \n", lookFor1, (binarySearchR(arr, start, end, lookFor1) != -1) ? "is found" : "is not found");
	
	
	int x = 6;
	count = insert(arr, count, x);
	display(arr, count);
	
	count = deleteElem(arr, count, 7);
	display(arr, count);
	
	
	return 0;
}


void display(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int insert(int arr[], int size, int x)
{
	int i;
	int start = 0;
	int end = size - 1;
	int middle;
	
	// size is the count
	if (size < MAX) {
		while (start <= end) {
			middle = (start + end) / 2;
			
			if (x <= arr[start]) {
				i = start;
				break;
			}
			
			if (x >= arr[end]) {
				i = end + 1;
				break;
			}
			
			// then x should be between middle - 1 and middle
			if (arr[middle] <= x) {
				if (arr[middle - 1] >= x) {
					i = middle - 1;
					break;
				}
				start = middle + 1;
				
			// then x should be between middle and middle + 1
			} else {
				if (arr[middle + 1] <= x) {
					i = middle;
					break;
				}
				end = middle - 1;
			}
		}
	
		// i would be the index of the floor so thats where we insert x
		memmove(arr+i+1, arr+i, sizeof(int) * (size - i));
		arr[i] = x;
		size++;
	}
	return size;
}

int deleteElem(int arr[], int size, int x)
{
	int i = -1;
	int middle;
	int start = 0;
	int end = size - 1;
	
	while (start <= end) {
		middle = (start + end) / 2;
		
		if (arr[middle] == x) {
			i = middle;
			break;
		}
		
		if (arr[middle] < x) {
			start = middle + 1;
		} else {
			end = middle - 1;
		}
	}
	
	if (i != -1) {
		memmove(arr+middle, arr+middle+1, sizeof(int) * (size - i - 1));
		size--;	
	}
	
	return size;
}


int binarySearchNR(int arr[], int count, int x)
{
	int start, end, middle;
	start = 0;
	end = count - 1;
	middle = (start + end) / 2;
	
	while (start <= end) {
		middle = (start + end) / 2;
		
		if (arr[middle] == x) {
			return middle;
		}
		
		if (arr[middle] < x) {
			start = middle + 1;			
		} else {
			end = middle - 1;
		}
	}
	return -1;
}

int binarySearchR(int arr[], int start, int end, int x)
{
	int middle = (start + middle) / 2;
	
	if (start > end) {
		return -1;
	}
	
	if (arr[middle] == x) {
		return middle;
	}
	
	if (arr[middle] < x)
		return binarySearchR(arr, middle + 1, end, x);
	else
		return binarySearchR(arr, start, middle - 1, x);
}
