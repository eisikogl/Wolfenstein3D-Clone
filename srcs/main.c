/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calion <calion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:42:20 by eisikogl          #+#    #+#             */
/*   Updated: 2022/11/10 22:34:13 by calion           ###   ########.fr       */
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
        mlx_pixel_put(gamedata->mlx, gamedata->mlx_window, pixelX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
}

// void drawRays(t_gamedata *gamedata)
// {
//     int r,map_x,map_y,map_pos,dof;
//     float ray_x,ray_y,ray_angle,x_offset,y_offset;
//     r = 0;
//     ray_angle = gamedata->player_angle;
//     //ray_x = ray_y / tan(ray_angle);
//     //ray_y = ((map_height * 16) - player_y) / 16;
//     while(r < 1)
//     {
//         dof = 0;
//         //float aTan = -1/tan(ray_angle);
//         if(ray_angle < PI && ray_angle >= PI/2 ) // looking up quadrant 2
//         {
//             ray_y = (int)(((gamedata->mapY * 16) - gamedata->player_y) / 16);
//             ray_x = gamedata->player_x - (gamedata->player_y - ray_y) / tan(ray_angle);
//             y_offset = -16;
//             x_offset = (y_offset) / tan(ray_angle);
//         }
//         if(ray_angle > 0 && ray_angle < PI / 2) // looking up quadrant 1
//         {
//             ray_y = (int)(((gamedata->mapY * 16) - gamedata->player_y) / 16);
//             ray_x = gamedata->player_x + (gamedata->player_y - ray_y) / tan(ray_angle);
//             y_offset = -16;
//             x_offset = -1 * ( y_offset / tan(ray_angle));
//         }
//         if(ray_angle > PI && ray_angle <= PI + PI/2) //looking down quadrant 3
//         {
//             ray_y = (int)((((gamedata->mapY * 16) - gamedata->player_y) / 16) + 16);
//             ray_x = gamedata->player_x - ((ray_y - gamedata->player_y) / tan(ray_angle));
//             y_offset = 16;
//             x_offset = -1 * (y_offset / tan(ray_angle));
//         }
//         if(ray_angle > PI + PI / 2 && ray_angle < 2*PI) //looking down quadrant 4
//         {
//             ray_y = (int)(((gamedata->mapY * 16) - gamedata->player_y) / 16) + 16;
//             ray_x = gamedata->player_x + ((ray_y - gamedata->player_y) / tan(ray_angle));
//             y_offset = 16;
//             x_offset = (y_offset / tan(ray_angle));
//         }
//         if(ray_angle == 0 || ray_angle == PI)
//         {
//             ray_x = gamedata->player_x;
//             ray_y = gamedata->player_y;
//             dof = gamedata->mapY;
//         }
//         // while(dof < gamedata->mapY)
//         // {
//             /*find position in array*/
//             //  map_x = (int)(ray_x) / 16;
//             //  map_y = (int)(ray_y) / 16;
//             // if(map_x < gamedata->mapX && map_y < gamedata->mapY && gamedata->map_split[map_y][map_x] == 1)
//             // {
//             //     dof = gamedata->mapY;
//             // }
//             // else
//             // {
//             //     ray_x += x_offset;
//                 // ray_y += y_offset;
//                 // dof += 1;
//             // }
//         // }

//         drawLine(gamedata,gamedata->player_x + 2,gamedata->player_y+2,
//         ray_x,ray_y,0x0000FF00);

//         r++;
//     }

// }

