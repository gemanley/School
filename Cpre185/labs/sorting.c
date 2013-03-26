#include <stdio.h>
#include <stdlib.h>

/*
 *	Given two pointers to  integers, swaps their values.
 */
void swap(int *, int *);

/*
 *	This method should implement a mergesort
 */
void sortmerge(int n, int arr[]);

/*
 *	This method should implement a quicksort
 */
void sortquick(int n, int arr[]);

/*
 *	Just calls the sorting method that you want to test.
 *	Edit this method by commenting out the sort you don't
 *	want to test. Obviously, without editing it, you will
 *	need to call only one to get a good test back.
 */
void sort(int n, int arr[])
{
	//sortmerge(n, arr);
	sortquick(n, arr);
}
/*
 *	Clearly an extraneous function, but should be a good
 *	example of using pointers in function calls.
 */
void printInt(int * x){
	printf("%d, ", *x);
}

/*
 * Displays the contents of an array
 */
void printArr(int n, int arr[])
{
	int i;
	printf("[ ");
	for(i = 0; i < n; i++){
		printInt(&arr[i]);
	}
	
	printf("\b\b]\n");
}


int main()
{
	int items;
	int i;
	int *arr;
	
	printf("Number of items in list: ");
	scanf("%d", &items);
	
	arr = (int *)malloc(sizeof(int) * items);
	
	for(i = 0; i < items; i++)
	{
		printf("item %d: ", i+1);
		scanf("%d", &arr[i]);
	}
	
	printf("Original:\n\t");
	printArr(items, arr);
	
	sort(items, arr);
	
	printf("Post-Sort:\n\t");
	printArr(items, arr);
	
	system("pause");
}

void sortquick(int n, int arr[])
{
	//write your quicksort implementation here.
}

void sortmerge(int n, int arr[])
{
	//write your mergesort implementation here.
}
