/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 04:47:23 by asabri            #+#    #+#             */
/*   Updated: 2023/04/26 11:46:46 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char *c)
{
	int i;

	i = 0;
	if (!*c)
		return (1);
	while (c[i])
	{
		if ((c[i] < '0' || c[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	if (ft_isdigit(str))
		ft_error();
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	res = res * sign;
	if (res > 2147483647 || res < -2147483648)
		ft_error();
	return (res);
}