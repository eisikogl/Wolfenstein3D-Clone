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

void	exit_modes(int exit_mode)
{
	if (exit_mode == 0)
		perror("Error\n");
	if (exit_mode == 1)
		ft_printf("You left dude come back... ");
	if (exit_mode == 2)
		ft_printf("Congcats! Succesfully trapped the Kittens in the Tree");
	if (exit_mode == 3)
		ft_printf("Error\nInvalid Map");
	if (exit_mode == 4)
		ft_printf("Error\nInvalid Map: Only one Player spawn point allowed");
	if (exit_mode == 5)
		ft_printf("Error\nInvalid Map: No Collectibles found");
	if (exit_mode == 6)
		ft_printf("Error\nInvalid Map: Less than 1 Exit availible");
	if (exit_mode == 7)
		ft_printf("Error\nInvalid Map: Forbidden characters");
	if (exit_mode == 8)
		ft_printf("Error\nInvalid Map: Row too short");
	if (exit_mode == 9)
		ft_printf("Error\nInvalid Map: Empty row");
	if (exit_mode == 10)
		ft_printf("Error\ninvalid Map: No Player spawn points");
	if (exit_mode == 11)
		perror("Error\ninvalid Map .ber");
	exit_modes2(exit_mode);
}

void	exit_modes2(int exit_mode)
{
	if (exit_mode == 12)
		ft_printf("Error\nInvalid Map: Wall not connected First colum\
		\nxxxxxxx\nooooooo\nooooooo\nooooooo");
	if (exit_mode == 13)
		ft_printf("Error\nInvalid Map: Wall not connected Last colum\
		\nooooooo\nooooooo\nooooooo\nxxxxxxx");
	if (exit_mode == 14)
		ft_printf("Error\nInvalid Map: Wall not connected Middle Left\
		\nxoooooo\nxoooooo\nxoooooo\nxoooooo");
	if (exit_mode == 15)
		ft_printf("Error\nInvalid Map: Wall not connected Middle Right\
		\noooooox\noooooox\noooooox\noooooox");
}

int	exit_game(t_gamedata *gamedata, int exit_mode)
{
	exit_modes(exit_mode);
	if (gamedata)
		free(gamedata);
	exit(exit_mode);
}