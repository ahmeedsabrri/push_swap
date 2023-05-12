/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:18:05 by asabri            #+#    #+#             */
/*   Updated: 2023/05/11 19:03:49 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	checkstr(unsigned int *end, unsigned int *start,
char const *s, char c)
{
	while (s[*start] == c && s[*start] != 0)
		*start += 1;
	*end = *start;
	while (s[*end] != c && s[*end] != 0)
		*end += 1;
}

static unsigned int	getnb(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char			**p;
	char			*r;
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = 0;
	p = ft_malloc(sizeof(char *) * (getnb(s, c) + 1), 1);
	if (!p)
		return (NULL);
	r = (char *)s;
	i = 0;
	while (i < getnb(s, c))
	{
		checkstr(&end, &start, r, c);
		p[i] = ft_substr(s, start, end - start);
		if (p[i] == NULL)
			return (NULL);
		start = end;
		i++;
	}
	p[i] = 0;
	return (p);
}
