//#include<stdio.h>
//void selectionSort(int array[], int size);
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
//	selectionSort(array, size);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", array[i]);
//	}
//	puts("");
//}
//
//void selectionSort(int array[], int size)
//{
//	for (int i = 0; i < size - 1; i++)
//	{
//		int iMin = i;
//		for (int j = i + 1; j < size; j++)
//	{
//			if (array[j] < array[iMin])
//			{
//			 iMin = j;
//			}
//	}
//		//swapping
//		int temp = array[i];
//		array[i] = array[iMin];
//		array[iMin] = temp;
//	}
//}