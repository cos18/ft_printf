/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_element.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 00:16:27 by sunpark           #+#    #+#             */
/*   Updated: 2020/03/15 00:23:58 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ELEMENT_H
# define PRINT_ELEMENT_H

# include <stdarg.h>
# include "libft.h"
# include "percent.h"

int	print_char(t_percent *p, va_list *ap);
int	print_string(t_percent *p, va_list *ap);
int	print_int(t_percent *p, va_list *ap);
int print_unint(t_percent *p, va_list *ap);
int print_pointer(t_percent *p, va_list *ap);
int print_hex(t_percent *p, va_list *ap, int is_upper);

#endif
