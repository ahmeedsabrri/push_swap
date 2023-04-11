/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:36:52 by asabri            #+#    #+#             */
/*   Updated: 2023/04/11 09:05:58 by asabri           ###   ########.fr       */
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

void	error_handler(char const *str)
{
	if (!(only_numbers(str)))
	{
		ft_printf("Error");
		exit (1);
	}
	if (!(ft_only_space(str)))
	{
		ft_printf("Error");
		exit (1);
	}
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
	while (i < size)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	only_numbers(char const *str)
{
	int	i;
	int	count_neg;
	int	count_pos;
	int	caracter;

	i = 0;
	count_neg = 0;
	count_pos = 0;
	caracter = 0;
	while (str[i])
	{
		if (str[i] == '-')
			count_neg++;
		else if (str[i] == '+')
			count_pos++;
		else if ((str[i] > '9' || str[i] < '0') 
			&& (str[i] != 32 || str[i] != '+' || str[i] != '-'))
			caracter++;
		i++;
	}
	if ((count_neg >= 2 || count_pos >= 2) 
		|| (count_neg >= 1 && count_pos >= 1) || caracter >= 1)
		return (0);
	return (1);
}
