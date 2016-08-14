/*
 * shell_insert_sort.c
 *
 *  Created on: Aug 14, 2016
 *      Author: leo
 */
/*
 * shell_insert_sort.c
 *
 *  Created on: Aug 14, 2016
 *      Author: leo
 */
#include <stdio.h>
#include <stdlib.h>

void shell_insert_sort(int a[],int n,int div)
{
	int i = 0,j = 0,x = 0;
	for(i=div;i<n;++i)
	{
		if(a[i]<a[i-div])
		{
			j = i - div;
			x = a[i];
			a[i] = a[i-div];
			while(x<a[j]&&j>=0)
			{
				a[j+div] = a[j];
				j -= div;
			}
			a[j+div] = x;
		}
		print(a,n,i);
	}
}


void shell_sort(int a[],int n)
{
	int div = n/2;
	while(div>=1)
	{
		printf("div=%d \n",div);
		shell_insert_sort(a,n,div);
		div = div/2;
	}
}


int main()
{
	int a[] = {3,1,8,5,7,12,4,28,14,6};
	shell_sort(a,10);
	return 0;

}



