//#include<stdio.h>
//void bubbleSort(int array[], int size);
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
//	bubbleSort(array, size);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", array[i]);
//	}
//	puts("");
//}
//
//void bubbleSort(int array[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size - 1 - i; j++)
//		{
//			if (array[j] > array[j + 1])
//			{
//				int temp = array[j];
//				array[j] = array[j + 1];
//				array[j + 1] = temp;
//			}
//		}
//	}
//}