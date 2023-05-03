/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utitls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:53:50 by asabri            #+#    #+#             */
/*   Updated: 2023/05/03 19:02:00 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstnew(int content)
{
	t_list		*new;
	static int	i;

	new = malloc(sizeof (t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst ->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		ptr = ft_lstlast(*(lst));
		ptr->next = new;
	}
}

t_list	*array_linkedlist(int *arr, int size)
{
	int		i;
	t_list	*stack;

	i = -1;
	stack = NULL;
	while (++i < size)
		ft_lstadd_back(&stack, ft_lstnew(arr[i]));
	return (stack);
}
