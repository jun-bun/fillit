# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkotov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 18:07:57 by dkotov            #+#    #+#              #
#    Updated: 2018/06/29 18:10:33 by dkotov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft

HEADER = fillit.h

SOURCES = libft/*.c

OBJECTS = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c libft/$(LIB).h $(SOURCES)
	ar rcs libft/$(LIB).a $(OBJECTS)
	gcc -Wall -Wextra -Werror -o $(NAME) libft/$(LIB).a fillit.c

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

main:
	gcc -Wall -Wextra -Werror main.c
