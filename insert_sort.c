/*
 * insert_sort.c
 *
 *  Created on: Aug 14, 2016
 *      Author: leo
 */


#include <stdio.h>
#include <stdlib.h>

void print(int a[], int n ,int i){
	int j = 0;
	printf("i = %d \n",i);

	for(; j<n; ++j){

		printf("\t a[%d]=%d",j,a[j]);

	}

	printf("\n");

}




void insert_sort(int a[],int n)
{
	int i = 0,j = 0,x = 0;
	for(i=1;i<n;++i)
	{
		if(a[i-1]>a[i])
		{
			x = a[i];
			j = i - 1;
			a[i] = a[i-1];
			while(x<a[j] && j>=0)
			{
				a[j+1] = a[j];

				--j;		 //元素后移s

			}
			a[j+1] = x;		 //插入到正确位置
		}
		print(a,n,i);			//打印每趟排序的结果
	}
}
int main()
{
	int a[] = {3,1,8,5,7,12,4,28,14,6};

	insert_sort(a,10);
	return 0;
}
