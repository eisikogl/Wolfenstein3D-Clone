#include "../includes/cube3d.h"

void	my_mlx_pixel_put(t_gamedata *gamedata, int x, int y, int color)
{
	char	*dst;

	dst = gamedata->addr + (y * gamedata->line_length + x * (gamedata->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_pixel_put3d(t_gamedata *gamedata, int x, int y, int color)
{
	char	*dst3d;

	dst3d = gamedata->addr3d + (y * gamedata->line_length3d + x * (gamedata->bits_per_pixel3d / 8));
	*(unsigned int*)dst3d = color;
}