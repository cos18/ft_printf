/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:42:45 by sunpark           #+#    #+#             */
/*   Updated: 2020/03/04 17:42:03 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "macro.h"

/*
** s_form format
** conversion : 0 - cspdiuxX - 7
** flag : ?
*/

typedef struct	s_form
{
	char		*original;
	int			flag;
	int			width;
	int			precision;
	int			length;
	int			specifier;
}				t_form;

int		ft_printf(const char *format, ...);

#endif
