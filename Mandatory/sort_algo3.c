/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:20:18 by asabri            #+#    #+#             */
/*   Updated: 2023/04/11 08:27:14 by asabri           ###   ########.fr       */
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
		stack = stack->next;
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
void move_to_top_b(t_list **stack, int index)
{
	int size;
	int pos;
	
	size = ft_lstsize(*stack);
	pos = get_pos(*stack,index);
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
/*------------------------------------------------------------------------*/
int get_index_val(t_list *stack,int val)
{
	if (!stack)
		return (-1);
	while (stack)
	{
		if (stack->content == val)
			return (stack->index);
		stack =stack->next;
	}
	return (-1);
}

static int get_next_max(int max, t_list *stack)
{
	t_list *tmp;
	int i;
	int next;

	tmp = stack;
	i = 0;
	next = min_value(stack);
	while(tmp)
	{
		if (tmp->content < max && tmp->content > next)
			next = tmp->content;
		tmp = tmp->next;
	}
	return (next);
}
int get_pos_cont(t_list *stack,int val)
{
	int i;

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
int to_push(t_list *stack_b , int max , int next)
{
	int pos_max;
	int pos_next;
	int size ;

	pos_max = get_pos_cont(stack_b,max);
	pos_next = get_pos_cont(stack_b,next);
	size = ft_lstsize(stack_b);
	if (pos_max > pos_next && pos_max <= (size / 2) && pos_next < (size / 2))
		return(1);
	if (pos_max < pos_next && pos_max > (size / 2) && pos_next > (size / 2))
		return (1);
	return (0);
}

void push_stack_b(t_list **stack_b ,t_list **stack_a)
{
	int max;
	max = max_value(*stack_b);
	t_list *tmp;
	tmp = *stack_b;
	while (*stack_b)
	{	
		
			if (to_push(*stack_b,max,get_next_max(max,*stack_b)))
			{
				move_to_top_b(stack_b,get_index_val(*stack_b ,get_next_max(max,*stack_b)));
				pa(stack_a, stack_b);
				move_to_top_b(stack_b,get_index_val(*stack_b ,max));
				pa(stack_a, stack_b);
				sa(stack_a);
			}else
				move_to_top_b(stack_b,get_index_val(*stack_b ,max));
			if (ft_lstsize(*stack_b) == 1)
			{
				pa(stack_a, stack_b);
				return ;
			}
			pa(stack_a, stack_b);
			max = get_next_max(max,*stack_b);
			
		}
		
}
void sort_algo3(t_list **stack_a, t_list **stack_b)
{
	int chunk;
	int size;
	int i;
	
	index_min(stack_a);
	size = ft_lstsize(*stack_a);
	if (size <= 150)
		chunk = 20;
	i = 0;
	while (*stack_a)
	{	
		while (get_index_chunk(*stack_a ,chunk) != -1)
			{
				move_to_top(stack_a,get_index_chunk(*stack_a ,chunk));
				if (get_index_chunk(*stack_a ,chunk) > (chunk - 10))
					{
						pb(stack_b, stack_a);
						rb(stack_b);
					}
				else
					pb(stack_b, stack_a);
			}
		chunk += 20;
	}
	push_stack_b(stack_b,stack_a);
}