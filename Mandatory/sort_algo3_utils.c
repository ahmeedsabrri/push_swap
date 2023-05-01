/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo3_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:10:21 by asabri            #+#    #+#             */
/*   Updated: 2023/04/29 15:34:40 by asabri           ###   ########.fr       */
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
		while ((*stack)->index != index)
			rb(stack);
	}
	else
	{
		while ((*stack)->index != index)
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

int	get_pos_cont(t_list *stack, int val)
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

int	to_push(t_list *stack_b, int max, int next)
{
	int	pos_max;
	int	pos_next;
	int	size ;

	pos_max = get_pos_cont(stack_b, max);
	pos_next = get_pos_cont(stack_b, next);
	size = ft_lstsize(stack_b);
	if (pos_max > pos_next && pos_max <= (size / 2) && pos_next < (size / 2))
		return (1);
	if (pos_max < pos_next && pos_max > (size / 2) && pos_next > (size / 2))
		return (1);
	return (0);
}

void	push_stack_b(t_list **stack_b, t_list **stack_a)
{
	int		max;

	max = max_value(*stack_b);
	while (*stack_b)
	{
		if (to_push(*stack_b, max, get_next_max(max,*stack_b)))
		{
			move_to_top_b(stack_b,
				get_index_val(*stack_b, get_next_max(max, *stack_b)));
			pa(stack_a, stack_b);
			move_to_top_b(stack_b, get_index_val(*stack_b, max));
			pa(stack_a, stack_b);
			sa(stack_a);
		}
		else
			move_to_top_b(stack_b, get_index_val(*stack_b, max));
		if (ft_lstsize(*stack_b) == 1)
		{
			pa(stack_a, stack_b);
			return ;
		}
		pa(stack_a, stack_b);
		max = get_next_max(max,*stack_b);
	}
}
