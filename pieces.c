/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:51:07 by juwong            #+#    #+#             */
/*   Updated: 2018/07/05 13:26:11 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void remove_piece(char ***board)
 {
	char	**ptr_board;
	char	last_piece;
	int		i;
	int		k;

	ptr_board = *board;
	last_piece = 'A';
	k = 0;
	while (ptr_board[k])
	{
		i = 0;
		while (ptr_board[k][i])
		{
			if (ft_isalpha(ptr_board[k][i]))
			{
				if (last_piece < ptr_board[k][i])
					last_piece = ptr_board[k][i];
			}
			i++;
		}
		k++;
	}
	k = 0;
	while (ptr_board[k])
	{
		i = 0;
		while (ptr_board[k][i])
		{
			if (ptr_board[k][i] == last_piece)
				ptr_board[k][i] = '.';
			i++;
		}
		k++;
	}
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
		ptr++;
	}
	return (1);
}

int		put_piece(char *piece, char ***board, t_point p)
{
	char	**board2;
	int		k;

	board2 = *board;
	if (!piece)
		return (0);
	k = p.x;
	while (*(char*)piece)
	{
		if (ft_isalpha(*(char*)piece))
		{
			board2[p.y][k] = *(char*)piece;
			k++;
		}
		else if (*((char*)piece) == '.')
			k++;
		else if (*((char*)piece) == '\n')
		{
			p.y++;
			k = p.x;
		}
		piece++;
	}
	return (1);
}