/*
 * select_sort.c
 *
 *  Created on: Aug 14, 2016
 *      Author: leo
 */

/*
 * select_sort.c
 *
 *  Created on: Aug 14, 2016
 *      Author: leo
 */


#include <stdio.h>
#include <stdlib.h>


int find_minkey(int a[],int n,int i)
{
	int j = 0,k = i;
	for(j=i+1;j<n;++j)
	{
		if(a[j]<a[k])
			k = j;
	}
	return k;
}

void select_sort(int a[],int n)
{
	int i = 0,min_key;
	for(i=0;i<n;++i)
	{
		min_key = find_minkey(a,n,i);
		if(a[i]>a[min_key])
		{
			int temp = a[min_key];
			a[min_key] = a[i];
			a[i] = temp;
		}
		print(a,n,i);
	}
}

//wrong
void SelectSort(int r[],int n) {
	int i ,j , min ,max, tmp;
	for (i=1 ;i <= n/2;i++) {
		// 做不超过n/2趟选择排序
		min = i; max = i ; //分别记录最大和最小关键字记录位置
		for (j= i+1; j<= n-i; j++) {
			if (r[j] > r[max]) {
				max = j ; continue ;
			}
			if (r[j]< r[min]) {
				min = j ;
			}
	  }
	  //该交换操作还可分情况讨论以提高效率
	  tmp = r[i-1]; r[i-1] = r[min]; r[min] = tmp;
	  tmp = r[n-i]; r[n-i] = r[max]; r[max] = tmp;
	  print(r,n,i);
	}
}

int main()
{
	int i = 0;
	int a[] = {3,1,8,5,7,12,4,28,14,6};
	//select_sort(a,10);
	SelectSort(a,10);
	for(;i<10;++i)
	{
		printf("a[%d]=%d \n",i,a[i]);
	}
	return 0;
}

