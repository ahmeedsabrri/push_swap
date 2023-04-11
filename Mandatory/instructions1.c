/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:43:03 by asabri            #+#    #+#             */
/*   Updated: 2023/04/11 08:18:33 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **stack)
{
    if((!stack && !*stack) || ft_lstsize(*stack) <= 2)
        return ;
    int tmp;
    
    tmp = (*stack)->content;
    (*stack)->content = (*stack)->next->content;
    (*stack)->next->content = tmp;
}

void sa(t_list **stack_a)
{
   swap(stack_a);
   ft_printf("sa\n");
}

void sb(t_list **stack_b)
{
   swap(stack_b);
   ft_printf("sb\n");
   
}

void ss(t_list **stack_b, t_list **stack_a)
{
   swap(stack_b);
   swap(stack_a);
   ft_printf("ss\n");
}
