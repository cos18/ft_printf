/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:55:20 by sunpark           #+#    #+#             */
/*   Updated: 2020/03/14 18:47:35 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERCENT_H
# define PERCENT_H

typedef struct	s_percent
{
	int			sort;
	int			sign;
	int			width;
	int			precision;
}				t_percent;

t_percent	*create_percent(void);
void		set_sort(t_percent *p, char c);
void		set_sign(t_percent *p, char c);
void		clear_percent(t_percent *p);

#endif
