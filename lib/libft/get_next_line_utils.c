/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:47:47 by diodos-s          #+#    #+#             */
/*   Updated: 2023/09/20 09:36:41 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*new_stash_aux(char *new_stash)
{
	if (new_stash[0] == '\0')
	{
		free (new_stash);
		new_stash = 0;
	}
	return (new_stash);
}

char	*new_stash(char *stash)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (stash[i])
		str[j++] = stash[i++];
	str[j] = '\0';
	free(stash);
	str = new_stash_aux(str);
	return (str);
}

char	*extract_line(char *stash)
{
	int		i;
	char	*str;

	i = 0;
	if (stash[i] == 0)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		str = malloc(sizeof(char) * (i + 1));
	else
		str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{	
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*found_new_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*add_to_stash(char *stash, char *buf)
{
	size_t	i;
	size_t	j;
	char	*add;

	i = -1;
	j = 0;
	if (!stash)
	{
		stash = (char *)malloc(1 * sizeof(char));
		stash[0] = '\0';
	}
	if (!stash || !buf)
		return (NULL);
	add = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buf) + 1));
	if (!add)
		return (NULL);
	while (stash[++i] != '\0')
		add[i] = stash[i];
	while (buf[j] != '\0')
		add[i++] = buf[j++];
	add[i] = '\0';
	free(stash);
	return (add);
}
