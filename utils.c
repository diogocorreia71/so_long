/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:06:22 by diodos-s          #+#    #+#             */
/*   Updated: 2023/09/22 11:36:08 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	return_msg(t_game *so_long)
{
	if (so_long->player != 1)
		return (11);
	else if (so_long->exit != 1)
		return (22);
	else if (so_long->total_coins < 1)
		return (33);
	return (EXIT_SUCCESS);
}

int	flood_fill(int total_coins, int y, int x, char **test_map)
{
	static int	coins;
	static int	exit;

	if (test_map[y][x] == WALL)
		return (0);
	else if (test_map[y][x] == COIN)
		coins++;
	else if (test_map[y][x] == EXIT)
		exit++;
	test_map[y][x] = WALL;
	flood_fill(total_coins, y, x + 1, test_map);
	flood_fill(total_coins, y, x - 1, test_map);
	flood_fill(total_coins, y + 1, x, test_map);
	flood_fill(total_coins, y - 1, x, test_map);
	if (coins == total_coins && exit == 1)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	quit_game(t_game *so_long)
{
	clean_game(so_long);
	exit(EXIT_SUCCESS);
}

int	exit_error(t_game *so_long, char *msg)
{
	clean_game(so_long);
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}