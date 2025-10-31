#include "libft.h"
#include <stdio.h>
int main(void){char str[]="PiscineC";char dest[50];ft_putstr("Hello EPITA!\n");printf("len=%d\n",ft_strlen(str));ft_strcpy(dest,str);printf("copied:%s\n",dest);return 0;}