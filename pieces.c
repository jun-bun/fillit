/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:51:07 by juwong            #+#    #+#             */
/*   Updated: 2018/06/29 22:08:55 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** make_piece(o) -> []
char **make_piece(int piece, int	piece_num)
*/

typedef struct	s_piece
{
	int 		piece;
	char		symbol;
	char		**piece_object;
	t_piece		*next;
}				t_list;

char 	*piece_cords(int piece)
{
	int		**s;

s[0] = {0,0,0,1,1,0,1,1};
s[1] = {0,0,0,1,0,2,0,3};
if (!piece)
	return s[piece];
}

char	**piece_create(int	piece)
{
	char	*cords;
	char	**piece_arr;
	int		i;

	if (!piece)
		return NULL;
	cords = piece_cords(piece);
	i = 0;
	piece_array = (char**)malloc(sizeofchar*) * cords[6);
	while(i <= 8)
		piece_array[i] = 
}