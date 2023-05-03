/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:36:52 by asabri            #+#    #+#             */
/*   Updated: 2023/05/03 16:02:21 by asabri           ###   ########.fr       */
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

bool	if_sorted(t_list *stack)
{
	if (stack)
	{	
		while (stack->next)
		{
			if (stack->content > stack->next->content)
				return (false);
			stack = stack->next;
		}
	}
	return (true);
}

void	error_handler(char const *str)
{
	if (!(ft_only_space(str)))
		ft_error();
}
