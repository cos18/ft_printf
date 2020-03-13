/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_percentage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:43:20 by sunpark           #+#    #+#             */
/*   Updated: 2020/03/13 18:54:33 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	is_conversion_or_flag(char c)
{
	if (c == '-' || c == '0')
		return (1);
	if (c == '*')
		return (2);
	if (c == '.')
		return (3);
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
			c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (4);
	return (0);
}

int	print_percent(const char **format, va_list *args_list)
{
	int status;
	int printed;

	printed = 0;
	status = 1;
	while (status)
	{
		if (status > is_conversion_or_flag(**format))
			break;
	}
	return (printed);
}
