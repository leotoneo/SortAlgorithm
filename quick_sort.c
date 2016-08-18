/*
 * quick_sort.c
 *
 *  Created on: Aug 18, 2016
 *      Author: leo
 */

#include <stdio.h>
#include <stdlib.h>

void my_swap(int *ex1,int *ex2)
{
	int temp = *ex1;
	*ex1 = *ex2;
	*ex2 = temp;
}

int partition(int a[],int low,int high)
{
	int key = a[low];
	while(low<high)
	{
		while(low<high && a[high]>=key) --high;
		my_swap(&a[low],&a[high]);
		while(low<high && a[low]<=key) ++low;
		my_swap(&a[low],&a[high]);

	}
	print_heap(a,10);  //call heap_sort.c of api
	return low;

}

void quick_sort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid = partition(a,low,high);
		quick_sort(a,low,mid-1);
		quick_sort(a,mid+1,high);
	}

}

//改进
void quick_improve(int a[],int low,int high,int k)
{
	if(high-low>k)
	{
		int mid = partition(a,low,high);
		quick_improve(a,low,mid-1,k);
		quick_improve(a,mid+1,high,k);
	}

}

void qsort_improve(int a[],int high,int k)
{
	int i = 0;
	quick_improve(a,0,high,k);
	for(i=1;i<=high;++i)
	{
		int temp = a[i];
		int j = i - 1;
		while(temp<a[j] && j>=0)
		{
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = temp;
	}

}

int main()
{
	int i = 0;
	int a[] = {3,1,8,5,7,12,4,28,14,6};
	int len = sizeof(a)/sizeof(int);
	//quick_sort(a,0,9);
	qsort_improve(a,9,4);
	for(i=0;i<len;++i)
		printf("a[%d]=%d ",i,a[i]);
	return 0;
}
