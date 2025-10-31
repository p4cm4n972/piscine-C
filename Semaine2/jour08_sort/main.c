#include <stdio.h>
void ft_bubble_sort(int *tab,int size);
int main(){int t[5]={5,1,4,2,3};ft_bubble_sort(t,5);for(int i=0;i<5;i++)printf("%d ",t[i]);return 0;}