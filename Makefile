# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 22:04:16 by sunpark           #+#    #+#              #
#    Updated: 2020/03/14 17:49:59 by sunpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_printf.c take_percentage.c percent.c
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
			@$(MAKE) -C libft bonus
			$(GCC) $(GCCFLAG) -c $< -o $(<:.c=.o) -I$(INCDIR)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS) $(LIBFT)

all:		$(NAME)

clean:
			@$(MAKE) -C libft clean
			$(RM) $(OBJS)

fclean:		clean
			@$(MAKE) -C libft fclean
			$(RM) $(NAME)

.PHONY:		libft all clean fclean
