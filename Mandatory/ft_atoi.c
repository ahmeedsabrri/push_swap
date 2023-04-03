/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 04:47:23 by asabri            #+#    #+#             */
/*   Updated: 2023/04/03 01:16:26 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	long	res;
	int	sign;
	
	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
	{
		if (*(str+ 1) < '0' || *(str+ 1) > '9')
		{
			ft_printf("error");
			exit (1);
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	// if (*str == ' ' || *str == '-' || *str == '+')
	// {
	// 	ft_printf("Errorxx");
	// 	exit (1);
	// }
	res = res * sign;
	if (res > 2147483647 || res < -2147483648)
	{
		ft_printf("Error ds");
		exit (1);
	}
	return (res);
}