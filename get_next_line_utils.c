/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:39:19 by Loui :)           #+#    #+#             */
/*   Updated: 2021/12/22 23:22:26 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*newstring;

	i = 0;
	j = 0;
	newstring = (char *)malloc((ft_strl(s1, 0) + ft_strl(s2, 0) + 1));
	if (!newstring)
		return (NULL);
	while (s1[i] != '\0')
	{
		newstring[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		newstring[j] = s2[i];
		j++;
		i++;
	}
	newstring[j] = '\0';
	free(s1);
	return (newstring);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*m_dst;
	unsigned char	*m_src;

	m_dst = (unsigned char *) dst;
	m_src = (unsigned char *) src;
	if ((size_t)(m_dst - m_src) < n)
	{
		while (n--)
			*(m_dst + n) = *(m_src + n);
	}
	else
	{
		while (n--)
			*m_dst++ = *m_src++;
	}
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		*ptr++ = 0;
		i++;
	}
}

char	*ft_strchr(const char *string, int c)
{
	char	*ptr;

	ptr = (char *)string;
	c = (char)c;
	while (*ptr != '\0')
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	if (*ptr == c)
		return (ptr);
	return (NULL);
}
