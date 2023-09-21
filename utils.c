/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:06:22 by diodos-s          #+#    #+#             */
/*   Updated: 2023/09/21 15:07:46 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_error(t_game *so_long, char *msg)
{
	clean_game(so_long);
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}