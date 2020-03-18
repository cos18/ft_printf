/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:54:02 by sunpark           #+#    #+#             */
/*   Updated: 2020/03/18 16:49:40 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

t_percent	*create_percent(void)
{
	t_percent	*result;

	result = (t_percent *)malloc(sizeof(t_percent));
	if (result)
		clear_percent(result);
	return (result);
}

void		set_sort(t_percent *p, char c)
{
	if (c == '-')
		p->sort = 2;
	else if (c == '0' && p->sort != 2)
		p->sort = 1;
}

void		set_sign(t_percent *p, char c)
{
	if (c == '+')
		p->sort = 2;
	else if (c == ' ' && p->sort != 2)
		p->sort = 1;
}

void		clear_percent(t_percent *p)
{
	p->sort = 0;
	p->sign = 0;
	p->width = 0;
	p->precision = -1;
}
