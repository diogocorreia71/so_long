/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:55:58 by diodos-s          #+#    #+#             */
/*   Updated: 2023/09/21 16:19:21 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	launch_game(char *map_file)
{
	t_game	so_long;
	
	ft_bzero(&so_long, sizeof(t_game));
	create_map(&so_long, map_file);
	check_map(&so_long);
	launch_mlx(&so_long);
	load_sprites(&so_long);
}

int	check_filename(char *str)
{
	if (ft_strnstr(str + ft_strlen(str) - 4, ".ber", 4))
		return (EXIT_SUCCESS);
	else
	{
		ft_printf("Error!\nInvalid file extension. Try <map_name>.ber");
		return (EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!check_filename(argv[1]))
			launch_game(argv[1]);
		else
			return (EXIT_FAILURE);
	}
	else
	{
		ft_printf("Error!\nInvalid number of arguments. ");
		ft_printf("Try <./so_long> <maps/map_name.ber>");
		return (EXIT_FAILURE);
	}
}