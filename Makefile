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

NAME = fillit.a

HEADER = fillit.h

SOURCE = *.c

ROOT = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(HEADER) $(SOURCE)
	ar rcs $(NAME) $(ROOT)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(HEADER).gch a.out

re: fclean all

main:
	gcc -Wall -Wextra -Werror main.c
