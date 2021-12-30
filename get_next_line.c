/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:32:59 by Loui :)           #+#    #+#             */
/*   Updated: 2021/12/22 23:21:31 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strl(const char *s, int flag)
{
	size_t	i;

	i = 0;
	if (flag == 0)
	{
		while (s[i] != '\0')
			i++;
		return (i);
	}
	else
	{
		while (s[i] != '\n')
			i++;
		i++;
		return (i);
	}
	return (0);
}

char	*do_this(char *nextline, char *buf)
{
	char	*tmp;

	tmp = ft_substr(buf, 0, ft_strl(buf, 1));
	nextline = ft_strjoin(nextline, tmp);
	free (tmp);
	tmp = ft_substr(buf, ft_strl(buf, 1), ft_strl(buf, 0));
	ft_bzero(buf, BUFFER_SIZE);
	ft_memmove(buf, tmp, ft_strl(tmp, 0));
	free(tmp);
	return (nextline);
}

char	*no_nl(char *nextline, int fd, char *buf, ssize_t rc)
{
	while (ft_strchr(buf, '\n') == NULL)
	{
		if (buf[0] != 0)
		{
			nextline = ft_strjoin(nextline, buf);
			ft_bzero(buf, BUFFER_SIZE);
		}
		rc = read(fd, buf, BUFFER_SIZE);
		if (rc == 0 && buf[0] == 0 && nextline[0] != 0)
		{
			return (nextline);
		}
		if (rc == 0 && buf[0] == 0)
		{
			free(nextline);
			return (NULL);
		}
		if (ft_strchr(buf, '\n') != NULL)
		{
			nextline = do_this(nextline, buf);
			return (nextline);
		}
	}
	return (NULL);
}

char	*find_nextline(int fd, char *nextline, char *tmp, ssize_t rc)
{
	static char	buf[BUFFER_SIZE + 1];

	if (ft_strchr(buf, '\n') == NULL)
	{
		nextline = no_nl(nextline, fd, buf, rc);
		if (!nextline)
			return (NULL);
		else
			return (nextline);
	}
	if (rc <= 1)
		free(nextline);
	nextline = ft_substr(buf, 0, ft_strl(buf, 1));
	tmp = ft_substr(buf, ft_strl(nextline, 1), BUFFER_SIZE);
	ft_bzero(buf, BUFFER_SIZE);
	ft_memmove(buf, tmp, BUFFER_SIZE);
	if (tmp)
		free(tmp);
	if (nextline)
		return (nextline);
	free (nextline);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*nextline;
	char		*tmp;
	ssize_t		rc;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = NULL;
	rc = 0;
	nextline = malloc(1);
	if (!nextline)
		return (0);
	nextline[0] = 0;
	nextline = find_nextline(fd, nextline, tmp, rc);
	if (nextline)
		return (nextline);
	free (nextline);
	return (NULL);
}
