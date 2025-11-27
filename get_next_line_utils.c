/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acobbaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:50:22 by acobbaer          #+#    #+#             */
/*   Updated: 2025/11/27 13:59:26 by acobbaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	size_t		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	size_t			i;
	char			*res;

	if (!s1)
		return (NULL);
	res = malloc(ft_strlen(s1) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*res;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (start > i)
	{
		start = i;
		len = 0;
	}
	else if (len > i - start)
		len = i - start;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (start < len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*res;
	int			i;
	int			j;

	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		res[j + i] = s2[i];
		i++;
	}
	res[i + j] = '\0';
	return (res);
}

int	has_newline(char *stash)
{
	size_t		i;

	if (!stash)
		return (0);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
