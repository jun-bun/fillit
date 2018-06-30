# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkotov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 18:07:57 by dkotov            #+#    #+#              #
#    Updated: 2018/06/30 14:05:21 by dkotov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft/libft

HEADER = fillit.h

LIB_SRC = libft/*.c

SRC = *.c

OBJECTS = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(LIB).h $(LIB_SRC) $(NAME).h fillit.c valid.c -g
	ar rcs $(NAME).a $(OBJECTS)
	gcc -Wall -Wextra -Werror -o $(NAME) $(NAME).a -g

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(NAME).a
	rm -f $(LIB).a $(LIB).h.gch $(HEADER).gch

re: fclean all

main:
	gcc -Wall -Wextra -Werror main.c
