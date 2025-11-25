/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acobbaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:44:34 by acobbaer          #+#    #+#             */
/*   Updated: 2025/11/25 15:45:22 by acobbaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free (buf);
		buf = NULL;
		return (NULL);
	}
	stash = read_file(fd, stash, buf);
	free (buf);
	buf = NULL;
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = left_stash(stash);
	return (line);
}

static char	*read_file(int fd, char *stash, char *buf)
{
	char		*tmp;
	int			chars_read;

	while (!has_newline(stash))
	{
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (chars_read <= 0)
			break ;
		buf[chars_read] = '\0';
		if (!stash)
			tmp = ft_strdup(buf);
		else
			tmp = ft_strjoin(stash, buf);
		if (!tmp)
			return (NULL);
		free(stash);
		stash = tmp;
	}
	if (chars_read < 0)
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	return (stash);
}

static char	*get_line(char *stash)
{
	size_t		i;
	char		*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	return (line);
}

static char	*left_stash(char *stash)
{
	size_t		i;
	size_t		j;
	char		*res;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (stash[i] == '\0')
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	res = malloc(ft_strlen(stash) - i + 1);
	if (!res)
		return (NULL);
	j = 0;
	while (stash[i])
		res[j++] = stash[i++];
	free (stash);
	stash = NULL;
	res[j] = '\0';
	return (res);
}
