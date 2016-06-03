#include "libft.h"
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>


int		main(void)
{
	DIR		*d;
	int		statr;
	struct dirent *dir;
	struct stat buff;

	d = opendir("./");
	while((dir = readdir(d)))
		if (dir->d_name[0] != '.')
		{
			statr = stat(dir->d_name,  &buff);
			printf("\n %o ", buff.st_mode);
			write(1, dir->d_name, dir->d_namlen);
		}
	closedir(d);
	return (0);
}
