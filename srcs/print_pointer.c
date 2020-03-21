/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 22:35:33 by sunpark           #+#    #+#             */
/*   Updated: 2020/03/21 23:07:09 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"
#include "../includes/print_element.h"

int 				get_long_hex_len(unsigned long long print)
{
	return ((print < 16) ? 1 : 1 + get_long_hex_len(print / 16));
}

unsigned long long	long_hex_pow(int n)
{
	return ((n == 0) ? 1 : long_hex_pow(n - 1) * 16);
}

void				print_long_hex_num(unsigned long long print, t_percent *p)
{
	int		locate;
	int		minnum;

	if (print == 0 && p->precision == 0)
	{
		/*
		if (p->width)
			ft_putchar_fd(' ', 1);
		*/
		return ;
	}
	locate = get_long_hex_len(print);
	while (locate--)
	{
		minnum = print / long_hex_pow(locate) % 16;
		if (minnum < 10)
			ft_putchar_fd('0' + minnum, 1);
		else
			ft_putchar_fd('a' + minnum - 10, 1);
	}
}

int					print_pointer(t_percent *p, va_list ap)
{
	unsigned long long	print;
	int					result;
	int					len;
	int					dlen;

	print = va_arg(ap, unsigned long long);
	dlen = get_long_hex_len(print);
	len = ((p->precision > dlen) ? p->precision : dlen);
	if (!print && p->precision == 0)
	{
		len = 0;
		dlen = 0;
	}
	result = len + 2;
	if (p->sort != 2)
	{
		p->sort = 0;
		result += print_sort(p, len + 2);
	}
	ft_putstr_fd("0x", 1);
	while (len > dlen && (len--))
		ft_putchar_fd('0', 1);
	print_long_hex_num(print, p);
	len = ((p->precision > len) ? p->precision : len);
	if (p->sort == 2)
		result += print_sort(p, len + 2);
	return (result);
}
