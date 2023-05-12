/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:17:10 by asabri            #+#    #+#             */
/*   Updated: 2023/05/11 20:28:47 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotation(t_list **stack)
{
	t_list	*tmp;
	t_list	*head;

	if (!*stack)
		return ;
	if (ft_lstsize(*stack) < 2)
		return ;
	tmp = *stack;
	head = (*stack)->next;
	ft_lstadd_back(&tmp,*stack);
	(*stack)->next = 0;
	(*stack) = head;
}

void	ra(t_list **a)
{
	rotation(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotation(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotation(a);
	rotation(b);
	write(1, "rr\n", 3);
}
