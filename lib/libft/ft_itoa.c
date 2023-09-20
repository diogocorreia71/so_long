/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:50:03 by diodos-s          #+#    #+#             */
/*   Updated: 2023/04/20 14:18:38 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_if(size_t size, char *str)
{
	if (size == 0 && str[1] == '\0')
		*(str + size) = '0';
	if (size == 0 && str[1] != '\0')
		*(str + size) = '-';
	return (str);
}

long	check_nbr(long nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}

int	check_size(int n)
{
	if (n > 0)
		n = 0;
	else
		n = 1;
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	size;

	nbr = n;
	size = check_size(n);
	nbr = check_nbr(nbr);
	while (n)
	{
		n = (n / 10);
		size++;
	}
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	*(str + size--) = '\0';
	while (nbr > 0)
	{
		*(str + size--) = nbr % 10 + '0';
		nbr = (nbr / 10);
	}
	str = check_if(size, str);
	return (str);
}
