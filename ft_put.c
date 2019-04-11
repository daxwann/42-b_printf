/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 21:33:35 by xwang             #+#    #+#             */
/*   Updated: 2018/09/29 13:03:20 by xwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *s)
{
	int i;

	i = 0;
	if (s == 0)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnb_base(unsigned long nb, unsigned long base)
{
	int	count;

	count = 0;
	if (nb / base != 0)
		count += ft_putnb_base(nb / base, base);
	if (nb % base < 10)
		count += ft_putchar(nb % base + '0');
	else
		count += ft_putchar(nb % base - 10 + 'a');
	return (count);
}

int	ft_putnb(int nb)
{
	int				count;
	unsigned int	unum;

	count = 0;
	if (nb < 0)
	{
		unum = (unsigned int)(-nb);
		count += ft_putchar('-');
		count += ft_putnb_base(unum, 10);
	}
	else
	{
		if (nb / 10 != 0)
			count += ft_putnb(nb / 10);
		count += ft_putchar(nb % 10 + '0');
	}
	return (count);
}
