/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:17:04 by asabri            #+#    #+#             */
/*   Updated: 2023/04/11 08:17:37 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_list **src, t_list **dst)
{
    if(!*src)
        return ;
    t_list *tmp;

    tmp = *src;
    *src = (*src)->next;
    tmp->next = 0;
    if(*dst)
        tmp->next = *dst;
    *dst = tmp;
}

void pa(t_list **a , t_list **b)
{
   push(b, a);
   ft_printf("pa\n");
}

void pb(t_list **b , t_list **a)
{
   push(a, b);
   ft_printf("pb\n");
}