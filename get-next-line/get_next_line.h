/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:47:46 by dbotelho          #+#    #+#             */
/*   Updated: 2025/12/15 10:51:20 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *s);
void	upd_buff(char *buffer, size_t start);
int		ft_checknl(const char *buf);
void	ft_mvbuff(char *buf);
void	ft_fillbuff(int fd, char *buf);
char	*get_next_line(int fd);

#endif
