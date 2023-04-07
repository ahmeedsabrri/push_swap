/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:43:03 by asabri            #+#    #+#             */
/*   Updated: 2023/04/07 01:00:31 by asabri           ###   ########.fr       */
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

//TODO : function  rotate and rrotate;

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
// rotation 
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
   ft_printf("ra\n");
}
void rr(t_list **a , t_list **b)
{
   rotation(a);
   rotation(b);
   ft_printf("rr\n");
}
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
    ft_printf("rra\n");
}
void rrb(t_list **b)
{
    rrotation(b);
    ft_printf("rra\n");
}
void rrr(t_list **a , t_list **b)
{
   rrotation(a);
   rrotation(b);
   ft_printf("rrr\n");
}
