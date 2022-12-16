#include "../includes/cube3d.h"
#include "../assets/bricksx64.ppm"

void	drawLine(t_gamedata *gamedata, int beginX, int beginY,int endX,int endY,int color)
{
	float deltaX = endX - beginX;
	float deltaY = endY - beginY;

	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

	deltaX /= pixels; // 1
	deltaY /= pixels; // 0
	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
		if(pixelX < gamedata->mapX * 16 && pixelY < gamedata->mapY*16 && pixelX>0 && pixelY>0)
		{
			my_mlx_pixel_put(gamedata, pixelX, pixelY, color);
			pixelX += deltaX;
			pixelY += deltaY;
		}
		--pixels;
	}
}

void	drawLine3d(t_gamedata *gamedata, int beginX, int beginY,int endX,int endY,int color)
{
	float deltaX = endX - beginX;
	float deltaY = endY - beginY;

	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

    deltaX /= pixels; // 1
    deltaY /= pixels; // 0
    double pixelX = beginX;
    double pixelY = beginY;
    while (pixels)
    {
		
		my_mlx_pixel_put3d(gamedata, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
    }
}

void drawLine3d_texture(t_gamedata *gamedata, float beginX, float beginY,float shade,float texture_x,float lineHeight)
{
	int y=0;
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
		my_mlx_pixel_put3d(gamedata, beginX, y+WallOffsetY, color);
		texture_y += texture_step;
		y++;
    }
}