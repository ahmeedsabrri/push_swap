/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:44:45 by asabri            #+#    #+#             */
/*   Updated: 2023/04/07 00:55:30 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int max_value(t_list *tmp)
{
    int max = tmp->content;
    tmp = tmp->next;
    while (tmp) {
        
        if (max < tmp->content)
            max = tmp->content;
        tmp = tmp->next;
    }
    return (max);
}
void sort_algo1(t_list **stack_a)
{
    int max;

    max = max_value(*stack_a);
    if(ft_lstsize(*stack_a) == 3)
    { 
        if ((*stack_a)->content == max)   
            ra(stack_a);
        else if ((*stack_a)->next->content == max)
            rra(stack_a);
    }
    if ((*stack_a)->content > (*stack_a)->next->content)
        sa(stack_a);
}