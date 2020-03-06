# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 22:04:16 by sunpark           #+#    #+#              #
#    Updated: 2020/03/05 20:33:22 by sunpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_printf.c
SRCDIR	= ./srcs/
INCDIR	= includes

SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a
LIBFT	= libft/libft.a

GCC		= gcc
GCCFLAG	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:		
			make -C libft
			$(GCC) $(GCCFLAG) -c $< -o $(<:.c=.o) $(LIBFT) -I$(INCDIR)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

.PHONY:		libft all clean fclean
