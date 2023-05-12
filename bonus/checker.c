/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 01:27:50 by asabri            #+#    #+#             */
/*   Updated: 2023/05/11 20:33:45 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	exec_instarc1(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "pa"))
		return (push(stack_b, stack_a), 1);
	else if (!ft_strcmp(line, "pb"))
		return (push(stack_a, stack_b), 1);
	else if (!ft_strcmp(line, "rra"))
		return (rrotation(stack_a), 1);
	else if (!ft_strcmp(line, "rrb"))
		return (rrotation(stack_b), 1);
	else if (!ft_strcmp(line, "rrr"))
		return (rrotation(stack_a), rrotation(stack_b), 1);
	else
		return (0);
}

void	exec_instarc(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "sa"))
		swap(stack_a);
	else if (!ft_strcmp(line, "sb"))
		swap(stack_b);
	else if (!ft_strcmp(line, "ss"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (!ft_strcmp(line, "ra"))
		rotation(stack_a);
	else if (!ft_strcmp(line, "rb"))
		rotation(stack_b);
	else if (!ft_strcmp(line, "rr"))
	{
		rotation(stack_a);
		rotation(stack_b);
	}
	else if (!exec_instarc1(stack_a, stack_b, line))
		ft_error();
}

void	read_lines(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		exec_instarc(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc > 1)
	{
		stack_a = ft_parsing(&argc, argv);
		read_lines(&stack_a, &stack_b);
		if (if_sorted(stack_a) && !stack_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	ft_malloc(0, 2);
	return (0);
}