// void drawRays(t_gamedata *gamedata)
// {
//     int r,map_x,map_y,map_pos,dof;
//     float ray_x,ray_y,ray_angle,x_offset,y_offset;
//     r = 0;
//     ray_angle = gamedata->player_angle;
//     //ray_x = ray_y / tan(ray_angle);
//     //ray_y = ((map_height * 16) - player_y) / 16;
//     //S(int)playery
//     while(r < 1)
//     {
//         dof = 0;
//         //float aTan = -1/tan(ray_angle);
//         if(ray_angle < (PI - PI/2) && ray_angle > 0 ) // looking up quadrant 1
//         {
//             ray_y = (int)((gamedata->mapY * 16) - gamedata->player_y);
//             ray_x = gamedata->player_x + ((gamedata->player_y - ray_y) / tan(ray_angle));
//             y_offset = -16;
//             x_offset = (y_offset) / tan(ray_angle);
//         }
//         if(ray_angle >= PI - PI/2 && ray_angle < PI) // looking up quadrant 2
//         {
//             ray_y = (int)((gamedata->mapY  * 16) - gamedata->player_y);
//             ray_x = gamedata->player_x - ((gamedata->player_y - ray_y) / tan(ray_angle));
//             y_offset = -16;
//             x_offset = -1 * (-1 * y_offset) / tan(ray_angle);
//         }
//         if(ray_angle > PI && ray_angle <= PI + PI / 2) //looking down quadrant 3
//         {
//             ray_y = (int)((gamedata->mapY  * 16) - gamedata->player_y) + 16;
//             ray_x = gamedata->player_x - (tan(ray_angle) * (ray_y - gamedata->player_y));
//             y_offset = 16;
//             x_offset = ((-1 * y_offset) / tan(ray_angle));
//         }
//         if(ray_angle < (PI + PI / 2) && ray_angle < (2 * PI)) //looking down quadrant 4
//         {
//             ray_y = (int)((gamedata->mapY  * 16) - gamedata->player_y) + 16;
//             ray_x = gamedata->player_x + (tan(ray_angle) * (ray_y - gamedata->player_y));
//             y_offset = 16;
//             x_offset = (y_offset / tan(ray_angle));
//         }
//         if(ray_angle == 0 || ray_angle == PI)
//         {
//             ray_x = gamedata->player_x;
//             ray_y = gamedata->player_y;
//             dof = gamedata->mapY;
//         }
//         while(dof < gamedata->mapY)
//         {
//             /*find position in array*/
//              map_x = (int)(ray_x) / 16;
//              map_y = (int)(ray_y) / 16;
//             if(map_x < gamedata->mapX && map_y < gamedata->mapY && gamedata->map_split[map_y][map_x] == '1')
//             {
//                 dof = gamedata->mapY;
//             }
//             else
//             {
//                 ray_x += x_offset;
//                 ray_y += y_offset;
//                 dof += 1;
//             }
//        }

//         drawLine(gamedata,gamedata->player_x + 2,gamedata->player_y+2,
//         ray_x,ray_y,0x0000FF00);

//         r++;
//     }

// }

// void drawRays(t_gamedata *gamedata)
// {
//     int r,map_x,map_y,map_pos,dof;
//     float ray_x,ray_y,ray_angle,x_offset,y_offset;
//     //ray_x = ray_y / tan(ray_angle);
//     //ray_y = ((map_height * 16) - player_y) / 16;
//     //S(int)playery
//     /*Horizontal Line check*/
//     r = 0;
//     ray_angle = gamedata->player_angle;
//     while(r < 1)
//     {
//         dof = 0;
//         float aTan = -1/tan(ray_angle);
   
//         if(ray_angle < PI) // looking up quadrant 2
//         {
//             ray_y = (((int)gamedata->player_y>>4)<<4)-0.0001;
//             ray_x = (gamedata->player_y - ray_y) * aTan + gamedata->player_x;
//             y_offset = -16;
//             x_offset = -y_offset * aTan;
//         }
//         if(ray_angle > PI) //looking down quadrant 3
//         {
//             ray_y = (((int)gamedata->player_y>>4)<<4)+16;
//             ray_x = (gamedata->player_y - ray_y) * aTan + gamedata->player_x;
//             y_offset = 16;
//             x_offset = -y_offset * aTan;
//         }

//         if(ray_angle == 0 || ray_angle == PI)
//         {
//             ray_x = gamedata->player_x;
//             ray_y = gamedata->player_y;
//             dof = gamedata->mapY;
//         }
//         while(dof < gamedata->mapY)
//         {
//             /*find position in array*/
//              map_x = (int)(ray_x) >> 4;
//              map_y = (int)(ray_y) >> 4;
//             // map_pos = map_y * gamedata->mapX + map_x;

//             if(map_x < gamedata->mapX && map_y < gamedata->mapY && gamedata->map_split[map_y][map_x] == '1')
//             {
//                 dof = gamedata->mapY;
//             }
//             else
//             {
//                 ray_x += x_offset;
//                 ray_y += y_offset;
//                 dof += 1;
//             }
//        }

//         drawLine(gamedata,gamedata->player_x + 2,gamedata->player_y+2,
//         ray_x,ray_y,0x0000FF00);

//     /*Vertical Line check*/
//     //     dof = 0;
//     //     float nTan = -tan(ray_angle);
//     //     if(ray_angle > P2 && ray_angle < P3) // looking left
//     //     {
//     //         ray_x = (((int)gamedata->player_x>>4)<<4)-0.0001;
//     //         ray_y = (gamedata->player_x - ray_x) * nTan + gamedata->player_y;
//     //         x_offset = -16;
//     //         y_offset = -x_offset * nTan;
//     //     }
//     //     if(ray_angle < P2 || ray_angle > P3) //looking right
//     //     {
//     //         ray_x = (((int)gamedata->player_x>>4)<<4)+16;
//     //         ray_y = (gamedata->player_x - ray_x) * nTan + gamedata->player_y;
//     //         x_offset = 16;
//     //         y_offset = -x_offset * nTan;
//     //     }
//     //     if(ray_angle == 0 || ray_angle == PI)
//     //     {
//     //         ray_x = gamedata->player_x;
//     //         ray_y = gamedata->player_y;
//     //         dof = gamedata->mapY;
//     //     }
//     //     while(dof < gamedata->mapY)
//     //     {
//     //         /*find position in array*/
//     //          map_x = (int)(ray_x) >> 4;
//     //          map_y = (int)(ray_y) >> 4;
//     //         // map_pos = map_y * gamedata->mapX + map_x;

