
#include "wolf.h"

  
typedef struct	s_img
{
	int				widht;
	int				height;
	char			*buffer;
	float			vertexes[8];
	struct s_image	*next;
};				t_img;

typedef struct	s_quadra
{
	int		oo_x;
	int		oo_y;
	int		ox_x;
	int		ox_y;
	int		yo_x;
	int		yo_y;
	int		yx_x;
	int		yx_y;
};				t_quadra;