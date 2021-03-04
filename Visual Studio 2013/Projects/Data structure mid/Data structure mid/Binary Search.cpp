//#include<stdio.h>
//
//int binarySearch(int array[], int size, int element);
//void main()
//{
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int size = 10;
//	int element;
//	puts("Input the element to search:");
//	scanf_s("%d", &element);
//	if (binarySearch(array, size, element))
//		puts("Found!!");
//	else
//		puts("Not found!!");
//}
//
//int binarySearch(int array[], int size, int element)
//{
//	int first = 0;
//	int last = size - 1;
//	while (true)
//	{
//		int middle = (first + last) / 2;
//
//		if (element == array[middle])
//		{
//			return 1;
//		}
//		else if (first >= last)
//		{
//			return 0;
//		}
//		else if (element < array[middle])
//		{
//			last = middle - 1;
//		}
//		else if (element > array[middle])
//		{
//			first = middle + 1;
//		}
//	}
//}