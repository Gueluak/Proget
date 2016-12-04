#include "filler.h"

char	*read_line(int fd)
{
	static char	*buff;
	char		*str;
	char		*tmp;
	int			i;

	str = NULL;
	if (!buff)
		buff = ft_memalloc(BUFF);
	//else
//		str = ft_memndup(buff, ft_strlen(buff));
	while (read(fd, buff, BUFF))
	{
		//print("\nlapin\n");
		i = 0;
		while (buff[i] != '\n' && buff[i])
			i++;
		tmp = ft_strncat(str, buff, i);
		if (str)
			free(str);
		str = tmp;
		if (buff[i] == '\n')
		{
			//tmp = ft_memndup(buff, i);
			//free(buff);
			//buff = tmp;
			return(str);
		}
	}
	return (str);
}