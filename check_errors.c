/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:24:01 by diodos-s          #+#    #+#             */
/*   Updated: 2023/09/25 09:05:41 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_paths(t_game *so_long)
{
	int	i;
	int	reach_exit;
	char **test_map;

	i = -1;
	reach_exit = 0;
	test_map = ft_calloc(so_long->rows + 1, sizeof(char *));
	if (!test_map)
		exit_error(so_long, "Memory allocaction failed.");
	while (++i < so_long->rows)
	{
		test_map[i] = ft_strdup(so_long->map[i]);
		{
			if (!test_map)
				exit_error(so_long, "Memory allocaction failed.");
		}
	}
	reach_exit = flood_fill(so_long->total_coins, so_long->curr.y, so_long->curr.x, test_map);
	clean_test_map(test_map);
	return (reach_exit);
}

int	check_sprites(t_game *so_long)
{
	int	i;
	int	j;

	i = -1;
	while (++i < so_long->rows)
	{
		j = -1;
		while (++j < so_long->cols)
		{
			if (so_long->map[i][j] == PLAYER)
			{
				so_long->player++;
				so_long->curr.x = j;
				so_long->curr.y = i;
			}
			else if (so_long->map[i][j] == EXIT)
				so_long->exit++;
			else if (so_long->map[i][j] == COIN)
				so_long->total_coins++;
			else if (!ft_strchr("01CEP", so_long->map[i][j]))
				return (44);
		}
	}
	return (return_msg(so_long));
}

int	check_walls(t_game *so_long)
{
	int	i;

	i = -1;
	while (++i < so_long->rows)
		if (so_long->map[i][0] != WALL || so_long->map[i][so_long->cols - 1] != WALL)
			return (EXIT_FAILURE);
	i = -1;
	while (++i < so_long->cols)
		if (so_long->map[0][i] != WALL || so_long->map[so_long->rows - 1][i] != WALL)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_format(t_game *so_long)
{
	int 	i;
	int 	row_len;

	i = 0;
	row_len = ft_strlen(so_long->map[0]);
	while (i < so_long->rows)
	{
		if (ft_strlen(so_long->map[1]) != row_len)
			return (EXIT_FAILURE);
		i++;
	}
	so_long->cols = ft_strlen(so_long->map[0]);
	return (EXIT_SUCCESS);
}

void	check_map(t_game *so_long)
{
	int	i;

	if (!so_long->rows)
		exit_error(so_long, "Map is empty.");
	if (check_format(so_long))
		exit_error(so_long, "Map is not a rectangle.");
	if (check_walls(so_long))
		exit_error(so_long, "Map is not surrounded by walls.");
	i = check_sprites(so_long);
	if (i == 11)
		exit_error(so_long, "Map has invalid number of players.");
	else if (i == 22)
		exit_error(so_long, "Map has invalid number of exits.");
	else if (i == 33)
		exit_error(so_long, "Map has invalid number of collectables.");
	else if (i == 44)
		exit_error(so_long, "Map has invalid characters.");
	if (check_paths(so_long))
		exit_error(so_long, "Map has invalid path.");
}