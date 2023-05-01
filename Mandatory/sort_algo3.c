/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:20:18 by asabri            #+#    #+#             */
/*   Updated: 2023/05/01 15:33:04 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_min(t_list **stack)
{
	t_list	*tmp;
	int		i;
	int		min;
	int		next;

	tmp = (*stack);
	i = 0;
	min = min_value(*stack);
	ft_index(stack, i, min);
	while (tmp)
	{
		next = get_next_min(min, *stack);
		if (next == min)
			return ;
		ft_index(stack, ++i, next);
		min = next;
		tmp = tmp->next;
	}
}

void	move_to_top(t_list **stack, int index)
{
	int	size;
	int	pos;

	size = ft_lstsize(*stack);
	pos = get_pos(*stack, index);
	if (pos <= size / 2)
	{
		while ((*stack)->index != index)
			ra(stack);
	}
	else
	{
		while ((*stack)->index != index)
			rra(stack);
	}	
}

int	get_index_chunk(t_list *stack, int val)
{
	while (stack)
	{
		if (stack->index < val)
			return (stack->index);
		stack = stack->next;
	}
	return (-1);
}

void	check_size(int size, int *chunk, int *chunk_size, int *ch)
{
	if (size <= 150)
		*chunk = 20;
	else if (size <= 500)
		*chunk = 55;
	*chunk_size = *chunk / 2;
	*ch = *chunk;
}

void	sort_algo3(t_list **stack_a, t_list **stack_b)
{
	int	chunk;
	int	chunk_size;
	int	size;
	int	ch;

	index_min(stack_a);
	size = ft_lstsize(*stack_a);
	check_size(size, &chunk, &chunk_size, &ch);
	while (*stack_a)
	{
		while (get_index_chunk(*stack_a, chunk) != -1)
		{
			move_to_top(stack_a, get_index_chunk(*stack_a, chunk));
			if (get_index_chunk(*stack_a, chunk) > (chunk - chunk_size))
			{
				pb(stack_b, stack_a);
				rb(stack_b);
			}
			else
				pb(stack_b, stack_a);
		}
		chunk += ch;
	}
	push_stack_b(stack_b, stack_a);
}
