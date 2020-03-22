/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 22:47:45 by sunpark           #+#    #+#             */
/*   Updated: 2020/03/22 14:30:12 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_element.h"

int	print_sort(t_percent *p, int len)
{
	int	print_times;

	if (p->width <= len)
		return (0);
	print_times = p->width - len;
	while (print_times--)
		ft_putchar_fd((p->sort == 1) ? '0' : ' ', 1);
	return (p->width - len);
}
