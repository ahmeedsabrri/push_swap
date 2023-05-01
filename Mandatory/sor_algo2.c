/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sor_algo2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 03:47:08 by asabri            #+#    #+#             */
/*   Updated: 2023/04/29 15:44:37 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mini_value(t_list *stack)
{
	int		min;
	t_list	*tmp;

	tmp = stack;
	min = tmp->content;
	while (tmp)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

static int	get_positon(t_list *stack, int elem)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->content == elem)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	sort_algo2(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		min;
	int		mid;
	int		pos;

	tmp = *stack_a;
	mid = ft_lstsize(*stack_a) / 2;
	while (ft_lstsize(*stack_a) > 3)
	{
		min = mini_value(*stack_a);
		pos = get_positon(*stack_a, min);
		if (min == (*stack_a)->content)
			pb(stack_b, stack_a);
		else if (pos > mid)
			rra(stack_a);
		else if (pos <= mid)
			ra(stack_a);
	}
	sort_algo1(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
