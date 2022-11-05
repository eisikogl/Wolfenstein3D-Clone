/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calion <calion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:56:45 by eisikogl          #+#    #+#             */
/*   Updated: 2022/11/06 00:20:51 by calion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <math.h>

#include "../libs/mlx/mlx.h"
#include "../libs/Libft/libft.h"

#include "../includes/get_next_line.h"
#define PI 3.14159265359 

typedef struct s_gamedata
{
    void *mlx;
    void *mlx_window;
    void *img_player;
    void *img_wall;

    int  player_x;
    int  player_y;

    float player_dy;
    float player_dx;
    float player_angle;
}t_gamedata;

typedef struct s_map
{
    char *map_path;
    char *map;
    char **map_split;

    char *north_texture_path;
    char *south_texture_path;
    char *west_texture_path;
    char *east_texture_path;

    int *floor_color;
    int *ceiling_color;
    /* data */
}t_map;

/*input_control*/
int key_event(int key, t_gamedata *gamedata);

/*read_map*/
void read_map(t_map *call_map);

/*exit_game*/
int	exit_game(t_gamedata *gamedata);

/*controlls*/
int get_line_len(t_map *call_map);
int get_height(t_map *call_map);
void drawPlayer(t_gamedata *gamedata);
void drawWall(t_gamedata *gamedata,int i,int j);
void init(t_gamedata *gamedata);

#endif