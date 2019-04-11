/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 11:52:13 by xwang             #+#    #+#             */
/*   Updated: 2018/09/26 17:43:42 by xwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

int	conversion(va_list ap, char qualifier)
{
	int len;

	len = 0;
	if (qualifier == 's')
		len = ft_putstr(va_arg(ap, char *));
	else if (qualifier == 'c')
		len = ft_putchar(va_arg(ap, int));
	else if (qualifier == 'd' || qualifier == 'i')
		len = ft_putnb(va_arg(ap, int));
	else if (qualifier == 'u')
		len = ft_putnb_base(va_arg(ap, unsigned int), 10);
	else if (qualifier == 'p')
		len = ft_putstr("0x") + ft_putnb_base(va_arg(ap, unsigned long), 16);
	else if (qualifier == 'o')
		len = ft_putnb_base(va_arg(ap, unsigned int), 8);
	else if (qualifier == 'x')
		len = ft_putnb_base(va_arg(ap, unsigned int), 16);
	else
		len = ft_putchar(qualifier);
	return (len);
}

int	b_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	va_start(ap, format);
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
			count += ft_putchar(format[i]);
		else if (format[i + 1] != '\0')
		{
			count += conversion(ap, format[i + 1]);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
