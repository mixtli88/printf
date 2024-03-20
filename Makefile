# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabril <mabril@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 16:49:43 by mabril            #+#    #+#              #
#    Updated: 2024/03/20 16:54:44 by mabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

RM = rm -f

SRCS = 	ft_memo.c	\
		ft_printf.c \
		ft_putchar.c \
		ft_puthexaup.c \
		ft_puthexatit.c	\
		ft_putnrb.c	\
		ft_putstr.c	\
		ft_unsigne.c \

OBJ = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	cc -Wall -Werror -Wextra -c $< -o $@ -I.

$(NAME): $(OBJ)
	@$(RM) $@
	ar rcs $@ $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all



