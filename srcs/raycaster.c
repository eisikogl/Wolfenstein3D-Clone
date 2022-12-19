/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calion <calion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:20:07 by calion            #+#    #+#             */
/*   Updated: 2022/12/16 22:50:50 by calion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

float	dist(float beginx, float beginy, float endx, float endy, float angle)
{
	float	deltax;
	float	deltay;

	deltax = endx - beginx;
	deltay = endy - beginy;
	return (sqrt((deltax * deltax) + (deltay * deltay)));
}

void	drawRays(t_gamedata *gamedata)
{
	int		r;
	int		map_x;
	int		map_y;
	int		map_pos;
	int		dof;
    float	ray_x;
	float	ray_y;
	float	ray_angle;
	float	x_offset;
	float	y_offset;
	float	distT;

	mlx_clear_window(gamedata->mlx, gamedata->mlx_3dwindow);
	float texture_y = 0;
    r = 0;
    ray_angle = gamedata->player_angle - Dgre * 30 ;
	if (ray_angle < 0)
	{
		ray_angle += 2 * PI;
	}
	if (ray_angle > 2 * PI)
	{
		ray_angle -= 2 * PI;
	}
    int raysize = 8192;
	while (r < raysize)
	{
        dof = 0;
		/*find shortest line*/
        float distHori = 1000000,horiX= gamedata->player_x,horiY = gamedata->player_y;
   		/*Horizontal Line check*/
        float aTan = tan(ray_angle);
		if (ray_angle < PI) // looking up quadrant 2
		{
			ray_y = ((int)(gamedata->player_y / 16) * 16) - 0.0001 ;
			ray_x = ((gamedata->player_y - ray_y) / aTan) + gamedata->player_x;
			y_offset = -16;
			x_offset = -(y_offset / aTan);
		}
		if (ray_angle > PI) //looking down quadrant 3
		{
			ray_y = ((int)(gamedata->player_y / 16) * 16) + 16;
			ray_x = ((gamedata->player_y - ray_y) / aTan) + gamedata->player_x;
			y_offset = 16;
			x_offset = -(y_offset / aTan);
		}
		if (ray_angle == 0 || ray_angle == PI )
		{
			ray_x = gamedata->player_x;
			ray_y = gamedata->player_y;
			dof = gamedata->mapY;
		}
		while (dof < gamedata->mapY)
		{
			/*find position in array*/
				map_x = ((int)(ray_x) / 16);
				map_y = ((int)(ray_y) / 16);
			if (map_x < gamedata->mapX && map_y < gamedata->mapY && map_x >= 0 && map_y >= 0 && gamedata->map_split[map_y][map_x] == '1')
			{
				horiX = ray_x;
				horiY = ray_y;
				distHori = dist(gamedata->player_x, gamedata->player_y, horiX, horiY, ray_angle);
				dof = gamedata->mapY;
			}
			else
			{
				ray_x += x_offset;
				ray_y += y_offset;
				dof += 1;
			}
		}
		/*Vertical Line check*/
        dof = 0;
		float distVerti= 1000000,vertiX= gamedata->player_x,vertiY = gamedata->player_y;
		float nTan = tan(ray_angle);
		if (ray_angle > P2 && ray_angle < P3) // looking left
		{
			ray_x = (((int)gamedata->player_x / 16) * 16) - 0.0001;
			ray_y = (gamedata->player_x - ray_x) * nTan + gamedata->player_y;
			x_offset = -16;
			y_offset = -x_offset * nTan;
		}
		if (ray_angle < P2 || ray_angle > P3) //looking right
		{
			ray_x = (((int)gamedata->player_x / 16) * 16)+16;
			ray_y = (gamedata->player_x - ray_x) * nTan + gamedata->player_y;
			x_offset = 16;
			y_offset = -x_offset * nTan;
		}
		if (ray_angle == 0 || ray_angle == PI)
		{
			ray_x = gamedata->player_x;
			ray_y = gamedata->player_y;
			dof = gamedata->mapX;
		}
		while (dof < gamedata->mapX)
		{
			/*find position in array*/
			map_x = (int)(ray_x) / 16;
			map_y = (int)(ray_y) / 16;
			if (map_x < gamedata->mapX && map_y < gamedata->mapY && map_x >= 0 && map_y >= 0 && gamedata->map_split[map_y][map_x] == '1')
			{
				vertiX = ray_x;
				vertiY = ray_y;
				distVerti = dist(gamedata->player_x, gamedata->player_y, vertiX, vertiY, ray_angle);
				dof = gamedata->mapX;
			}
			else 
			{
				ray_x += x_offset;
				ray_y += y_offset;
				dof += 1;
			}
		}
		int color;
		float shade = 1;
		if (distVerti < distHori)
		{
			ray_x = vertiX;
			ray_y = vertiY;
			distT = distVerti;
			shade = 0.5;
		}
		if (distHori < distVerti)
		{
			ray_x = horiX;
			ray_y = horiY;
			distT = distHori;
			shade = 1;
		}
		drawLine(gamedata,gamedata->player_x + 2,gamedata->player_y+2,
        ray_x ,ray_y,0x0000FF00);
	/*3d SCENE*/
	float ca = gamedata->player_angle - ray_angle;
	if (ca < 0)
	{
		ca += 2 * PI;
	}
	if (ca > 2 * PI)
	{
		ca -= 2 * PI;
	}
	distT = distT * cos(ca);
	int mapsize = gamedata->mapY * gamedata->mapY;
	float lineHeight = (16 * 512) / distT;
	float WallOffsetY = 256 - lineHeight/2;
	float WallOffsetX = 1024 / 2;
	float sceensize = 1024 / raysize;
	float texture_x;
	if (shade == 1)
	{
		/*south*/
		texture_x = (int)(ray_x * 2.0) % 64;
		/*north*/
		if (ray_angle > 180)
		{
			texture_x = 63 - texture_x;
		}
	}
	else
	{
		/*east*/
		texture_x = (int)(ray_y * 2.0) % 64;
		/*west*/
		if (ray_angle > 90 && ray_angle < 270)
		{
			texture_x = 63 - texture_x;
		}
	}
	drawLine3d_texture(gamedata, r/8, WallOffsetY, shade, texture_x, lineHeight);
	ray_angle += Dgre / 136 ;
	if (ray_angle < 0)
	{
		ray_angle += 2*PI;
	}
	if (ray_angle > 2*PI)
	{
		ray_angle -= 2*PI;
	}
	r++;
	}
}