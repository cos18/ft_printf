# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 22:04:16 by sunpark           #+#    #+#              #
#    Updated: 2020/03/02 22:30:17 by sunpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

GCC		= gcc
GCCFLAG	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:
			$(GCC) $(GCCFLAG) -c $< -o $(<:.c=.o)

$(NAME)

all:		$(NAME)

clean

fclean:		clean
			$(RM) $(NAME)
