/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calion <calion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:42:20 by eisikogl          #+#    #+#             */
/*   Updated: 2022/12/16 23:40:09 by calion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	init_textures(t_gamedata *gamedata)
{
	int	x;

	x = 64;
	gamedata->north_texture = mlx_xpm_file_to_image(gamedata->mlx, \
	gamedata->north_texture_path, &x, &x);
	gamedata->north_addr = mlx_get_data_addr(gamedata->north_texture, \
	&gamedata->north_bits_per_pixel, &gamedata->north_line_length, \
	&gamedata->north_endian);
}

void	init_2dwindow(t_gamedata *gamedata)
{
	gamedata->mapX = get_line_len(gamedata);
	gamedata->mapY = get_height(gamedata);
	gamedata->mlx_window = mlx_new_window(gamedata->mlx, 16 * gamedata->mapX, \
	16 * gamedata->mapY, "2D_MAP");
	gamedata->img2d = mlx_new_image(gamedata->mlx, gamedata->mapX * 16, \
	gamedata->mapY * 16);
	gamedata->addr = mlx_get_data_addr(gamedata->img2d, \
	&gamedata->bits_per_pixel, &gamedata->line_length, &gamedata->endian);
}

void	init_3dwindow(t_gamedata *gamedata)
{
	gamedata->mlx_3dwindow = mlx_new_window(gamedata->mlx, 1024, 512, "3D");
	gamedata->window_height = 512;
	gamedata->window_width = 1024;
	gamedata->img3dwin = mlx_new_image(gamedata->mlx, gamedata->window_width, \
	gamedata->window_height);
	gamedata->addr3d = mlx_get_data_addr(gamedata->img3dwin, \
	&gamedata->bits_per_pixel3d, &gamedata->line_length3d, &gamedata->endian3d);
}

void	init_floor_ceiling(t_gamedata *gamedata)
{
	gamedata->trgb_floor = create_trgb(0, gamedata->floor_color[0], \
	gamedata->floor_color[1], gamedata->floor_color[2]);
	gamedata->trgb_ceiling = create_trgb(0, gamedata->ceiling_color[0], \
	gamedata->ceiling_color[1], gamedata->ceiling_color[2]);
}

int	main(int argc, char **argv)
{
	t_gamedata	*gamedata;

	gamedata = malloc(sizeof(t_gamedata));
	if (argc != 2)
		printf("add map \n");
	gamedata->mlx = mlx_init();
	gamedata->map_path = argv[1];
	read_map(gamedata);
	gamedata->map_split = ft_split(gamedata->map, '\n');
	init_2dwindow(gamedata);
	init_3dwindow(gamedata);
	init_floor_ceiling(gamedata);
	drawMap(gamedata);
	mlx_hook(gamedata->mlx_window, 2, 1L << 0, key_event, gamedata);
	//mlx_hook(gamedata.mlx_window, 17, 1L << 17, exit_game, &gamedata);
	mlx_loop(gamedata->mlx);
	return (0);
}
