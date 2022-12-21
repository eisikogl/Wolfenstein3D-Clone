/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rendering_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eisikogl <eisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:19:54 by calion            #+#    #+#             */
/*   Updated: 2022/12/21 03:11:04 by eisikogl         ###   ########.fr       */
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
	i = y + 1;
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

void DrawCube(t_gamedata *gamedata, float begix, float begiy, float endx, float endy, int color, int cubewith)
{
	int	j;
	int	i;

	i = 0;
	while (i < endy + cubewith)
	{
		j = 0;
		while (j < endx)
		{
			mlx_pixel_put(gamedata->mlx, gamedata->mlx_3dwindow, \
			begix + j, begiy + i, color);
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
	int	rectheigt;
	int	rectwidth;
	int	j;
	int	i;

	rectheigt = 5;
	rectwidth = 5;
	i = 0;
	while (i < rectheigt)
	{
		j = 0;
		while (j < rectwidth)
		{
			my_mlx_pixel_put(gamedata, gamedata->player_x + j, \
			gamedata->player_y + i, 0xFFFFFF00);
			j++;
		}
		++i;
	}
	drawRays(gamedata);
	drawLine(gamedata, gamedata->player_x + 2, gamedata->player_y + 2, \
	(gamedata->player_x + 2) - 2 * (-gamedata->player_dx), \
	(gamedata->player_y + 2) - 2 * gamedata->player_dy, 0x00FF0000);
}