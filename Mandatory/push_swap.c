/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 04:55:05 by asabri            #+#    #+#             */
/*   Updated: 2023/04/07 05:23:13 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char  *get_digits(char const *str1, char *str2 )
{
    char *tmp;

    tmp = ft_strjoin(str2,str1);
    tmp = ft_strjoin(tmp, " ");
    free(str2);
    return (tmp);
}
int has_duplicate(int *array_a, int size) {
    int i;
    int j;

    i = 0;
    while (i < size - 1) {
        j = i + 1;
        while (j < size) {
            if (array_a[i] == array_a[j]) {
                free (array_a);
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
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
        error_handler(mtr[i]);
        array_a[i] = ft_atoi(mtr[i]);
        free(mtr[i]);
        i++;
    }
    free(mtr);
    *argc = i;
    return (array_a);
}

int only_numbers (char const *str)
{
    int	i;
    int count_neg;
    int count_pos;
    int caracter;

	i = 0;
    count_neg = 0;
    count_pos = 0;
    caracter = 0;
    while (str[i])
	{
        if (str[i] == '-')
        {
		    count_neg++;
        }
        else if (str[i] == '+')
        {

            count_pos++;
        }
        else if ((str[i] > '9' || str[i] < '0') && (str[i] != 32 || str[i] != '+' || str[i] != '-'))
        {
            caracter++;
        }
		i++;
	}
    i = 0;
	while (str[i])
	{
		if ((count_neg >= 2 || count_pos >= 2) || (count_neg >= 1 && count_pos >= 1) || caracter >= 1)
        {
            
			return (0);
        }
		i++;
	}
	return (1);
}

int ft_only_space(const char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == ' ')
            i++;
        else
            return (1);
    }
    return (0);
}

void error_handler(char const *str)
{
    if(!(only_numbers(str)))
    {
        ft_printf("Error_onlyunumbr");
        exit (1);
    }
    if (!(ft_only_space(str)))
    {
        ft_printf("Error_onlyspace");
        exit (1);
    } 
}

int main(int argc, char const *argv[])
{
    int i;
    char *str;
    int *array_a;
    t_list *stack_a;
    t_list  *stack_b;
    
    i = 1;
    if (!str)
        str = (char *)malloc(1 * sizeof(char));
    if(argc <= 1)
        exit(0);
    else
    {
        while(i < argc)
            str = get_digits(argv[i++],str);    
        array_a = fill_stack(array_a,str,&argc);
        if(has_duplicate(array_a,argc))
        {
            ft_printf("Error_has_duplicate");
            exit (1);
        }
        stack_a = ArrayLinkedList(array_a,argc);
    }
    sort_algo3(&stack_a, &stack_b);
    return 0;
}
