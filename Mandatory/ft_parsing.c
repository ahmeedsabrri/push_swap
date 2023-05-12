/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:27:37 by asabri            #+#    #+#             */
/*   Updated: 2023/05/11 20:12:14 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_digits(char const *av, char *str )
{
	char	*tmp;

	error_handler(av);
	tmp = ft_strjoin(str, av);
	return (tmp);
}

int	*fill_stack(int *array_a, char *str, int *argc)
{
	char	**mtr;
	int		i;

	i = 0;
	mtr = ft_split(str, ' ');
	while (mtr[i])
		i++;
	array_a = (int *)ft_malloc(i * sizeof(int), 1);
	if (!array_a)
		return (ft_malloc(0, 0), NULL);
	i = 0;
	while (mtr[i])
	{
		array_a[i] = ft_atoi(mtr[i]);
		i++;
	}
	*argc = i;
	return (array_a);
}

t_list	*ft_parsing(int *argc, char **argv)
{
	char	*str;
	int		i;
	t_list	*stack_a;
	int		*array_a;

	str = (char *)ft_malloc(1 * sizeof(char), 1);
	*str = 0;
	i = 1;
	array_a = NULL;
	if (*argc == 1)
		exit (1);
	else
	{
		while (i < *argc)
			str = get_digits(argv[i++], str);
		array_a = fill_stack(array_a, str, argc);
		if (has_duplicate(array_a, *argc))
			ft_error();
		stack_a = array_linkedlist(array_a, *argc);
	}
	return (stack_a);
}
