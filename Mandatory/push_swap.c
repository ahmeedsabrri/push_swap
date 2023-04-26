/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 04:55:05 by asabri            #+#    #+#             */
/*   Updated: 2023/04/26 11:50:37 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char  *get_digits(char const *av, char *str )
{
    char *tmp;

    error_handler(av);
    tmp = ft_strjoin(str,av);
    free(str);
    return (tmp);
}

int *fill_stack(int *array_a, char *str , int* argc)
{
    char **mtr;
    int i;
    
    i = 0;
    mtr = ft_split(str,' ');
    while(mtr[i])
        i++;
    if (!array_a)
        array_a = (int *)malloc(i * sizeof(int));
    i = 0;
    while (mtr[i])
    {
        array_a[i] = ft_atoi(mtr[i]);
        free(mtr[i]);
        i++;
    }
    free(mtr);
    *argc = i;
    return (array_a);
}

int main(int argc, char const *argv[])
{
    int i;
    char *str;
    int *array_a;
    t_list *stack_a;
    t_list  *stack_b;
	
    str = (char *)malloc(1 * sizeof(char));
    *str = 0;
    i = 1;
    if (argc == 1)
        exit (1);
    else
    {
        while(i < argc)
            str = get_digits(argv[i++],str);
        array_a = fill_stack(array_a,str,&argc);
        if(has_duplicate(array_a,argc))
            ft_error();
        else if(if_sorted(array_a,argc))
            ft_error();
        stack_a = ArrayLinkedList(array_a,argc);
    }
    if (argc <= 3)
        sort_algo1(&stack_a);
    else if (argc <= 5)
        sort_algo2(&stack_a,&stack_b);
    else
        sort_algo3(&stack_a,&stack_b);
    return 0;
}
