/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:59:39 by diodos-s          #+#    #+#             */
/*   Updated: 2023/09/21 16:09:36 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/libft/libft.h"
# include "lib/mlx/mlx.h"

# define SPACE		'0'
# define WALL		'1'
# define COIN		'C'
# define EXIT		'E'
# define PLAYER		'P'

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_sprite
{
	void	*img;
	int		height;
	int		width;
}			t_sprite;

typedef struct s_game
{
	t_sprite	*sprites;
	t_position	prev;
	t_position	curr;
	void		*mlx;
	void		*win;
	char		**map;
	int			rows;
	int			cols;
	int			moves;
	int			player;
	int			total_coins;
	int			coins;
	int			exit;
}	t_game;

int		check_filename(char *str);
void	create_map(t_game *so_long, char *map_file);
void	get_rows(t_game *so_long, char *map_file);
void	launch_game(char *map_file);
void	read_map(t_game *so_long, int fd);
int		exit_error(t_game *so_long, char *msg);
void	check_map(t_game *so_long);
int		check_paths(t_game *so_long);
int		check_sprites(t_game *so_long);
int		check_walls(t_game *so_long);
int		check_format(t_game *so_long);
void	clean_exit_test(char **test_map);

#endif