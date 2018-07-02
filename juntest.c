// Do not add this to final git
#include "fillit.h"
#include <stdio.h>

void	ft_print_board(char **board)
{
	while (*board)
	{	ft_putstr(*board++);
		ft_putchar('\n');
	}
}

void	test_get_boundry()
{
	short	*boundry;

	t_list		*pieces;
	pieces = ft_lstnew("##\n##",  6);
	pieces->next = ft_lstnew("#\n#\n#\n#", 8);

	boundry = get_boundry_piece(pieces->content);
	while (*boundry)
	{
		printf("%hd ", *boundry);
		boundry++;
	}
	pieces = pieces->next;
	
	boundry = get_boundry_piece(pieces->content);
	while (*boundry)
	{
		printf("%hd ", *boundry);
		boundry++;
	}
}

int		main()
{
	t_list		*pieces;
	char		**board;

	pieces = ft_lstnew("##\n##\n",  6);
	pieces->next = ft_lstnew("#\n#\n#\n#\n", 8);
	write(1, pieces->content, pieces->content_size);
	pieces = pieces->next;
	write(1, pieces->content, pieces->content_size);
	ft_putchar('\n');
	board = make_board(4);
	ft_print_board(board);
	put_piece(pieces, &board);
	ft_print_board(board);
	test_get_boundry();
	return (0);
}
