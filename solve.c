/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:43:53 by juwong            #+#    #+#             */
/*   Updated: 2018/07/05 13:14:48 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
void	solve(t_list *pieces)
{
	char	**board;
	size_t	size;
	int		p.x;
	int		p.y;

    size = get_min_board_size(pieces);
    board = make_board(size);
	
//	p.x = 0;
//	p.y = 0;
	if (check_valid_space(piece, board, i, j)
		return ;

	ft_print_board(board);
	ft_putchar('\n');
	pieces = pieces->next;

}
*/

int		solve(t_piece 	*l_pieces, char ***board, int size, t_point p)
{
	int			*boundry;
	//int		res;
	//t_list	*new_l;
	//int		res;
	t_point		np;
	int			res;

	if (!l_pieces)
		return (1);
	boundry = l_pieces->boundry;
	np.x = 0;
	np.y = 0;
	while (p.x + boundry[0] <= size && p.y + boundry[1] <= size)
	{
		/*
		if ((!piece_placeable(l_pieces->content, board, size, p)))
		{
			p.x++;
			new_l = ft_lstnew(remove_piece(board), 8);
			ft_lstadd(&l_pieces, new_l);
			//ft_putstr(new_l->content);
			res = (solve(new_l, board, size, p));
		}
		*/
		if (check_valid_space(l_pieces->content, board, p.x, p.y))
		{
			put_piece(l_pieces->content, board, p);
			ft_print_board(*board);
			ft_putendl("put piece");
			ft_putstr(l_pieces->content);
			ft_putchar('\n');
			ft_putchar('\n');
			res = solve(l_pieces->next, board, size, np);
			if (res == 1)
				return (1);		
			if (res == 0)
			{
				remove_piece(board);
				ft_print_board(*board);
				ft_putendl("removed piece");
				ft_putstr(l_pieces->content);
				ft_putchar('\n');
				ft_putchar('\n');
			}
		}
			p.x++;
			if (p.x + boundry[0] > size)
			{
				p.y++;
				p.x = 0;
			}
	}
	return (0);
}

void	start_solve(t_piece *l_pieces)
{
	char		**board;
	int			size;
	t_point		p;

    size = get_min_board_size(l_pieces);
    board = make_board(size);
	
	p.x = 0;
	p.y = 0;
	while (!(solve(l_pieces, &board, size, p)))
		{
			size++;
    		free(board);
			board = make_board(size);
		}
	ft_putendl("Found answer!");
	ft_print_board(board);
}
/*
	while (pieces)
	{
//		put_piece(pieces->content, &board, size, p);
		ft_print_board(board);
		while (!(put_piece(pieces->content, &board, size, p)))
		{
			remove_piece(&board);
			pieces = l_last;
			p.x++;
			if (p.x > (int)size)
			{
				p.x = 0;
				p.y++;
			}
		p.x = 0;
		p.y = 0;
		l_last = pieces;
		if (pieces->next)
			pieces = pieces->next;
		else
			return ;
		}

	}
*/

/*
void	solve(t_list *pieces)
{
	char	**board;
	size_t	size;
	int		p.x;
	int		p.y;

    size = get_min_board_size(pieces);
    board = make_board(size);
	
	p.x = 0;
	p.y = 0;
	while(pieces)
	{
		if (!(check_valid_space(pieces, &board, p.x, p.y)))
		{
			ft_print_board(board);
			ft_putchar('\n');
			remove_piece(&board);
			ft_print_board(board);
			p.x++;
			if (p.x > (int)size)
			{
				p.x = 0;
				p.y++;
			}
		}
		else
		{
			put_piece(pieces, &board, p.x, p.y);
			pieces = pieces->next;
			p.x = 0;
			p.y = 0;
		}
	}
	
	remove_piece(&board);
	ft_print_board(board);
}
*/