//     //         if(map_x < gamedata->mapY && map_y < gamedata->mapY && gamedata->map_split[map_y][map_x] == '1')
//     //         {
//     //             dof = gamedata->mapY;
//     //         }
//     //         else
//     //         {
//     //             ray_x += x_offset;
//     //             ray_y += y_offset;
//     //             dof += 1;
//     //         }
//     //    }
//     //     drawLine(gamedata,gamedata->player_x + 2,gamedata->player_y+2,
//     //     ray_x,ray_y,0x00FF0000);
//         r++;
// 	}
// }

void drawRays(t_gamedata *gamedata)
{
    int r,map_x,map_y,map_pos,dof;
    float ray_x,ray_y,ray_angle,x_offset,y_offset;
    //ray_x = ray_y / tan(ray_angle);
    //ray_y = ((map_height * 16) - player_y) / 16;
    //S(int)playery
    /*Horizontal Line check*/
    r = 0;
    ray_angle = gamedata->player_angle;
    printf("im rayangle: %f\n",ray_angle);
  
         dof = 0;
         float aTan = tan(ray_angle);
        if(ray_angle < PI) // looking up quadrant 2
        {
           ray_y = ((int)(gamedata->player_y / 16) * 16) - 0.000001;
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

          if(ray_angle == PI || ray_angle == 0 || ray_angle == 2*PI)
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

            if(map_x < gamedata->mapX && map_y < gamedata->mapY && gamedata->map_split[map_y][map_x] == '1')
            {
                dof = gamedata->mapY;
            }
            else
            {
                ray_x += x_offset;
                ray_y += y_offset;
                dof += 1;
            }
       }
        drawLine(gamedata,gamedata->player_x + 2,gamedata->player_y+2,
        ray_x ,ray_y,0x0000FF00);

    /*Vertical Line check*/
    
    //      dof = 0;
    //     aTan = tan(ray_angle);
    //     if((ray_angle > (PI / 2) && ray_angle < (3*PI/2)) && ray_angle != PI) //looking down quadrant 3
    //     {
    //         ray_x = ((int)(gamedata->player_x / 16) * 16) - 0.000001;
    //         ray_y = ((gamedata->player_x - ray_x) / aTan) + gamedata->player_y;
    //         x_offset = -16;
    //         y_offset = -(x_offset / aTan);
    //     }
    //     if(((ray_angle < (PI/2) || ray_angle > (3*PI/2)) && ray_angle != 0 && ray_angle != 2*PI)) // looking up quadrant 2
    //     {
    //        ray_x = ((int)(gamedata->player_x / 16) * 16 ) + 16;
    //        ray_y = ((gamedata->player_x - ray_x) / aTan) + gamedata->player_y;
    //        x_offset = 16;
    //        y_offset = -(x_offset / aTan);
    //     }

    //     if(ray_angle == PI || ray_angle == 0 || ray_angle == 2*PI)
    //     {
    //         ray_x = gamedata->player_x;
    //         ray_y = gamedata->player_y;
    //         dof = gamedata->mapX;
    //     }
    //     while(dof < gamedata->mapX)
    //     {
    //         /*find position in array*/
    //          map_x = (int)(ray_x) / 16;
    //          map_y = (int)(ray_y) / 16;
    //         //  printf("im map_X : %d \n",map_x);
    //         //  printf("im map_Y : %d \n",map_y);
    //         // map_pos = map_y * gamedata->mapX + map_x;

    //         if(map_x < gamedata->mapX && map_y < gamedata->mapY && gamedata->map_split[map_y][map_x] == '1')
    //         {
    //             dof = gamedata->mapX;
    //         }
    //         else
    //         {
    //             ray_x += x_offset;
    //             ray_y += y_offset;
    //             dof += 1;
    //         }
    //    }

    //     drawLine(gamedata,gamedata->player_x + 2,gamedata->player_y+2,
    //     ray_x ,ray_y,0x00FFFF00);
        
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
    drawWall(call_map,x,y);
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
    init(gamedata);
	mlx_new_image(gamedata->mlx,16*  gamedata->mapX, 16 * gamedata->mapY);
    drawMap(gamedata);
    mlx_hook(gamedata->mlx_window, 2, 1L << 0, key_event, gamedata);
	//mlx_hook(gamedata.mlx_window, 17, 1L << 17, exit_game, &gamedata);
	mlx_loop(gamedata->mlx);
    return 0;
}

//Map Error Handling
//Readmap put into struct
//Raytracing