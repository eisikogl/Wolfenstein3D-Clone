/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eisikogl <eisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:55:50 by eisikogl          #+#    #+#             */
/*   Updated: 2022/12/29 14:26:16 by eisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	exit_game(t_gamedata *gamedata)
{
	mlx_destroy_window(gamedata->mlx,gamedata->img2d);
	mlx_destroy_window(gamedata->mlx,gamedata->img3dwin);
	free(gamedata);
	return 0;
}

int	ft_max(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
}

size_t	ft_splitlen(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	ft_check_file_extension(char *name)
{
	char	**split;
	int		i;

	split = ft_split(name, '.');
	i = 0;
	while (split[i])
		i++;
	if (i <= 1)
	{
		ft_free_split(split);
		printf("Error in file format \n");
		return (0);
	}
	if (ft_strncmp(split[i - 1], "cub", ft_max(3, ft_strlen(split[i - 1]))))
	{
		ft_free_split(split);
		printf("Error in file format \n");
		return (0);
	}
	ft_free_split(split);
	return (1);
}

t_data	get_xpm_image(t_gamedata *cub, char *path)
{
	t_data	img;
	int		w;
	w = 64;
	img.img = mlx_xpm_file_to_image(cub->mlx, path, &w, &w);
	if (!img.img)
	{
		free(path);
		return (img);
	}
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
}

/*
 * Check if the files for the textures exist and save the path
 * on the cub structure.  */
int	check_direction_path(t_gamedata *cub, char **split, int *num)
{
	char	*path;
	t_data	img;

	if (ft_splitlen(split) != 2)
		return (0);
	path = ft_strdup(split[1]);
	// img = get_xpm_image(cub, path);
	// if (!img.img)
	// 	return (0);
	if (!ft_strncmp(split[0], "NO", 2) && !cub->no_path)
		cub->no_path = path;
	else if (!ft_strncmp(split[0], "SO", 2) && !cub->so_path)
		cub->so_path = path;
	else if (!ft_strncmp(split[0], "WE", 2) && !cub->we_path)
		cub->we_path = path;
	else if (!ft_strncmp(split[0], "EA", 2) && !cub->ea_path)
		cub->ea_path = path;
	else
		return (0);
	// mlx_destroy_image(cub->mlx, img.img);
	*num += 1;
	return (1);
}

/*
 * Check if the colors for the floor and cealing are valid 
 * and save them on the cub structure.
 */
int	check_color_code(t_gamedata *cub, char **split, int *num)
{
	char	**colors;
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (ft_splitlen(split) != 2)
		return (0);
	colors = ft_split(split[1], ',');
	if (ft_splitlen(colors) != 3)
		n = -1;
	while (i < 3 && n != -1)
	{
		n = ft_atoi(colors[i]);
		if ((n < 0) | (n > 255))
			n = -1;
		else if (!ft_strncmp(split[0], "F", 1))
			cub->f_color[i] = n;
		else if (!ft_strncmp(split[0], "C", 1))
			cub->c_color[i] = n;
		i++;
	}
	ft_free_split(colors);
	*num += 1;
	return (n != -1);
}

int	is_valid_param(t_gamedata *cub, char *line, int *num)
{
	int		r;
	char	*first;
	size_t	l;
	char	**split;

	split = ft_split(line, ' ');
	first = split[0];
	l = ft_strlen(first);
	r = 0;
	if (!ft_strncmp(first, "NO", l) || !ft_strncmp(first, "SO", l)
		|| !ft_strncmp(first, "WE", l) || !ft_strncmp(first, "EA", l))
	{
		r = check_direction_path(cub, split, num);
	}
	else if (!ft_strncmp(first, "F", l) || !ft_strncmp(first, "C", l))
		r = check_color_code(cub, split, num);
	if (r != 0)
		free(line);
	ft_free_split(split);
	return (r);
}
