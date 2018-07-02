/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:25:08 by juwong            #+#    #+#             */
/*   Updated: 2018/07/01 20:17:21 by juwong           ###   ########.fr       */
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

short	*get_boundry_piece(char *piece)
{
	short	i;
	short	j;
	short	max_i;
	short	*boundry;

	i = 0;
	j = 1;
	max_i = 0;
	boundry = (short *)malloc(sizeof(short) * 2);
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

int		put_piece(t_list *piece,char	***board)
{
	char	**board2;
	short	boundry;
	board2 = *board;

//	int		i;
//	int		j;
	if (!(piece->next))
		return (0);
	boundry = get_boundry_piece(t_list->content);
	while (**board2)
		if()


	/*
	i = 0
	j = 0
	while (*(piece->content))
		if(board2[i][j] = '.')
			board2[i][j] = piece->content++;
	*/
	return (1);
}