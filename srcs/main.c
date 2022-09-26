/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calion <calion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:42:20 by eisikogl          #+#    #+#             */
/*   Updated: 2022/09/26 17:19:09 by calion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

// The map must be composed of only 6 possible characters: 0 for an empty space,
// 1 for a wall, and N,S,E or W for the player’s start position and spawning
// orientation.

int main()
{
    void	*mlx;
    mlx = mlx_init();

    mlx_new_window(mlx,500,500,"Hello World");    
    // mlx_hook(gamedata->mlx_window, 2, 1L << 0, key_event, gamedata);
	// mlx_hook(gamedata->mlx_window, 17, 1L << 17, exit_game, gamedata);
	mlx_loop(mlx);
}