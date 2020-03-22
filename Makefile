# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 22:04:16 by sunpark           #+#    #+#              #
#    Updated: 2020/03/22 15:36:33 by sunpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_printf.c take_percentage.c percent.c print_ascii.c \
			print_element.c print_num.c print_hex.c print_pointer.c
BSRC	= ft_printf_bonus.c take_percentage_bonus.c percent.c print_ascii.c \
			print_element.c print_num.c print_hex.c print_pointer.c
SRCDIR	= ./srcs/
INCDIR	= includes

SRCS	= $(addprefix $(SRCDIR), $(SRC))
BSRCS	= $(addprefix $(SRCDIR), $(BSRC))
OBJS	= $(SRCS:.c=.o)
BOBJS	= $(BSRCS:.c=.o)

NAME	= libftprintf.a

GCC		= gcc
GCCFLAG	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:		
			$(GCC) $(GCCFLAG) -c $< -o $(<:.c=.o) -I$(INCDIR)

$(NAME):	$(OBJS)
			@$(MAKE) -C libft/ bonus
			@cp libft/libft.a $(NAME)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

bonus:		$(BOBJS)
			@$(MAKE) -C libft/ bonus
			@cp libft/libft.a $(NAME)
			ar rc $(NAME) $(BOBJS)

test:		$(OBJS)
			@$(MAKE) -C libft/ bonus
			$(GCC) $(GCCFLAG) -c test.c -o test.o -I$(INCDIR)
			$(GCC) $(GCCFLAG) -g -o ptest libft/libft.a test.o $(OBJS)

clean:
			@$(MAKE) -C libft clean
			$(RM) $(BOBJS) test.o

fclean:		clean
			@$(MAKE) -C libft fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		libft all clean fclean re bonus
