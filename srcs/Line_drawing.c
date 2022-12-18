/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calion <calion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:08:23 by eisikogl          #+#    #+#             */
/*   Updated: 2022/09/26 19:24:01 by calion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../assets/bricksx64.ppm" //fix for image input

void	drawLine(t_gamedata *gamedata, int begx, int begy,int endx,int endy,int color)
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
		if(pixelx < gamedata->mapX * 16 && pixely < gamedata->mapY*16 && pixelx>0 && pixely>0)
		{
			my_mlx_pixel_put(gamedata, pixelx, pixely, color);
			pixelx += deltax;
			pixely += deltay;
		}
		--pixels;
	}
}

void	drawLine3d(t_gamedata *gamedata, int begx, int begy,int endx,int endy,int color)
{
	float deltax = endx - begx;
	float deltay = endy - begy;

	int pixels = sqrt((deltax * deltax) + (deltay * deltay));

    deltax /= pixels; // 1
    deltay /= pixels; // 0
    double pixelx = begx;
    double pixely = begy;
    while (pixels)
    {
		
		my_mlx_pixel_put3d(gamedata, pixelx, pixely, color);
		pixelx += deltax;
		pixely += deltay;
		--pixels;
    }
}

void 	rawLine3d_texture(t_gamedata *gamedata, float begx, float begy,float shade,float texture_x,float lineHeight)
{
	int y = 0;
	int color;
	float texture_step = 64.0 / (float)lineHeight;
	float texture_offset = 0;
	if(lineHeight > 512)
	{
		texture_offset = (lineHeight - 512)/2.0;
		lineHeight = 512;
	}
	float WallOffsetY = 256-lineHeight/2;
	float texture_y = texture_offset * texture_step;
	
    while(y<lineHeight)
    {
		float r = brick_wall[(int)(texture_y)*64*3+(int)(texture_x)*3];
        float g = brick_wall[(int)(texture_y)*64*3+1+(int)(texture_x)*3+1];
        float b = brick_wall[(int)(texture_y)*64*3+2+(int)(texture_x)*3+2];
		//printf("%f\n",c);
        // if(c == 1.0)
		//     color = create_trgb(0,100*shade,255*shade,255*shade);
        // if(c == 0)
		//     color = create_trgb(0,0,0,0);
        color = create_trgb(0,r*shade,g*shade,b*shade);
		my_mlx_pixel_put3d(gamedata, begx, y+WallOffsetY, color);
		texture_y += texture_step;
		y++;
    }
}