/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calion <calion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:42:20 by eisikogl          #+#    #+#             */
/*   Updated: 2022/09/26 22:10:06 by calion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

// The map must be composed of only 6 possible characters: 0 for an empty space
// 1 for a wall, and N,S,E or W for the player’s start position and spawning
// orientation.

int main(int argc,char **argv)
{
    void	*mlx;
    t_map   call_map;

    if(argc != 2)
        printf("add map \n");
    mlx = mlx_init();
    call_map.map_path = argv[1];
    read_map(&call_map);
    printf("%s \n",call_map.north_texture_path);
    printf("%s \n",call_map.south_texture_path);
    printf("%s \n",call_map.east_texture_path);
    printf("%s \n",call_map.west_texture_path);
    printf("%d %d %d\n",call_map.floor_color[0],call_map.floor_color[1],call_map.floor_color[2]);
    printf("%d %d %d\n",call_map.ceiling_color[0],call_map.ceiling_color[1],call_map.ceiling_color[2]);
    printf("%s \n",call_map.map);
    //mlx_new_window(mlx,500,500,"Hello World");
    //mlx_hook(gamedata->mlx_window, 2, 1L << 0, key_event, gamedata);
	// mlx_hook(gamedata->mlx_window, 17, 1L << 17, exit_game, gamedata);
	mlx_loop(mlx);
}

//Map Error Handling
//Readmap put into struct
//Raytracing