/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:12:42 by diodos-s          #+#    #+#             */
/*   Updated: 2023/09/27 14:12:31 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	launch_mlx(t_game *so_long)
{
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
		exit_error(so_long, "Failed to initialize MiniLibX.");
	so_long->win = mlx_new_window(so_long->mlx, so_long->cols * SIZE,
			so_long->rows * SIZE, "so_long");
	if (!so_long->win)
		exit_error(so_long, "Failed to create window.");
}

void	load_sprites(t_game *so_long)
{
	so_long->sprites = malloc(SPRITES * sizeof(t_sprite));
	if (!so_long->sprites)
		exit_error(so_long, "Failed to allocate memory to sprites.");
	so_long->sprites[W1].img = mlx_xpm_file_to_image(so_long->mlx, FW1,
			&(so_long->sprites[W1].width), &(so_long->sprites[W1].height));
	so_long->sprites[S1].img = mlx_xpm_file_to_image(so_long->mlx, FS1,
			&(so_long->sprites[S1].width), &(so_long->sprites[S1].height));
	so_long->sprites[C1].img = mlx_xpm_file_to_image(so_long->mlx, FC1,
			&(so_long->sprites[C1].width), &(so_long->sprites[C1].height));
	so_long->sprites[E1].img = mlx_xpm_file_to_image(so_long->mlx, FE1,
			&(so_long->sprites[E1].width), &(so_long->sprites[E1].height));
	so_long->sprites[P1].img = mlx_xpm_file_to_image(so_long->mlx, FP1,
			&(so_long->sprites[P1].width), &(so_long->sprites[P1].height));
}

void	render_map(t_game *so_long)
{
	int	x;
	int	y;

	y = -1;
	while (++y < so_long->rows)
	{
		x = -1;
		while (++x < so_long->cols)
			render_position(so_long, x, y);
	}
}

void	render_position(t_game *so_long, int x, int y)
{
	if (so_long->map[y][x] == '1')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->sprites[W1].img, so_long->sprites[W1].width * x,
			so_long->sprites[W1].height * y);
	else if (so_long->map[y][x] == 'C')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->sprites[C1].img, so_long->sprites[C1].width * x,
			so_long->sprites[C1].height * y);
	else if (so_long->map[y][x] == 'E')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->sprites[E1].img, so_long->sprites[E1].width * x,
			so_long->sprites[E1].height * y);
	else if (so_long->map[y][x] == '0')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->sprites[S1].img, so_long->sprites[S1].width * x,
			so_long->sprites[S1].height * y);
	else if (so_long->map [y][x] == 'P')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->sprites[P1].img, so_long->sprites[P1].width * x,
			so_long->sprites[P1].height * y);
}
