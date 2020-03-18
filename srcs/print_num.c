/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 19:40:37 by sunpark           #+#    #+#             */
/*   Updated: 2020/03/18 21:15:03 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/print_element.h"

int		get_digit_len(int n)
{
	return ((-10 < n && n < 10) ? 1 : 1 + get_digit_len(n / 10));
}

void	put_unint(unsigned int n)
{
	if (n >= 100000)
		put_unint(n / 100000);
	ft_putnbr_fd(n % 100000, 1);
}

int		print_int(t_percent *p, va_list ap)
{
	int len;
	int print;
	int result;
	
	print = va_arg(ap, int);
	p->sort = (p->sort == 1 && print < 0) ? 0 : p->sort;
	result = (print < 0) ? 1 : 0;
	len = get_digit_len(print);
	len = ((p->precision > len) ? p->precision : len);
	if (p->sort != 2)
		result += print_sort(p, len + ((print < 0) ? 1 : 0));
	if (print < 0)
		ft_putchar_fd('-', 1);
	while (len > get_digit_len(print) && (len--))
		ft_putchar_fd('0', 1);
	put_unint((print < 0) ? -1 * print : print);
	len = ((p->precision > len) ? p->precision : len);
	if (p->sort == 2)
		result += print_sort(p, len + ((print < 0) ? 1 : 0));
	return (result);
}
