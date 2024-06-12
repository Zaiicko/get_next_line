/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:33:12 by zaiicko           #+#    #+#             */
/*   Updated: 2024/06/12 19:43:53 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, len);
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(*str));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	return (str);
}

char	*ft_read_and_stack(int fd, char *stash)
{
	char	*buffer;
	ssize_t	read_bytes;
	char	*temp;

	if (!stash)
		stash = (char *)ft_calloc(1, 1);
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(buffer), NULL);
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
		if (ft_strrchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*ft_next_line(char *buffer)
{
	size_t	i;
	char	*line;
	char	*temp;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	else if (!buffer[i])
		i++;
	line = ft_substr(buffer, 0, i);
	if (!line)
		return (NULL);
	temp = ft_substr(buffer, i, ft_strlen(buffer) - i);
	if (!temp)
		return (free(line), NULL);
	ft_memcpy(buffer, temp, ft_strlen(temp) + 1);
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stash = ft_read_and_stack(fd, stash);
	if (!stash || *stash == '\0')
		return (free(stash), stash = NULL, NULL);
	line = ft_next_line(stash);
	if (!line)
		return (free(line), NULL);
	return (line);
}
