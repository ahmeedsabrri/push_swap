/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:43:03 by asabri            #+#    #+#             */
/*   Updated: 2023/04/06 00:45:44 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_list **stack_a)
{
    t_list *tmp;
    t_list *tmp2;

    tmp = *stack_a;
    ft_printf("sa");
    if (ft_lstsize(*stack_a) > 2)
    {
        tmp2 = (*stack_a)->next->next;
        (*stack_a) = (*stack_a)->next;
        tmp = tmp2->next;
        (*stack_a) = tmp->next;
    }
    else
    {
        (*stack_a) = (*stack_a)->next;
        (*stack_a) = tmp->next;
        tmp->next = NULL;
    }
    ft_printf("sa");
}
// void sb(int *stack_a , int *stack_b)
// {
   
// }
// void ss(int *stack_a , int *stack_b)
// {
   
// }
// void pa(int *stack_a , int *stack_b)
// {
   
// }
// void pb(int *stack_b)
// {
   
// }
// void ra(int *stack_a , int *stack_b)
// {
   
// }
// void rb(int *stack_a , int *stack_b)
// {
   
// }
// void rr(int *stack_a , int *stack_b)
// {
   
// }
// void rra(int *stack_a , int *stack_b)
// {
   
// }
// void rrb(int *stack_a , int *stack_b)
// {
   
// }
// void rrr(int *stack_a , int *stack_b)
// {
   
// }
