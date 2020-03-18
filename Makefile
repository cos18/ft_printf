# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 22:04:16 by sunpark           #+#    #+#              #
#    Updated: 2020/03/18 21:03:32 by sunpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_printf.c take_percentage.c percent.c print_ascii.c \
			print_element.c print_num.c
SRCDIR	= ./srcs/
INCDIR	= includes

SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a

GCC		= gcc
GCCFLAG	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:		
			$(GCC) $(GCCFLAG) -c $< -o $(<:.c=.o) -I$(INCDIR)

$(NAME):	$(OBJS)
			@$(MAKE) -C libft/ bonus
			@cp libft/libft.a libftprintf.a
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

test:		$(OBJS)
			@$(MAKE) -C libft/ bonus
			$(GCC) $(GCCFLAG) -c test.c -o test.o -I$(INCDIR)
			$(GCC) $(GCCFLAG) -g -o ptest libft/libft.a test.o $(OBJS)

clean:
			@$(MAKE) -C libft clean
			$(RM) $(OBJS) test.o

fclean:		clean
			@$(MAKE) -C libft fclean
			$(RM) $(NAME)

.PHONY:		libft all clean fclean
