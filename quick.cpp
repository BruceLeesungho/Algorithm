#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Quick_sort(int left, int right, int* arr);
int N;
int array_1[10000];


int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int n;
		scanf("%d", &n);
		array_1[i] = n;
	}
	Quick_sort(0, N - 1, array_1);


	for (int i = 0; i < N; i++)
	{
		printf("%d\n", array_1[i]);
	}
	return 0;
}


void Quick_sort(int l, int r, int* arr)
{
	if (l < 0 || r > N || l >= r) return;
	
	int mid = (l + r) / 2;
	int left = l;
	int right = r;

	while (left <= right)
	{
		int temp;
		while ((arr[left] < arr[mid]) && (left < N)) left++;
		while ((arr[right] > arr[mid]) && (right > 0)) right--;
		
		if(left <= right)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;  //swap

			left++;
			right--;
		}
	}
	//int new_pivot = (left + pivot) / 2;

	Quick_sort(l, right, arr);
	Quick_sort(left, r, arr);


}


