/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 19:40:37 by sunpark           #+#    #+#             */
/*   Updated: 2020/03/19 16:42:53 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"
#include "../includes/print_element.h"

int		get_digit_len(int n)
{
	return ((-10 < n && n < 10) ? 1 : 1 + get_digit_len(n / 10));
}

void	put_unint(unsigned int n, t_percent *p)
{
	if (n == 0 && p->precision == 0)
	{
		if (p->width)
			ft_putchar_fd(' ', 1);
		return ;
	}
	if (n >= 100000)
		put_unint(n / 100000, p);
	ft_putnbr_fd(n % 100000, 1);
}

int		sort_front(t_percent *p, int print, int len)
{
	if (p->sort && print < 0)
		ft_putchar_fd('-', 1);
	if (p->precision != -1)
		p->sort = 0;
	return (print_sort(p, len + ((print < 0) ? 1 : 0)));
}

int		print_int(t_percent *p, va_list ap)
{
	int len;
	int print;
	int result;

	print = va_arg(ap, int);
	p->sort = (p->sort == 1 && print < 0 && p->precision >= 0) ? 0 : p->sort;
	result = (print < 0) ? 1 : 0;
	len = get_digit_len(print);
	len = ((p->precision > len) ? p->precision : len);
	result += len;
	if (p->sort != 2)
		result += sort_front(p, print, len);
	if (p->sort != 1 && print < 0)
		ft_putchar_fd('-', 1);
	while (len > get_digit_len(print) && (len--))
		ft_putchar_fd('0', 1);
	put_unint((print < 0) ? -1 * print : print, p);
	len = ((p->precision > len) ? p->precision : len);
	if (p->sort == 2)
		result += print_sort(p, len + ((print < 0) ? 1 : 0));
	return (result - ((print || p->precision || p->width) ? 0 : 1));
}

int		print_unint(t_percent *p, va_list ap)
{
	unsigned int	print;
	int				result;
	int				dlen;
	int				len;

	print = va_arg(ap, unsigned int);
	dlen = (print >= 1000000000) ? 10 : get_digit_len(print);
	len = ((p->precision > dlen) ? p->precision : dlen);
	result = len;
	if (p->sort != 2)
	{
		if (p->precision != -1)
			p->sort = 0;
		result += print_sort(p, len);
	}
	while (len > dlen && (len--))
		ft_putchar_fd('0', 1);
	put_unint(print, p);
	len = ((p->precision > len) ? p->precision : len);
	if (p->sort == 2)
		result += print_sort(p, len);
	return (result - ((print || p->precision || p->width) ? 0 : 1));
}
