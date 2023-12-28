/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:14:37 by yaolivei          #+#    #+#             */
/*   Updated: 2023/12/05 18:06:51 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	cont;

	cont = 0;
	if (!s)
		return (cont);
	while (s[cont] != '\0')
	{
		cont++;
	}
	return (cont);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;

	i = -1;
	if (!s2)
		return (NULL);
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (free(s1), NULL);
	if (s1)
	{
		while (s1[++i])
			ptr[i] = s1[i];
	}
	else
		i++;
	while (*s2)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	if (s1)
		free(s1);
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	j = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (j + 1));
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	i = 0;
	while (i < j + 1)
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	cont;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	cont = 0;
	while (cont < len && s[start] != '\0')
	{
		ptr[cont] = s[start];
		cont++;
		start++;
	}
	ptr[cont] = '\0';
	return (ptr);
}
