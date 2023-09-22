/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:39:38 by diodos-s          #+#    #+#             */
/*   Updated: 2023/09/22 11:02:40 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *so_long)
{
	static int	flag;

	if (flag)
	{
		so_long->map[so_long->curr.y][so_long->curr.x] = PLAYER;
		so_long->map[so_long->prev.y][so_long->prev.x] = EXIT;
		flag = 0;
	}
	else if (so_long->map[so_long->curr.y][so_long->curr.x] == EXIT)
	{
		so_long->map[so_long->prev.y][so_long->prev.x] = SPACE;
		flag = 1;
	}
	else
		so_long->map[so_long->prev.y][so_long->prev.x] = SPACE;
	so_long->map[so_long->curr.y][so_long->curr.x] = PLAYER;
	render_position(so_long, so_long->prev.y, so_long->prev.x);
	render_position(so_long, so_long->curr.y, so_long->curr.x);
}

void	check_move(t_game *so_long, int key)
{
	if (so_long->map[so_long->curr.y][so_long->curr.x] != WALL)
	{
		if (key == W || key == A || key == S || key == D || key == UP || key == LEFT || key == DOWN || key == RIGHT)
			ft_printf("Moves: %i\n", ++so_long->moves);
		if (so_long->map[so_long->curr.y][so_long->curr.x] == COIN)
			so_long->coins++;
		else if (so_long->map[so_long->curr.y][so_long->curr.x] == EXIT && so_long->coins == so_long->total_coins)
		{
			ft_printf("You won!\n");
			quit_game(so_long);
		}
		move_player(so_long);
	}
	else
	{
		so_long->curr.y = so_long->prev.y;
		so_long->curr.x = so_long->prev.x;
	}
}

int	check_key(int key, t_game *so_long)
{
	so_long->prev.y = so_long->curr.y;
	so_long->prev.x = so_long->curr.x;
	if (key == ESC)
		quit_game(so_long);
	else if (key == W || key == UP)
		so_long->curr.y--;
	else if (key == A || key == LEFT)
		so_long->curr.x--;
	else if (key == S || key == DOWN)
		so_long->curr.y++;
	else if (key == D || key == RIGHT)
		so_long->curr.x++;
	check_move(so_long, key);
	return (key);
}