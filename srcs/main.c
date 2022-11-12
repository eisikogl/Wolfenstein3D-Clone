/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calion <calion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:42:20 by eisikogl          #+#    #+#             */
/*   Updated: 2022/11/13 00:08:54 by calion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

// The map must be composed of only 6 possible characters: 0 for an empty space
// 1 for a wall, and N,S,E or W for the player’s start position and spawning
// orientation.

void drawLine(t_gamedata *gamedata, int beginX, int beginY,int endX,int endY,int color)
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
			mlx_pixel_put(gamedata->mlx, gamedata->mlx_window, pixelX, pixelY, color);
			pixelX += deltaX;
			pixelY += deltaY;
		}
		--pixels;
    }
}

void drawLine3d(t_gamedata *gamedata, int beginX, int beginY,int endX,int endY,int color)
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
		
		mlx_pixel_put(gamedata->mlx, gamedata->mlx_3dwindow, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
    }
}

float dist(float beginX,float beginY,float endX,float endY,float angle)
{
	float deltaX = endX - beginX;
    float deltaY = endY - beginY;
	return sqrt((deltaX  * deltaX) + (deltaY * deltaY));
}

void drawRays(t_gamedata *gamedata)
{
    int r,map_x,map_y,map_pos,dof;
    float ray_x,ray_y,ray_angle,x_offset,y_offset,distT;
    //ray_x = ray_y / tan(ray_angle);
    //ray_y = ((map_height * 16) - player_y) / 16;
    //S(int)playery
	mlx_clear_window(gamedata->mlx,gamedata->mlx_3dwindow);
    r = 0;
    ray_angle = gamedata->player_angle - Dgre*30;
	if(ray_angle <0)
	{
		ray_angle += 2*PI;
	}
	if(ray_angle > 2*PI)
	{
		ray_angle -= 2*PI;
	}
	while(r<240)
	{
        dof = 0;
		/*find shortest line*/
		float distHori = 1000000,horiX= gamedata->player_x,horiY = gamedata->player_y;
   		/*Horizontal Line check*/
        float aTan = tan(ray_angle);
        if(ray_angle < PI) // looking up quadrant 2
        {
           ray_y = ((int)(gamedata->player_y / 16) * 16) - 0.0001 ;
           ray_x = ((gamedata->player_y - ray_y) / aTan) + gamedata->player_x;
           y_offset = -16;
           x_offset = -(y_offset / aTan);
        }
        if(ray_angle > PI) //looking down quadrant 3
        {
            ray_y = ((int)(gamedata->player_y / 16) * 16) + 16;
            ray_x = ((gamedata->player_y - ray_y) / aTan) + gamedata->player_x;
            y_offset = 16;
            x_offset = -(y_offset / aTan);
        }

        if(ray_angle == 0 || ray_angle == PI)
        {
            ray_x = gamedata->player_x;
            ray_y = gamedata->player_y;
            dof = gamedata->mapY;
        }
        while(dof < gamedata->mapY)
        {
            /*find position in array*/
             map_x = ((int)(ray_x) / 16);
             map_y = ((int)(ray_y) / 16);
            //  printf("im map_X : %d \n",map_x);
            //  printf("im map_Y : %d \n",map_y);
            // map_pos = map_y * gamedata->mapX + map_x;

            if(map_x < gamedata->mapX && map_y < gamedata->mapY && map_x >= 0 && map_y >= 0 && gamedata->map_split[map_y][map_x] == '1')
            {
				horiX = ray_x;
				horiY = ray_y;
				distHori = dist(gamedata->player_x,gamedata->player_y,horiX,horiY,ray_angle);
                dof = gamedata->mapY;
            }
            else
            {
                ray_x += x_offset;
                ray_y += y_offset;
            	dof += 1;
            }
       }
	//    drawLine(gamedata,gamedata->player_x + 2,gamedata->player_y+2,
    //    ray_x ,ray_y,0x0000FF00);

    /*Vertical Line check*/
    
        dof = 0;
		float distVerti= 1000000,vertiX= gamedata->player_x,vertiY = gamedata->player_y;
        float nTan = tan(ray_angle);
        if(ray_angle > P2 && ray_angle < P3) // looking left
        {
            ray_x = (((int)gamedata->player_x/16) * 16) - 0.0001;
            ray_y = (gamedata->player_x - ray_x) * nTan + gamedata->player_y;
            x_offset = -16;
            y_offset = -x_offset * nTan;
        }
        if(ray_angle < P2 || ray_angle > P3) //looking right
        {
            ray_x = (((int)gamedata->player_x / 16) * 16)+16;
            ray_y = (gamedata->player_x - ray_x) * nTan + gamedata->player_y;
            x_offset = 16;
            y_offset = -x_offset * nTan;
        }
  		if(ray_angle == 0 || ray_angle == PI)
        {
            ray_x = gamedata->player_x;
            ray_y = gamedata->player_y;
            dof = gamedata->mapY;
        }

        while(dof < gamedata->mapY)
        {
            /*find position in array*/
             map_x = (int)(ray_x) / 16;
             map_y = (int)(ray_y) / 16;
            //  printf("im map_X : %d \n",map_x);
            //  printf("im map_Y : %d \n",map_y);
            // map_pos = map_y * gamedata->mapX + map_x;

            if(map_x < gamedata->mapX && map_y < gamedata->mapY && map_x >= 0 && map_y >= 0 && gamedata->map_split[map_y][map_x] == '1')
            {
				vertiX = ray_x;
				vertiY = ray_y;
				distVerti = dist(gamedata->player_x,gamedata->player_y,vertiX,vertiY,ray_angle);
				dof = gamedata->mapY;
            }
            else 
            {
                ray_x += x_offset;
                ray_y += y_offset;
            	dof += 1;
            }
       }
		if(distVerti < distHori)
		{
			ray_x = vertiX;
			ray_y = vertiY;
			distT = distVerti; 
		}
		if(distHori < distVerti)
		{
			ray_x = horiX;
			ray_y = horiY;
			distT = distHori;
		}
        drawLine(gamedata,gamedata->player_x + 2,gamedata->player_y+2,
        ray_x ,ray_y,0x0000FF00);

	/*3d SCENE*/
	float ca = gamedata->player_angle - ray_angle;
	if(ca < 0)
	{
		ray_angle += 2*PI;
	}
	if(ray_angle<2*PI)
	{
		ray_angle-=2*PI;
	}
	distT = distT*cos(ca);
	int mapsize = gamedata->mapX * gamedata->mapY;
	float WallHeight = (64 * 320) / distT;
	if(WallHeight > 320)
	{
		WallHeight = 320;
	}
	float WallOffset = 160-WallHeight/2;
	
	drawLine3d(gamedata,r+530,WallOffset,r+530,WallHeight+WallOffset,0x00FF0000);
	
	ray_angle += Dgre/4;
	if(ray_angle < 0)
	{
		ray_angle += 2*PI;
	}
	if(ray_angle > 2*PI)
	{
		ray_angle -= 2*PI;
	}
	r++;
	}
}


