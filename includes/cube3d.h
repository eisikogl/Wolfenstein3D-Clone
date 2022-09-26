/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calion <calion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:56:45 by eisikogl          #+#    #+#             */
/*   Updated: 2022/09/26 19:24:28 by calion           ###   ########.fr       */
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

typedef struct s_gamedata
{
    /* data */
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


void read_map(t_map call_map);

#endif