#include <stdio.h>
#include <string.h>
void ft_sort_words(char **tab,int size){int i,j;char *tmp;for(i=0;i<size-1;i++){for(j=i+1;j<size;j++){if(strcmp(tab[i],tab[j])>0){tmp=tab[i];tab[i]=tab[j];tab[j]=tmp;}}}}
int main(int ac,char **av){if(ac>1){ft_sort_words(av+1,ac-1);for(int i=1;i<ac;i++)printf("%s ",av[i]);}}