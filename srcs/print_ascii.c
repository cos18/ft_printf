/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 00:39:26 by sunpark           #+#    #+#             */
/*   Updated: 2020/03/17 23:19:21 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/print_element.h"

int	print_char(t_percent *p, va_list *ap)
{
	int		result;
	char	print;

	result = 0;
	if (p->sort != 2)
		result += print_sort(p, 1);
	print = (char)va_arg(*ap, int);
	ft_putchar_fd(print, 1);
	result += 1;
	if (p->sort == 2)
		result += print_sort(p, 1);
	return (result);
}

int	print_string(t_percent *p, va_list *ap)
{
	int		result;
	char	*print;
	int		p_len;
	int		cnt;

	result = 0;
	print = (char *)va_arg(*ap, char *);
	p_len = ft_strlen(print);
	p_len = (p_len > p->precision) ? p->precision : p_len;
	if (p->sort != 2)
		result += print_sort(p, p_len);
	cnt = -1;
	while (++cnt < p_len)
		ft_putchar_fd(print[cnt], 1);
	result += p_len;
	if (p->sort == 2)
		result += print_sort(p, p_len);
	return (result);
}
