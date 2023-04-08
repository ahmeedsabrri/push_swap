/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:20:18 by asabri            #+#    #+#             */
/*   Updated: 2023/04/08 07:12:38 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int min_value(t_list *stack)
{
	int min;
	t_list *tmp;

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
void	ft_index(t_list **stack_a, int i, int min)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->content != min)
		tmp = tmp->next;
	tmp->index = i;
	// ft_printf("content : %d index : %d\n",min,tmp->index);
}

static int get_next_min(int min, t_list *stack)
{
	t_list *tmp;
	int i;
	int next;

	tmp = stack;
	i = 0;
	next = max_value(stack);
	while(tmp)
	{
		if (tmp->content > min && tmp->content < next)
			next = tmp->content;
		tmp = tmp->next;
	}
	return (next);
}

void index_min(t_list **stack)
{
	t_list *tmp;
	int i;
	int min;
	int next;
	
	tmp = (*stack);
	i = 0;
	min = min_value(*stack);
	ft_index(stack,i,min);
	while (tmp)
	{
		next  = get_next_min(min,*stack);
		if (next == min)
			return ;
		ft_index(stack,++i,next);
		min = next;
		tmp = tmp->next;
	} 
}

int get_index_chunk(t_list *stack,int val)
{
	while (stack)
	{
		if (stack->index < val)
			return (stack->index);
		stack =stack->next;
	}
	return (-1);
}
int get_pos(t_list *stack,int val)
{
	int i;

	i = 0;
	while (stack)
	{
		if (stack->index == val)
			return (i);
		i++;
		stack =stack->next;
	}
	return (i);
}
void move_to_top(t_list **stack, int index)
{
	int size;
	int pos;

	size = ft_lstsize(*stack);
	pos = get_pos(*stack,index);
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
void sort_algo3(t_list **stack_a, t_list **stack_b)
{
	int chunk;
	int size;
	int i;
	t_list *tmp;
	
	index_min(stack_a);
	tmp = *stack_a;
	size = ft_lstsize(*stack_a);
	if (size <= 150)
		chunk = 20;
	i = 0;
	while (*stack_a)
	{	
		while (get_index_chunk(*stack_a ,chunk) != -1)
			{
				ft_printf("%d\n", (*stack_a)->index);
				move_to_top(stack_a,get_index_chunk(*stack_a ,chunk));
				pb(stack_b, stack_a);
			}
		chunk += 20;
	}
}