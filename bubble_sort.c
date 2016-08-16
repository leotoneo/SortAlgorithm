/*
 * bubble_sort.c
 *
 *  Created on: Aug 16, 2016
 *      Author: leo
 */


#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int a[],int length)
{
	int i = 0,j = 0;
	for(i=0;i<length-1;++i)
	{
		for(j=0;j<length-1-i;++j)
		{
			if(a[j]>a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}

		}
		print(a,10,i);
	}

}

//1．设置一标志性变量pos,用于记录每趟排序中最后一次进行交换的位置。由于pos位置之后的记录均已交换到位,故在进行下一趟排序时只要扫描到pos位置即可。
void bubble_1 ( int r[], int n) {
	int i= n-1,j = 0;  //初始时,最后位置保持不变
	while ( i> 0) {
		int pos= 0; //每趟开始时,无记录交换
		for (j=0; j< i; j++)
			if (r[j]> r[j+1]) {
				pos= j; //记录交换的位置
				int tmp = r[j]; r[j]=r[j+1];r[j+1]=tmp;
			}
		i= pos; //为下一趟排序作准备
	 }
}

//2．传统冒泡排序中每一趟排序操作只能找到一个最大值或最小值,我们考虑利用在每趟排序中进行正向和反向两遍冒泡的方法一次可以得到两个最终值(最大者和最小者) , 从而使排序趟数几乎减少了一半。
void bubble_2 ( int r[], int n){
	int low = 0;
	int high= n -1; //设置变量的初始值
	int tmp,j;
	while (low < high) {
		for (j= low; j< high; ++j) //正向冒泡,找到最大者
			if (r[j]> r[j+1]) {
				tmp = r[j]; r[j]=r[j+1];r[j+1]=tmp;
			}
		--high;					//修改high值, 前移一位
		for ( j=high; j>low; --j) //反向冒泡,找到最小者
			if (r[j]<r[j-1]) {
				tmp = r[j]; r[j]=r[j-1];r[j-1]=tmp;
			}
		++low;					//修改low值,后移一位
	}
}

int main()
{
	int i = 0;
	int a[] = {3,1,8,5,7,12,4,28,14,6};
	int len = sizeof(a)/sizeof(int);
	//bubble_sort(a,10);
	bubble_1(a,len);
	//bubble_2(a,10);
	for(i=0;i<len;++i)
		printf("a[%d]=%d ",i,a[i]);
	return 0;
}
