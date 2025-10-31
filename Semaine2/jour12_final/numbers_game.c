#include <stdio.h>
void comb(int n,int target,int start,int sum,int *arr){if(n==0){if(sum==target){for(int i=0;i<3;i++)printf("%d",arr[i]);printf("\n");}return;}for(int i=start;i<=9;i++){arr[3-n]=i;comb(n-1,target,i,sum+i,arr);}}
int main(){int arr[3];comb(3,6,0,0,arr);return 0;}