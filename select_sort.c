/*
 * select_sort.c
 *
 *  Created on: Aug 14, 2016
 *      Author: leo
 */


#include <stdio.h>
#include <stdlib.h>


int main()
{
	printf("select_sort \n");
	return 0;
}

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

	}
}
