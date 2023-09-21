/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:12:42 by diodos-s          #+#    #+#             */
/*   Updated: 2023/09/21 16:22:51 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	launch_mlx(t_game *so_long)
{
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
		exit_error(so_long, "Failed to initialize MiniLibX.");
	so_long->win = mlx_new_window(so_long->mlx, so_long->cols * SIZE, so_long->rows * SIZE, "so_long");
	if (!so_long->win)
		exit_error(so_long, "Failed to create window.");
}

void	load_sprites(t_game *so_long)
{
	so_long->sprites = malloc(SPRITES * sizeof(t_sprite));
	if (!so_long->sprites)
		exit_error(so_long, "Failed to allocate memory to sprites.");
	
}