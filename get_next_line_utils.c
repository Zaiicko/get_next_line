/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:33:10 by zaiicko           #+#    #+#             */
/*   Updated: 2024/05/24 18:43:16 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;
	size_t	len;
	size_t	i;

	len = count * size;
	if (count != 0 && size != 0)
	{
		if ((len / count) != size)
			return (NULL);
	}
	i = 0;
	dest = (void *)malloc(count * size);
	if (!dest)
		return (NULL);
	while (i < len)
	{
		((unsigned char *)dest)[i] = 0;
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = (char *)ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	return (ft_memcpy(dest, s1, ft_strlen(s1) + 1));
}
