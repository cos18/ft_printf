/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_percentage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:43:20 by sunpark           #+#    #+#             */
/*   Updated: 2020/03/12 21:35:25 by sunpark          ###   ########.fr       */
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
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
			c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (3);
	return (0);
}

int	get_one_num(char **format)
{
	char	*now;
	int		count;
	int		tot_num;
	int		now_num;

	now = *format + 1;
	count = 0;
	tot_num = 0;
	while (*now)
	{
		now_num = is_conversion_or_flag(*now);
		
	}
	*format = now;
	return (count);
}

int	print_percentage(char **format, va_list args_list, int *printed)
{
	int	result;

	result = 0;
	while (*format)
	{
		if (*format == '%')
			result += get_one_num(format);
		format++;
	}
	return (result);
}
