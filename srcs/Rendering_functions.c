/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calion <calion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:19:54 by calion            #+#    #+#             */
/*   Updated: 2022/12/16 22:04:29 by calion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	render_rect(t_gamedata *gamedata, int x, int y)
{
	int	i;
	int	j;

	i = y;
	while (i < y + 16)
	{
		j = x;
		while (j < x + 16)
		{
			my_mlx_pixel_put(gamedata, j++, i, 0x00000000);
		}
		++i;
	}
	i = y+1;
	while (i < y + 15)
	{
		j = x + 1;
		while (j < x + 15)
		{
			my_mlx_pixel_put(gamedata, j++, i, 0x00FF0000);
		}
		++i;
	}
	return (0);
}


void DrawCube(t_gamedata *gamedata, float beginX, float beginY, float endX, float endY, int color, int cubewith)
{
	int	j;
	int	i;

	i = 0;
/*player rectangle*/
	while (i < endY + cubewith)
	{
		j = 0;
		while (j < endX)
		{
			mlx_pixel_put(gamedata->mlx, gamedata->mlx_3dwindow, beginX + j, beginY + i, color);
			j++;
		}
		++i;
	}
}



void	render_floor(t_gamedata *gamedata, int color)
{
	int	i;
	int	j;

	i = gamedata->window_height / 2;
	while (i < gamedata->window_height)
	{
		j = 0;
		while (j < gamedata->window_width)
		{
			my_mlx_pixel_put3d(gamedata, j++, i, color);
		}
		++i;
	}
}

void	render_ceiling(t_gamedata *gamedata, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < gamedata->window_height / 2)
	{
		j = 0;
		while (j < gamedata->window_width)
		{
			my_mlx_pixel_put3d(gamedata, j++, i, color);
		}
		++i;
	}
}

void	render_bg_map(t_gamedata *gamedata, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < gamedata->mapY * 16)
	{
		j = 0;
		while (j < gamedata->mapX * 16)
		{
			my_mlx_pixel_put(gamedata, j++, i, color);
		}
		++i;
	}
}


void	pixelPlayer(t_gamedata *gamedata)
{    
    int	rectheigt = 5;
    int rectwidth = 5; // odd numbers so arm is in middle;
    int j;
    int i = 0;
    /*player rectangle*/
    while (i < rectheigt)
    {
        j = 0;
        while (j < rectwidth)
        {
            my_mlx_pixel_put(gamedata, gamedata->player_x + j, gamedata->player_y + i, 0xFFFFFF00);
            j++;
        }
        ++i;
    }
    /*player arm*/
    //printf("im rayangle: %f \n",gamedata->player_angle);
    //printf("im player_y = %d \n",(int)(gamedata->player_y / 16) * 16);
    drawRays(gamedata);
    drawLine(gamedata,gamedata->player_x + 2,gamedata->player_y + 2,
    (gamedata->player_x + 2) - 2 * -gamedata->player_dx, (gamedata->player_y + 2) - 2 * gamedata->player_dy,0x00FF0000);
    // mlx_pixel_put(gamedata->mlx, gamedata->mlx_window, gamedata->player_x + j, gamedata->player_y + i, 0x00FF0000);

}