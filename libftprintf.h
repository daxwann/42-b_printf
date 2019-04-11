/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 21:28:14 by xwang             #+#    #+#             */
/*   Updated: 2018/09/29 14:57:08 by xwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>

int	ft_putchar(int c);
int	ft_putstr(const char *s);
int	ft_putnb(int nb);
int	ft_putnb_base(unsigned long nb, unsigned long base);
int	b_printf(const char *format, ...);
int	conversion(va_list ap, char qualifier);

#endif
