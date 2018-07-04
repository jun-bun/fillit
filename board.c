/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:25:08 by juwong            #+#    #+#             */
/*   Updated: 2018/07/03 21:11:44 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**make_board(int size)
{
	char	**board;
	char	**ptr;
	int		i;

	i = 0;
	board = (char**)malloc(sizeof(*board) * (size + 1));
	ptr = board;
	while (i < size)
	{
		*board = ft_strnew(size);
		*board = ft_memset(*board, '.', size);
		board++;
		i++;
	}
	*board = 0;
	return (ptr);
}

int		get_min_board_size(t_list *pieces)
{
	int		i;
	int		sqroot;
	
	i = 0;
	sqroot = 2;
	while (pieces)
    {
        pieces = pieces->next;
		i++;
    }
	i = i * 4;
	while (sqroot * sqroot < i)
		sqroot++;
	
	return ((size_t) sqroot);
}

int		*get_boundry_piece(char *piece)
{
	int		i;
	int		j;
	int		max_i;
	int		*boundry;

	i = 0;
	j = 1;
	max_i = 0;
	boundry = (int *)malloc(sizeof(int) * 2);
	while (*piece)
	{
		if (*piece == '\n')
		{
			j++;
			max_i = max_i < i ? i : max_i;
			i = 0;
		}
		else
			i++;
		piece++;
	}
	boundry[0] = max_i;
	boundry[1] = j;
	return (boundry);
}


 char	*remove_piece(char ***board)
 {
	char	**ptr_board;
	char	**ptr2_board;
	char	last_piece;
	int		i;

	ptr_board = *board;
	ptr2_board = *board;
	last_piece = 'A';
	while (*ptr_board)
	{
		i = 0;
		while ((*ptr_board)[i])
		{
			if (ft_isalpha(**ptr_board))
			{
				if (last_piece < (*ptr_board)[i])
					last_piece = (*ptr_board)[i];
			}
			i++;
		}
		ptr_board++;
	}
	while (*ptr2_board)
	{
		i = 0;
		while ((*ptr2_board)[i])
		{
			if ((*ptr2_board)[i] == last_piece)
				(*ptr2_board)[i] = '.';
			i++;
		}
		ptr2_board++;
	}
	if (last_piece == 'A')
		return (".AA\nAA");
	if (last_piece == 'B')
		return ("BB\nBB");
	if (last_piece == 'C')
		return ("C\nC\nC\nC");
	if (last_piece == 'D')
		return ("DDDD");
	else 
		return ("NOOOOOOOOO");
 }

int		check_valid_space(char *piece, char ***board, int x, int y)
{
	char	**board2;
	char	*ptr;
	int		i;
	int		j;

	if (!(piece))
		return (0);
	board2 = *board;
	ptr = piece;
	i = 0;
	j = 0;
/*
	ft_putnbr(x);
	ft_putendl("x");
	ft_putnbr(y);
	ft_putendl("y");
*/
	while (*ptr)
	{
		if (ft_isalpha(*ptr))
		{
			if (board2[j + y][i + x] == '.')
				i++;
			else
				return (0);
		}
		else if (*ptr == '.')
			i++;
		else if (*ptr == '\n')
		{
			j++;
			i = 0;
		}
/*
		ft_putnbr(i);
		ft_putnbr(j);
		ft_putchar('|');
		ft_putchar(*ptr);
		ft_putchar(board2[i + x][j + y]);
		ft_putchar('\n');
*/
		ptr++;
	}
	return (1);
}
int		piece_placeable(char *piece, char ***board, int size, t_point p)
{
	int		*boundry;
	boundry = get_boundry_piece(piece);

	while (p.x + boundry[0] <= size && p.y + boundry[1] <= size)
	{
		if(check_valid_space(piece, board, p.x, p.y))
			return (1);
		p.x++;
		if (p.x + boundry[0] > size)
		{
			p.y++;
			p.x = 0;
		}
	}
	return (0);
}

int		put_piece(char *piece, char ***board, int size, t_point p)
{
	char	**board2;
	int		*boundry;
	int		i;
	int		j;
	int		t;
	int		k;

	board2 = *board;
	if (!piece)
		return (0);
//	ft_putendl(piece->content);
	boundry = get_boundry_piece(piece);
	i = 0 + p.x;
	j = 0 + p.y;
	while (i + boundry[0] <= size && j + boundry[1] <= size)
	{

		t = check_valid_space(piece, board, i, j);
/*
		ft_putnbr(i + boundry[0]);
		ft_putendl("i + b");
		ft_putnbr(j + boundry[1]);
		ft_putendl("j + b");
*/
		if (t == 1)
		{
			k = i;
			while (*(char*)piece)
			{
//				ft_putstr("enter piece placement \n");
				if (ft_isalpha(*(char*)piece))
				{
					board2[j][k] = *(char*)piece;
					k++;
//					ft_putchar(board2[k][j]);
				}
				else if (*((char*)piece) == '.')
					k++;
				else if (*((char*)piece) == '\n')
				{
					j++;
					k = i;
				}
				piece++;
			}
			return (1);
		}
		i++;
//		ft_putnbr(i);
		if (i + boundry[0] > size)
		{
//			ft_putendl("Enter");
			j++;
			i = 0;
		}
	}
	return (0);
}