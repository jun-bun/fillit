/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:25:08 by juwong            #+#    #+#             */
/*   Updated: 2018/07/02 00:10:12 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**make_board(size_t size)
{
	char	**board;
	char	**ptr;
	size_t	i;

	i = 0;
	board = (char**)malloc(sizeof(char**) * size + 1);
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

//short	*piece_postion(t_list	*piece,		***board)

int		check_valid_space(t_list *piece, char ***board, int x, int y)
{
	char	**board2;
	int		i;
	int		j;
	board2 = *board;
	char	*ptr;

	if (!(piece->content))
		return (0);
	ptr = piece->content;
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
		if (*ptr == '#')
		{
			if (board2[i + x][j + y] == '.')
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

int		put_piece(t_list *piece, char	***board)
{
	char	**board2;
	int		*boundry;
	int		i;
	int		j;
	int		k;
	int		t;

	board2 = *board;
	if (!piece)
		return (0);
//	ft_putendl(piece->content);
	boundry = get_boundry_piece(piece->content);
	i = 0;
	j = 0;
	while (i + boundry[0] <= 4 && j + boundry[1] <= 4)
	{

		t = check_valid_space(piece, board, i, j);
		ft_putnbr(i + boundry[0]);
		ft_putendl("i + b");
		ft_putnbr(j + boundry[1]);
		ft_putendl("j + b");
		if (t == 1)
		{
			k = i;
			while (*(char*)piece->content)
			{
//				ft_putstr("enter piece placement \n");
				if (*(char*)piece->content == '#')
				{
					board2[j][k] = *(char*)piece->content;
					k++;
//					ft_putchar(board2[k][j]);
				}
				else if (*((char*)piece->content) == '.')
					k++;
				else if (*((char*)piece->content) == '\n')
				{
					j++;
					k = i;
				}
				piece->content++;
			}
			return (1);
		}
		i++;
//		ft_putnbr(i);
		if (i + boundry[0] >= 4)
		{
//			ft_putendl("Enter");
			j++;
			i = 0;
		}
	}
	return (0);
}