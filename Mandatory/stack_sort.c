/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:14:35 by asabri            #+#    #+#             */
/*   Updated: 2023/04/03 05:30:09 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(int *a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int *in_tmp(int *stk_a , int size)
{
    int i;
    int *tmp;
    
    i = 0;
    if (!tmp)
        tmp = (int *)malloc(sizeof(int) * size);
    
    while (i < size)
    {
        tmp[i] = stk_a[i];
        i++;
    }
    return (tmp);
}

void printArray(int *arr, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
    ft_printf("HNA AWLD LKHCHBA\n");
        printf("%d\n", arr[i]);
        i++;
    }   
}

void in_order(int *stk_a , int size)
{
    int i;
    int j;
    int temp;
    int *tmp;
    
    i = 0;
    j = 1;
    i = 0;
    tmp = in_tmp(stk_a,size);
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (tmp[j] < tmp[i])
            {
                swap(&tmp[j],&tmp[i]);
            }
            j++;
        }
        i++;
    }
    printArray(tmp,size);
}
