/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 04:55:05 by asabri            #+#    #+#             */
/*   Updated: 2023/05/11 20:10:56 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arg(int argc, t_list *stack_a, t_list *stack_b)
{
	if (argc <= 3)
		sort_algo1(&stack_a);
	else if (argc <= 5)
		sort_algo2(&stack_a, &stack_b);
	else
		sort_algo3(&stack_a, &stack_b);
	ft_malloc(0, 2);
}

int	main(int argc, char **argv)
{	
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = ft_parsing(&argc, argv);
	if (if_sorted(stack_a))
		return (ft_malloc(0, 2), 0);
	check_arg(argc, stack_a, stack_b);
	return (0);
}
