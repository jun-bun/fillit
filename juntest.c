// Do not add this to final git
#include "fillit.h"

void	test_get_boundry(t_piece	*pieces)
{
	//int		*boundry;
	
	//boundry = get_boundry_piece(pieces->content);
	while (pieces)
	{
		ft_putnbr(pieces->boundry[0]);
		ft_putnbr(pieces->boundry[1]);
		ft_putchar('\n');
		pieces = pieces->next;
	}
	
	//boundry = get_boundry_piece(pieces->content);
	/*
	while (*boundry)
	{
		ft_putnbr(*boundry);
		boundry++;
		ft_putchar('\n');
	}
	*/
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

	pieces = struct_new_piece("###.\n..#.", 1);
	pieces->next = struct_new_piece("..##\n..##", 2);
	pieces->next->next = struct_new_piece("..#.\n###.", 3);
	pieces->next->next->next = struct_new_piece(".##.\n##..", 4);
	pieces->next->next->next->next = struct_new_piece("###.\n..#.", 1);
	//pieces->next->next->next->next->next = struct_new_piece(".##.\n##..", 4);
	//pieces->next->next->next->next->next->next = struct_new_piece("####", 4);

	pieces->content = ("AAA\n..A");
	pieces->next->content = ("BB\nBB");
	pieces->next->next->content = ("..C\nCCC");
	pieces->next->next->next->content = (".DD\nDD");
	pieces->next->next->next->next->content = ("EEE\n..E");
	//pieces->next->next->next->next->next->content = (".FF\nFF");
	//pieces->next->next->next->next->next->next->content = ("GGGG");

	//struct_new_piece->symbol = ('A');
	//struct_new_piece->content = ("A..\nAAA");

	/*
	test_get_boundry(pieces);
	while (pieces)
	{
		ft_putstr(pieces->content);
		pieces = pieces->next;
		ft_putchar('\n');
	}
	*/
	start_solve(pieces);

	
	//test_get_boundry();
	return (0);
}
