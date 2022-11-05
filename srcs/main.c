/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calion <calion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:42:20 by eisikogl          #+#    #+#             */
/*   Updated: 2022/11/06 00:20:48 by calion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

// The map must be composed of only 6 possible characters: 0 for an empty space
// 1 for a wall, and N,S,E or W for the player’s start position and spawning
// orientation.

// void init(t_gamedata *gamedata)
// {
//     char	*path_player;
//     char	*path_wall;
//     int x = 16;
//     int y = 16;

// 	path_wall = "./assets/wall.xpm";
// 	path_player = "./assets/player.xpm";

//     gamedata->img_wall = mlx_xpm_file_to_image(gamedata->mlx, path_wall, &x, &y);
//     gamedata->img_player = mlx_xpm_file_to_image(gamedata->mlx, path_player, &x, &y);
// }

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


void drawMap(t_gamedata *gamedata, t_map *call_map)
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
                drawWall(gamedata,x,y);
                x += 16;
            }
            else if(call_map->map_split[i][j] == 'N')
            {
                gamedata->player_x = x;
                gamedata->player_y = y;
                drawPlayer(gamedata);
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
}

int main(int argc,char **argv)
{
    t_map       call_map;
    t_gamedata  *gamedata;

    gamedata = malloc(sizeof(t_gamedata));
    if(argc != 2)
        printf("add map \n");
    gamedata->mlx = mlx_init();
    call_map.map_path = argv[1];
    read_map(&call_map);
    call_map.map_split = ft_split(call_map.map,'\n');
    int maplen = get_line_len(&call_map);
    int mapheight = get_height(&call_map);
    gamedata->mlx_window = mlx_new_window(gamedata->mlx,16*maplen, 16 * mapheight,"Hello World");
    init(gamedata);
    drawMap(gamedata,&call_map);
    mlx_hook(gamedata->mlx_window, 2, 1L << 0, key_event, gamedata);
	//mlx_hook(gamedata.mlx_window, 17, 1L << 17, exit_game, &gamedata);
	mlx_loop(gamedata->mlx);
    return 0;
}

//Map Error Handling
//Readmap put into struct
//Raytracing