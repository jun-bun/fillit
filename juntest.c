// Do not add this to final git
#include "fillit.h"
#include <stdio.h>

void	ft_print_board(char **board)
{
	if(!board)
		printf("Fuck this shit");
	while (*board)
	{	ft_putstr(*board++);
		ft_putchar('\n');
	}
}

void	test_get_boundry()
{
	int		*boundry;

	t_list		*pieces;
	pieces = ft_lstnew("##\n##",  6);
	pieces->next = ft_lstnew("#\n#\n#\n#", 8);

	boundry = get_boundry_piece(pieces->content);
	while (*boundry)
	{
		printf("%d ", *boundry);
		boundry++;
	}
	pieces = pieces->next;
	
	boundry = get_boundry_piece(pieces->content);
	while (*boundry)
	{
		printf("%d ", *boundry);
		boundry++;
	}
}

int		main()
{
	t_list		*pieces;

	/*
	pieces = ft_lstnew("##\n##",  6);
	pieces->next = ft_lstnew(".##\n##", 6);
	pieces->next->next = ft_lstnew("#\n#\n#\n#", 8);
	pieces->next->next->next = ft_lstnew("####", 4);
	*/ 
	pieces = ft_lstnew("A\nAA\nA\n",  8);
	pieces->next = ft_lstnew("BB\nBB", 6);
	pieces->next->next = ft_lstnew("C\nC\nC\nC", 8);
	pieces->next->next->next = ft_lstnew("DDDD", 4);
	
	start_solve(pieces);
	
	//test_get_boundry();
	return (0);
}
