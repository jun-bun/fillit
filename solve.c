/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:43:53 by juwong            #+#    #+#             */
/*   Updated: 2018/07/03 23:39:31 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lstadd(t_list **alst, t_list *new);
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

int		solve(t_list *l_pieces, char ***board, int size, t_point p)
{
	int		*boundry;
	//int		res;
	//t_list	*new_l;
	int		res;
	if (l_pieces == NULL)
		return (1);
	boundry = get_boundry_piece(l_pieces->content);
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
		ft_print_board(*board);
		if ((piece_placeable(l_pieces->content, board, size, p)))
		{
			put_piece(l_pieces->content, board, size, p);
			l_pieces = l_pieces->next;
		}
		res = solve(l_pieces, board, size, p);
		if (res == 1)
			return (1);
		else
		{
			p.x++;
			if (p.x + boundry[0] > size)
			{
				p.y++;
				p.x = 0;
			}
		}
	}
	return (0);
}

void	start_solve(t_list *l_pieces)
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
	ft_print_board(board);
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
}

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