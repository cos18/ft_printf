# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 22:04:16 by sunpark           #+#    #+#              #
#    Updated: 2020/03/17 23:43:07 by sunpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_printf.c take_percentage.c percent.c print_ascii.c \
			print_element.c
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

clean:
			@$(MAKE) -C libft clean
			$(RM) $(OBJS)

fclean:		clean
			@$(MAKE) -C libft fclean
			$(RM) $(NAME)

.PHONY:		libft all clean fclean
