/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:54:02 by sunpark           #+#    #+#             */
/*   Updated: 2020/03/13 19:35:46 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_percent	*create_percent(void)
{
	t_percent	*result;
	
	result = (t_percent *)malloc(sizeof(t_percent));
	if (result)
	{
		result->sort = 0;
		result->sign = 0;
		result->width = 0;
		result->precision = 0;
	}
	return (result);
}
