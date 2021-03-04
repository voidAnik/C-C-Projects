//
//#include<stdio.h>
//
//void mergeSort(int A[], int size); 
//void merge(int A[],+ int L[], int nL, int R[], int nR);
//
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
//	mergeSort(array, size);
//	puts("\n\nAfter sorted:");
//	for (int i = 0; i < size;i++)
//	{
//		printf("%d ", array[i]);
//	}
//	puts("");
//}
//
//void mergeSort(int A[], int size)
//{
//	int left[100], right[100];
//	if (size < 2)
//	{
//		//puts("Already sorted!");
//		return;
//	}
//	int mid = size / 2;
//	puts("left:");
//	for (int i = 0; i < mid; i++)
//	{
//		left[i] = A[i];
//		printf("%d", left[i]);
//	}
//	puts("\nright:");
//	int j = 0;
//	for (int i = mid; i < size; i++)
//	{
//		right[j] = A[i];
//		printf("%d", right[j]);
//		j++;
//	}
//	puts("");
//	mergeSort(left,mid);
//	mergeSort(right,size-mid);
//	merge(A, left,mid, right,size-mid);
//}
//
//void merge(int A[],int L[],int nL, int R[],int nR)
//{
//	int i = 0, j = 0, k = 0;
//	while (i < nL && j < nR)
//	{
//		if (L[i] <= R[j])
//		{
//			A[k] = L[i];
//			i++;
//		}
//		else
//		{
//			A[k] = R[j];
//			j++;
//		}
//		k++;
//	}
//	while (i < nL)
//	{


//		A[k] = L[i];
//		i++;
//		k++;
//	}
//	while (j < nR)
//	{
//		A[k] = R[j];
//		j++;
//		k++;
//	}
//} 
