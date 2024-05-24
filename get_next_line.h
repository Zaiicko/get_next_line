/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:33:14 by zaiicko           #+#    #+#             */
/*   Updated: 2024/05/24 17:36:19 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif