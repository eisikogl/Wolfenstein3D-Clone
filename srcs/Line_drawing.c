/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eisikogl <eisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:08:23 by eisikogl          #+#    #+#             */
/*   Updated: 2022/12/20 23:38:45 by eisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	image_get_pixel(t_gamedata *img, int x, int y)
{
	if (x < 0 || x > 64 || y < 0 || y > 64)
		return (0);
	return (*((int *)(img->north_addr + (y * img->north_line_length) \
	+ (x * 4))));
}

void	drawLine(t_gamedata *gamedata, int begx, int begy, int endx, int endy, int color)
{
	float	deltax;
	float	deltay;
	int		pixels;
	double	pixelx;
	double	pixely;

	deltax = endx - begx;
	deltay = endy - begy;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	pixelx = begx;
	pixely = begy;
	while (pixels)
	{
		if (pixelx < gamedata->mapX * 16 && \
		pixely < gamedata->mapY * 16 && pixelx > 0 && pixely > 0)
		{
			my_mlx_pixel_put(gamedata, pixelx, pixely, color);
			pixelx += deltax;
			pixely += deltay;
		}
		--pixels;
	}
}

void	drawLine3d(t_gamedata *gamedata, int begx, int begy, int endx, int endy, int color)
{
	float	deltax;
	float	deltay;
	int		pixels;
	double	pixelx;
	double	pixely;

	deltax = endx - begx;
	deltay = endy - begy;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	pixelx = begx;
	pixely = begy;
	while (pixels)
	{
		my_mlx_pixel_put3d(gamedata, pixelx, pixely, color);
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
}

void	drawLine3d_texture(t_gamedata *gamedata, float begx, float begy, float shade, float texture_x, float lineHeight)
{
	int		y;
	int		color;
	float	texture_step;
	float	texture_offset;
	float	WallOffsetY;
	float	texture_y;

	char r;
	char g;
	char b;

	y = 0;
	texture_step = 64.0 / (float)lineHeight;
	texture_offset = 0;
	if (lineHeight > 512)
	{
		texture_offset = (lineHeight - 512) / 2.0;
		lineHeight = 512;
	}
	WallOffsetY = 256 - lineHeight / 2;
	texture_y = texture_offset * texture_step;
	while (y < lineHeight)
	{
		my_mlx_pixel_put3d(gamedata, begx, y + WallOffsetY, image_get_pixel(gamedata,
				texture_x,texture_y));
		texture_y += texture_step;
		y++;
	}
}