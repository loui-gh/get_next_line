/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:39:25 by Loui :)           #+#    #+#             */
/*   Updated: 2021/12/22 23:25:36 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9
# endif

char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *string, int c);
size_t	ft_strl(const char *s, int flag);
char	*find_nextline(int fd, char *nextline, char *tmp, ssize_t rc);
char	*get_next_line(int fd);
char	*no_nl(char *nextline, int fd, char *buf, ssize_t rc);
char	*do_this(char *nextline, char *buf);

#endif