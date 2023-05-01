/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:43:03 by asabri            #+#    #+#             */
/*   Updated: 2023/04/29 15:38:42 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	int	tmp;

	tmp = (*stack)->content;
	if ((!stack && !*stack) || ft_lstsize(*stack) <= 2)
		return ;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_b, t_list **stack_a)
{
	swap(stack_b);
	swap(stack_a);
	write(1, "ss\n", 3);
}
