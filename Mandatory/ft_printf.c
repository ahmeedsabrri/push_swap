/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:43:54 by asabri            #+#    #+#             */
/*   Updated: 2023/03/29 04:31:10 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_format(va_list args, const char c)
{
	int		len;
	char	*nb;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == '%')
		len += ft_percent();
	else if (c == 'd')
	{
		nb = ft_itoa(va_arg(args, int));
		len += ft_putstr(nb);
	}
	else if (c == 's')
		len += ft_putstr(va_arg(args ,const char *));
	else
		len += ft_putchar(c);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		lenght;

	i = 0;
	lenght = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			lenght += ft_format(args, format[i + 1]);
			i++;
		}
		else
			lenght += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (lenght);
}
