/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:43:53 by juwong            #+#    #+#             */
/*   Updated: 2018/07/03 00:00:39 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
void	solve(t_list *pieces)
{
	char	**board;
	size_t	size;
	int		pos_x;
	int		pos_y;

    size = get_min_board_size(pieces);
    board = make_board(size);
	
//	pos_x = 0;
//	pos_y = 0;
	if (check_valid_space(piece, board, i, j)
		return ;

	ft_print_board(board);
	ft_putchar('\n');
	pieces = pieces->next;

}
*/

/*
void	solve(t_list *piece, char ***board, size_t size, int pos_x, int pos_y)
{
	if (!(check_valid_space(piece, &board, pos_x, pos_y)))
		{
			put_piece(t_list *piece, char ***board, int pos_x, int pos_y);
			
		}
		else
		{
			put_piece(pieces, &board, pos_x, pos_y);
			pieces = pieces->next;
			pos_x = 0;
			pos_y = 0;
		}
}
*/
void	start_solve(t_list *pieces)
{
	char	**board;
	size_t	size;
	int		pos_x;
	int		pos_y;
	t_list	*l_last;

    size = get_min_board_size(pieces);
    board = make_board(size);
	
	pos_x = 0;
	pos_y = 0;
	while (pieces)
	{
		put_piece(pieces, &board, pos_x, pos_y);
		ft_print_board(board);
		while (!(put_piece(pieces, &board, pos_x, pos_y)))
		{
			remove_piece(&board);
			pos_x++;
			if (pos_x > (int)size)
			{
				pos_x = 0;
				pos_y++;
			}
		pos_x = 0;
		pos_y = 0;
		l_last = pieces;
		pieces = pieces->next;
		}
	}
}

/*
void	solve(t_list *pieces)
{
	char	**board;
	size_t	size;
	int		pos_x;
	int		pos_y;

    size = get_min_board_size(pieces);
    board = make_board(size);
	
	pos_x = 0;
	pos_y = 0;
	while(pieces)
	{
		if (!(check_valid_space(pieces, &board, pos_x, pos_y)))
		{
			ft_print_board(board);
			ft_putchar('\n');
			remove_piece(&board);
			ft_print_board(board);
			pos_x++;
			if (pos_x > (int)size)
			{
				pos_x = 0;
				pos_y++;
			}
		}
		else
		{
			put_piece(pieces, &board, pos_x, pos_y);
			pieces = pieces->next;
			pos_x = 0;
			pos_y = 0;
		}
	}
	
	remove_piece(&board);
	ft_print_board(board);
}
*/