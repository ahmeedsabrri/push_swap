/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:17:10 by asabri            #+#    #+#             */
/*   Updated: 2023/04/11 08:18:00 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotation (t_list **stack)
{
    if (!*stack)
        return ;
    if (ft_lstsize(*stack) < 2)
        return ;
    t_list *tmp;
    t_list *head;
    tmp = *stack;
    head = (*stack)->next; 
    ft_lstadd_back(&tmp,*stack);
    (*stack)->next = 0;
    (*stack) = head;
}

void ra(t_list **a)
{
   rotation(a);
   ft_printf("ra\n");
}

void rb(t_list **b)
{
   rotation(b);
   ft_printf("rb\n");
}

void rr(t_list **a , t_list **b)
{
   rotation(a);
   rotation(b);
   ft_printf("rr\n");
}