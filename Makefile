# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkuma <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/11 11:58:27 by gkuma             #+#    #+#              #
#    Updated: 2016/06/08 15:50:20 by gkuma            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a

NFLAGS = /nfs/2014/g/gkuma/.brew/Cellar/nasm/2.12.01/bin/nasm -f macho64

LFLAGS = -rsc

SRCSDIR = src/

SRC = ft_bzero.s ft_strcat.s ft_isascii.s ft_isalpha.s\
ft_isdigit.s ft_isalnum.s ft_isprint.s ft_toupper.s\
ft_tolower.s ft_puts.s ft_memset.s ft_memcpy.s\
ft_strdup.s ft_cat.s ft_putstr.s ft_strlen.s ft_memalloc.s\
ft_memchr.s ft_strcmp.s ft_strncmp.s

BONUS = ft_putstr.s ft_bzero.s\
ft_tolower.s ft_strlen.s ft_puts.s ft_memset.s ft_memcpy.s\
ft_strdup.s ft_memalloc.s ft_memchr.s ft_strcmp.s ft_strncmp.s

SRCLST = $(addprefix $(SRCSDIR),$(SRC))

BONUSLST = $(addprefix $(SRCSDIR),$(BONUS))

OBJ = $(SRCLST:.s=.o)

OBJB = $(BONUSLST:.s=.o)

all: $(NAME)

$(NAME):$(OBJ)
	ar $(LFLAGS) $(NAME) $(OBJ)

$(SRCDIR)%.o: $(SRCDIR)%.s
	$(NFLAGS) -o $@ $< 

main:
	gcc -Wall -Wextra -Werror main.c $(OBJ)

bonus:
	gcc -Wall -Wextra -Werror bonus.c $(OBJB)

main2:
	gcc -Wall -Wextra -Werror main2.c $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
