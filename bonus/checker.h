/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 01:28:15 by asabri            #+#    #+#             */
/*   Updated: 2023/05/11 20:22:34 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../Mandatory/push_swap.h"
# include "../Mandatory/libftmalloc/ft_malloc.h"
# include "./get_next_line.h"

int		ft_strcmp(const char *s1, const char *s2);
void	read_lines(t_list **stack_a, t_list **stack_b);
void	exec_instarc(t_list **stack_a, t_list **stack_b, char *line);
int		exec_instarc1(t_list **stack_a, t_list **stack_b, char *line);
#endif