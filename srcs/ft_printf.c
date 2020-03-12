/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:48:45 by sunpark           #+#    #+#             */
/*   Updated: 2020/03/12 21:31:48 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	args_list;
	int		printed;

	va_start(args_list, format);
	printed = 0;
	while (*format)
	{
		if(*format == '%')
	}
	va_end(args_list);
	return (0);
}
