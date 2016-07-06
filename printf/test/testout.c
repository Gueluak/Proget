#include "printf.h"
#include <locale.h>

int			main(int ac, char **av)
{
	int	i = 0;
	while (i < 10000000)
	{
		++i;
		printf("%d\n",i);
	}
	return (0);
}