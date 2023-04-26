/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:18:37 by asabri            #+#    #+#             */
/*   Updated: 2023/04/26 10:50:19 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rrotation(t_list **stack)
{
    if (!*stack)
        return ;
    
    if (ft_lstsize(*stack) < 2)
        return ;
    t_list *tmp;
    t_list *tmp2;
    tmp = *stack;
    while (tmp->next->next)
        tmp = tmp->next;
    tmp2 = tmp->next;
    
    tmp->next = 0;
    ft_lstadd_front(stack,tmp2);
}

void rra(t_list **a)
{
    rrotation(a);
    write(1,"rra\n",4);
}
void rrb(t_list **b)
{
    rrotation(b);
    write(1,"rrb\n",4);
}
void rrr(t_list **a , t_list **b)
{
   rrotation(a);
   rrotation(b);
   write(1,"rrr\n",4);
}
