/*
 * merge_sort.c
 *
 *  Created on: Aug 19, 2016
 *      Author: leo
 */


#include <stdio.h>
#include <stdlib.h>


void print_merge(int a[], int n){
	int j = 0;
    for(j= 0; j<n; j++){
        printf("\t a[%d]=%d",j,a[j]);
    }
    printf("\n");
}

//将r[i…m]和r[m +1 …n]归并到辅助数组rf[i…n]
void merge(int *r,int *rf, int i, int m, int n)
{
    int j,k;
    for(j=m+1,k=i; i<=m && j <=n ; ++k){
        if(r[j] < r[i]) rf[k] = r[j++];
        else rf[k] = r[i++];
    }
    while(i <= m)  rf[k++] = r[i++];
    while(j <= n)  rf[k++] = r[j++];
    print(rf,n+1);
}
//iteration
void merge_sort(int *r, int *rf, int lenght)
{
    int len = 1;
    //int *q = r ;
    int *tmp ;
    while(len < lenght) {
        int s = len; //每次划分的size
        len = 2 * s ;
        int i = 0;
        while(i+ len <lenght){                    //第一个序列：i-->i+s-1 length = (i+s-1-i+1)=s
            merge(r, rf,  i, i+ s-1, i+ len-1 ); // 第二个序列：i+s-->i+len-1(len=2*s) length = (i+2s-1-(i+s)+1)=s 对等长的两个子表合并
            i = i+ len;
        }
        if(i + s < lenght){                       //第一个序列：i-->i+s-1 length = (i+s-1-i+1)=s
            merge(r, rf,  i, i+ s -1, lenght -1);//第二个序列：i+s-->length-1 length = (length-1-(i+s)+1)=length-i-s对不等长的两个子表合并
        }
        tmp = r; r = rf; rf = tmp; //交换r,rf，以保证下一趟归并时，仍从r 归并到rf
    }

}



int main(){
    int a[10] = {3,1,5,7,2,4,9,6,10,8};
    int b[10];
    merge_sort(a,b,10);
    print_merge(a,10);


}
