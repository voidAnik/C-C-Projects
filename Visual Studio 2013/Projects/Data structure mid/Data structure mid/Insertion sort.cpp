//#include<stdio.h>
//void insertionSort(int array[], int size);
//void main()
//{
//	int array[100];
//	int size;
//	printf("How many numbers: ");
//	scanf_s("%d", &size);
//	puts("Input unsorted array:");
//	for (int i = 0; i < size; i++)
//	{
//		scanf_s("%d", &array[i]);
//	}
//	insertionSort(array, size);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", array[i]);
//	}
//	puts("");
//}
//
//void insertionSort(int array[], int size)
//{
//	for (int i = 1; i < size; i++)
//	{
//		int j = i - 1;
//		int temp = array[i];
//		while (j >= 0 && array[j] > temp)
//		{
//			array[j + 1] = array[j];
//			j--;
//		}
//		array[j + 1] = temp;
//	}
//}