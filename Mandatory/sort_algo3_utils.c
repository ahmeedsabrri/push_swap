/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo3_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:10:21 by asabri            #+#    #+#             */
/*   Updated: 2023/05/03 18:43:19 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top_b(t_list **stack, int index)
{
	int	size;
	int	pos;

	size = ft_lstsize(*stack);
	pos = get_pos(*stack, index);
	if (pos <= size / 2)
	{
		while ((*stack)->index != index && (*stack)->index != index - 1)
			rb(stack);
	}
	else
	{
		while ((*stack)->index != index && (*stack)->index != index - 1)
			rrb(stack);
	}	
}

int	get_index_val(t_list *stack, int val)
{
	if (!stack)
		return (-1);
	while (stack)
	{
		if (stack->content == val)
			return (stack->index);
		stack = stack->next;
	}
	return (-1);
}

void	push_stack_b(t_list **stack_b, t_list **stack_a)
{
	int		max;

	while (*stack_b)
	{
		max = max_value(*stack_b);
		move_to_top_b(stack_b, get_index_val(*stack_b, max));
		if ((*stack_b)->content != max_value(*stack_b))
		{
			pa(stack_a, stack_b);
			move_to_top_b(stack_b, get_index_val(*stack_b, max));
			pa(stack_a, stack_b);
			sa(stack_a);
		}
		else
			pa(stack_a, stack_b);
		if (ft_lstsize(*stack_b) == 1)
		{
			pa(stack_a, stack_b);
			return ;
		}
	}
}
