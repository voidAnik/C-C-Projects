//
//#include<stdio.h>
//
//void quickSort(int A[], int start, int end);
//int partition(int A[], int start, int end);
//void main()
//{
//	int array[100];
//	int size;
//	printf("How many numbers: ");
//	scanf_s("%d", &size);
//	puts("Enter unsorted numbers:");
//	for (int i = 0; i < size; i++)
//	{
//		scanf_s("%d", &array[i]);
//	}
//	quickSort(array, 0, size - 1);
//	puts("\n\nAfter sorted:");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", array[i]);
//	}
//	puts("");
//}
//
//void quickSort(int A[], int start, int end)
//{
//	if (start >= end)
//		return;
//
//	int pIndex = partition(A, start, end);
//	quickSort(A, start, pIndex - 1);
//	quickSort(A, pIndex + 1, end);
//
//}
//+
//int partition(int A[], int start, int end)
//{
//	int pivot = A[end];
//	int pIndex = start;
//
//	for (int i = start; i < end; i++)
//	{
//		if (A[i] <= pivot)
//		{
//			int temp = A[i];
//			A[i] = A[pIndex];
//			A[pIndex++] = temp;
//		}
//	}
//	int temp = A[pIndex];
//	A[pIndex] = A[end];
//	A[end] = temp;
//
//	return pIndex;
//}
