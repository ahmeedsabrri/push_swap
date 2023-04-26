/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:36:52 by asabri            #+#    #+#             */
/*   Updated: 2023/04/26 11:34:02 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_only_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}


int	has_duplicate(int *array_a, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (array_a[i] == array_a[j])
			{
				free (array_a);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	if_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	if (size == 1)
		return (0);
	while (i < size)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	error_handler(char const *str)
{
	if (!(ft_only_space(str)))
		ft_error();
}
