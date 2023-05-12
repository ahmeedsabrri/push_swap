/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:03:03 by asabri            #+#    #+#             */
/*   Updated: 2023/05/08 17:52:22 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoinn(char const *s1, char const *s2);
size_t	ft_strlenn(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif
