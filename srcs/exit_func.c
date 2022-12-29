/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eisikogl <eisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:55:50 by eisikogl          #+#    #+#             */
/*   Updated: 2022/12/29 18:12:59 by eisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ft_error(char *msg)
{
	printf("%s\n", msg);
	return (0);
}

void	ft_free_cub(t_gamedata *cub)
{
	free(cub->no_path);
	free(cub->so_path);
	free(cub->we_path);
	free(cub->ea_path);
}

int	exit_game(t_gamedata *gamedata)
{
	if (gamedata->mlx_3dwindow != NULL)
		mlx_destroy_window(gamedata->mlx, gamedata->mlx_3dwindow);
	system("leaks cube3d_mac");
	exit(1);
	return (0);
}