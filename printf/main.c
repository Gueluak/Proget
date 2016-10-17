#include "includes/printf.h"
#include <limits.h>
#include <stdio.h>

int main()
{
	char *str = "lapin";
	ft_printf("|%#.300m|\n\n\n|%#b|\n",str, 142);
}
