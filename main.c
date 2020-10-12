#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
	printf("文字列:%d",ft_printf("[%.*s]",-7,"hello"));
	printf("文字列:%d",printf("[%.*s]",-7,"hello"));
	return (0);
}
