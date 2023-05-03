/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:54:09 by asabri            #+#    #+#             */
/*   Updated: 2023/05/03 22:26:52 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_malloc.h"

t_malloc *newmalloc(void *data)
{
    t_malloc *n;

    n = malloc(sizeof(t_malloc));
    return(n->data = data, n->next = NULL, n);
}

void addfront(t_malloc **head, t_malloc *new)
{

    if(*head)
        new->next = *head;
    *head = new;
}

void listclear(t_malloc **head)
{
    if(!head)
        return;
    t_malloc *tmp;
    t_malloc *ptr;

    tmp = *head;
    while(tmp)
    {
        ptr = tmp;
        tmp = tmp->next;
        free(ptr->data);
        free(ptr);
    }
    *head = NULL;
}