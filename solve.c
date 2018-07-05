/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:43:53 by juwong            #+#    #+#             */
/*   Updated: 2018/07/05 15:29:48 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve(t_piece 	*l_pieces, char ***board, int size, t_point p)
{
	int			*boundry;
	t_point		np;
	int			res;

	if (!l_pieces)
		return (1);
	boundry = l_pieces->boundry;
	np.x = 0;
	np.y = 0;
	while (p.x + boundry[0] <= size && p.y + boundry[1] <= size)
	{
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