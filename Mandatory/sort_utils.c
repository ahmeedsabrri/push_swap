/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:26:48 by asabri            #+#    #+#             */
/*   Updated: 2023/05/03 18:52:11 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next_min(int min, t_list *stack)
{
	t_list	*tmp;
	int		i;
	int		next;

	tmp = stack;
	i = 0;
	next = max_value(stack);
	while (tmp)
	{
		if (tmp->content > min && tmp->content < next)
			next = tmp->content;
		tmp = tmp->next;
	}
	return (next);
}

void	ft_index(t_list **stack_a, int i, int min)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->content != min)
		tmp = tmp->next;
	tmp->index = i;
}

int	get_pos(t_list *stack, int val)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == val)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}

int	min_value(t_list *stack)
{
	int		min;

	min = 2147483647;
	while (stack)
	{
		if (min > stack->content)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}
