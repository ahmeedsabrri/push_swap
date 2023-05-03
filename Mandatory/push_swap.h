/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 04:55:34 by asabri            #+#    #+#             */
/*   Updated: 2023/05/03 22:13:45 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>
# include "libftmalloc/ft_malloc.h"

typedef struct s_list
{
	int				content;
	int				index;
	int				lis;
	int				sub_index;
	struct s_list	*next;
}				t_list;


size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		ft_atoi(char *str);
int		ft_only_space(const char *str);

int		has_duplicate(int *array_a, int size);
bool	if_sorted(t_list *stack);
int		ft_lstsize(t_list *list);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*arraylinkedList(char **arr);
void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_b, t_list **stack_a);
void	push(t_list **src, t_list **dst);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	rotation(t_list **stack);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rrotation(t_list **stack);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
int		max_value(t_list *tmp);
t_list	*check_argv(char const **argv);
char	*ft_strchr(const char *s, int c);
void	error_handler(char const *str);
t_list	*array_linkedlist(int *arr, int size);
void	sort_algo1(t_list **stack_a);
void	sort_algo2(t_list **stack_a, t_list **stack_b);
void	sort_algo3(t_list **stack_a, t_list **stack_b);
void	index_min(t_list **stack);
void	ft_error(void);

int		get_next_min(int min, t_list *stack);
void	ft_index(t_list **stack_a, int i, int min);
int		get_pos(t_list *stack, int val);
int		min_value(t_list *stack);
int		get_next_max(int max, t_list *stack);
void	push_stack_b(t_list **stack_b, t_list **stack_a);
#endif