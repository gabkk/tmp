# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkuma <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/11 11:58:27 by gkuma             #+#    #+#              #
#    Updated: 2015/01/09 01:30:51 by gkuma            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

CFLAGS = -Wall -Wextra -Werror -c

LFLAGS = -L libft -lft -lncurses

INC = -I includes/ -I libft/includes

SRCSDIR = src/

SRCS = main.c init.c first.c


OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(INC) -o  $(NAME) $(OBJ) $(LFLAGS)

$(OBJ): $(addprefix $(SRCSDIR),$(SRCS))
	make -C libft/
	gcc $(CFLAGS) $(INC) $(addprefix $(SRCSDIR),$(SRCS)) $(LFLAGGS)

norme:

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
