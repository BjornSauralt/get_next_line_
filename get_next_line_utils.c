/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarsaul <mgarsaul@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-31 14:23:10 by mgarsaul          #+#    #+#             */
/*   Updated: 2024-10-31 14:23:10 by mgarsaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memalloc(size_t size)
{
	void	*new;
	size_t	i;

	new = (void *) malloc(size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(unsigned char *)(new + i) = 0;
		i++;
	}
	return (new);
}

void	*ft_calloc(size_t count, size_t size)
{
	if (size != 0 && count > ((size_t) -1 / size))
		return (NULL);
	return (ft_memalloc(count * size));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(
			sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

size_t	ft_strlen(const char *str)
{
	int	valeur;

	valeur = 0;
	while (str[valeur])
		valeur++;
	return (valeur);
}

char	*ft_strchr(const char *str, int car)
{
	int	valeur;

	valeur = 0;
	if ((char)car == '\0')
		return ((char *)str + ft_strlen(str));
	while (str[valeur] != '\0')
	{
		if (str[valeur] == (char)car)
			return ((char *)str + valeur);
		valeur++;
	}
	if (str[valeur] == (char) car)
		return ((char *) str + valeur);
	return (NULL);
}
