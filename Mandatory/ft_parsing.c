/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:27:37 by asabri            #+#    #+#             */
/*   Updated: 2023/05/07 15:44:51 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_parsing(int argc,char **argv)
{
    char *str;
    int i;
    t_list *stack_a;
    int		*array_a;
    
    str = (char *)ft_malloc(1 * sizeof(char),1);
	*str = 0;
	i = 1;
	if (argc == 1)
		exit (1);
	else
	{
		while (i < argc)
			str = get_digits(argv[i++], str);
		array_a = fill_stack(array_a, str, &argc);
		if (has_duplicate(array_a, argc))
			ft_error();
		stack_a = array_linkedlist(array_a, argc);
	}
    return (stack_a);
}