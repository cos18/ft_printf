/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:43:20 by sunpark           #+#    #+#             */
/*   Updated: 2020/03/06 17:52:33 by sunpark          ###   ########.fr       */
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
			c == 'u' || c == 'x' || c == 'X')
		return (3);
	return (0);
}

int	get_one_num(char **format)
{
	char	*now;
	int		count;

	now = *format;
	count = 0;
	while (*now && *now)
	*format = now;
	return (count);
}

int	get_args_num(char *format)
{
	int	result;

	result = 0;
	while (*format)
	{
		if (*format == '%')
			result += get_one_num(&format);
		format++;
	}
	return (result);
}
