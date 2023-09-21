/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:58:24 by diodos-s          #+#    #+#             */
/*   Updated: 2023/09/21 15:59:36 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_exit_test(char **test_map)
{
	size_t	i;
	
	i = 0;
	if (!test_map)
		return ;
	while (test_map[i])
		free(test_map[i++]);
	free(test_map);
}