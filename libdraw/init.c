
#include "include/libdraw.h"

t_draw_env	draw_init(void)
{
	t_draw_env	d_env;

	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
	d_env.screen = SDL_SetVideoMode(2560, 1440, 8, SDL_HWSURFACE|SDL_ANYFORMAT);

	return (d_env);
}

int 	main(void)
{
	draw_init();
	return (0);
}