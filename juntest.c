// Do not add this to final git
#include "fillit.h"

void	ft_print_board(char **board)
{
	if(!board)
		ft_putstr("Fuck this shit");
	while (*board)
	{	ft_putstr(*board++);
		ft_putchar('\n');
	}
}

void	test_get_boundry()
{
	int		*boundry;

	t_list		*pieces;
	pieces = ft_lstnew("#..\n###",  6);
	pieces->next = ft_lstnew("#\n#\n#\n#", 8);

	boundry = get_boundry_piece(pieces->content);
	while (*boundry)
	{
		ft_putnbr(*boundry);
		boundry++;
		ft_putchar('\n');
	}
	pieces = pieces->next;
	
	boundry = get_boundry_piece(pieces->content);
	while (*boundry)
	{
		ft_putnbr(*boundry);
		boundry++;
		ft_putchar('\n');
	}
}

int		main()
{
	t_piece		*pieces;

	/*
	pieces = ft_lstnew("##\n##",  6);
	pieces->next = ft_lstnew(".##\n##", 6);
	pieces->next->next = ft_lstnew("#\n#\n#\n#", 8);
	pieces->next->next->next = ft_lstnew("####", 4);
	pieces = ft_lstnew(".AA\nAA",  6);
	pieces->next = ft_lstnew("BB\nBB", 6);
	pieces->next->next = ft_lstnew("C\nC\nC\nC", 8);
	pieces->next->next->next = ft_lstnew("DDDD", 4);
	*/

	pieces = struct_new_piece("..##\n.##.", 1);
	pieces->next = struct_new_piece("..##\n..##", 2);
	pieces->next->next = struct_new_piece("..#.\n..##\n..#.", 3);

	while (pieces)
	{
		ft_putstr(pieces->content);
		pieces = pieces->next;
		ft_putchar('\n');
	}
	//start_solve(pieces);
	test_get_boundry();
	
	//test_get_boundry();
	return (0);
}
