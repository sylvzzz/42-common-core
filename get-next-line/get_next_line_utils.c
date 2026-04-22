/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:47:33 by dbotelho          #+#    #+#             */
/*   Updated: 2025/12/15 10:51:45 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (free(s1), NULL);
	i = 0;
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i++] = s2[j];
		if (s2[j++] == '\n')
			break ;
	}
	join[i] = '\0';
	free(s1);
	return (join);
}

int	ft_checknl(const char *buf)
{
	int	i;

	i = 0;
	while (buf && buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_mvbuff(char *buff)
{
	int	i;
	int	j;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	j = 0;
	while (buff[i])
	{
		buff[j] = buff[i];
		i++;
		j++;
	}
	buff[j] = '\0';
}

void	ft_fillbuff(int fd, char *buf)
{
	ssize_t	bytes;

	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes > 0)
		buf[bytes] = '\0';
	else
		*buf = '\0';
}
