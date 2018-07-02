# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwong <juwong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 18:07:57 by dkotov            #+#    #+#              #
#    Updated: 2018/07/01 16:28:44 by juwong           ###   ########.fr        #
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

juntest:
	gcc -Wall -Wextra -Werror -c $(LIB).h $(LIB_SRC) $(NAME).h juntest.c valid.c board.c -g
	ar rcs $(NAME).a $(OBJECTS)
	gcc -Wall -Wextra -Werror -o juntest $(NAME).a -g