void pixelPlayer(t_gamedata *gamedata)
{    
    int rectheigt = 5;
    int rectwidth = 5; // odd numbers so arm is in middle;
    int j;
    int i = 0;
    /*player rectangle*/
    while (i < rectheigt)
	{
		j = 0;
		while (j < rectwidth)
        {
			mlx_pixel_put(gamedata->mlx, gamedata->mlx_window, gamedata->player_x + j, gamedata->player_y + i, 0xFFFFFF00);
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

// void pixelPlayer(t_gamedata *gamedata)
// {    
  
// 	mlx_pixel_put(gamedata->mlx, gamedata->mlx_window, gamedata->player_x, gamedata->player_y, 0x00FF0000);
 

// }

void init(t_gamedata *gamedata)
{
    //char	*path_player;
   // char	*path_wall;
    int x = 16;
    int y = 16;

	//path_wall = "./assets/wall.xpm";
	//path_player = "./assets/player.xpm";

    gamedata->img_wall = mlx_xpm_file_to_image(gamedata->mlx, "./assets/wall.xpm", &x, &y);
   // gamedata->img_player = mlx_xpm_file_to_image(gamedata->mlx, path_player, &x, &y);
}

// void drawPlayer(t_gamedata *gamedata)
// {
//     mlx_put_image_to_window(gamedata->mlx, gamedata->mlx_window, gamedata->img_player,
//     gamedata->player_x, gamedata->player_y);
// }

void drawWall(t_gamedata *gamedata,int i,int j)
{
    mlx_put_image_to_window(gamedata->mlx, gamedata->mlx_window, gamedata->img_wall,
    i, j );
}

void drawMap(t_gamedata *call_map)
{
    int i;
    int j;

    int x;
    int y = 0;
    
    i = 0;
    while(call_map->map_split[i] != NULL)
    {
        j = 0;
        x = 0;
        while(call_map->map_split[i][j] != '\n' || '\0')
        {
            if(call_map->map_split[i][j] == '1')
            {
                drawWall(call_map,x,y);
            }
            if(call_map->map_split[i][j] == 'N')
            {
                call_map->player_x = x;
                call_map->player_y = y;
                call_map->player_angle = PI / 2;
                call_map->player_dx = cos(call_map->player_angle) * 5;
			    call_map->player_dy = sin(call_map->player_angle) * 5;
                pixelPlayer(call_map);
            }

            x += 16;
            j++;
        }
        y += 16;
        i++;
    }
}

void drawMap2(t_gamedata *call_map)
{
    int i;
    int j;

    int x;
    int y = 0;
    
    i = 0;
    //drawWall(call_map,x,y);
    while(call_map->map_split[i] != NULL)
    {
        j = 0;
        x = 0;
        while(call_map->map_split[i][j] != '\n' || '\0')
        {
            if(call_map->map_split[i][j] == '1')
            {
                drawWall(call_map,x,y);
                x += 16;
            }
            else
            {
                x += 16;
            }

            j++;
        }
        y += 16;
        i++;
    }
     pixelPlayer(call_map);
}

int main(int argc,char **argv)
{
   // t_gamedata  *call_map;
    t_gamedata  *gamedata;

    gamedata = malloc(sizeof(t_gamedata));
    if(argc != 2)
        printf("add map \n");
    gamedata->mlx = mlx_init();
    gamedata->map_path = argv[1];
    read_map(gamedata);
    gamedata->map_split = ft_split(gamedata->map,'\n');
    gamedata->mapX = get_line_len(gamedata);
    gamedata->mapY = get_height(gamedata);
    gamedata->mlx_window = mlx_new_window(gamedata->mlx,16*  gamedata->mapX, 16 * gamedata->mapY,"Hello World");
	gamedata->mlx_3dwindow = mlx_new_window(gamedata->mlx,1024, 512,"Hello World");
    init(gamedata);
	//mlx_new_image(gamedata->mlx,16*  gamedata->mapX, 16 * gamedata->mapY);
    drawMap(gamedata);
    mlx_hook(gamedata->mlx_window, 2, 1L << 0, key_event, gamedata);
	//mlx_hook(gamedata.mlx_window, 17, 1L << 17, exit_game, &gamedata);
	mlx_loop(gamedata->mlx);
    return 0;
}

//Map Error Handling
//Readmap put into struct
//Raytracing