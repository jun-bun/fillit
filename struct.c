/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 23:18:04 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/04 14:31:56 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	tetro_symbol(int tetro_num)
{
	char	sym;

	sym = tetro_num + 64;

	return (sym);
}

t_piece *struct_new_piece(char *s, int tetro_num)
{
	t_piece	*piece;

	if ((piece = (t_piece *)malloc(sizeof(*piece))) == NULL)
		return (NULL);
	if (s == NULL || tetro_num == 0)
	{
		piece->symbol = 0;
		piece->content = NULL;
	}
	else
	{
		piece->symbol = tetro_symbol(tetro_num);
		piece->content = tetro_new_string(tetro_clean_coordinates(tetro_get_coordinates(s, 0, 19)));
		piece->boundry = get_boundry_piece(piece->content);
		piece->t_point.x = 0;
		piece->t_point.y = 0;
	}
	piece->next = NULL;
	return (piece);
}

/* t_piece *struct_add_piece(t_piece old_piece, char *s, int tetro_num)
{
	t_piece	*piece;

	if ((piece = (t_piece *)malloc(sizeof(*piece))) == NULL)
		return (NULL);
	if (symbol == NULL || content == NULL)
	{
		piece->symbol = NULL;
		piece->content = NULL;
	}
	else
	{
		piece->symbol = tetro_symbol(tetro_num);
		piece->content = tetro_new_string(tetro_clean_coordinates(tetro_get_coordinates(s, 0, 19)));
	}
	old_piece->next = piece;
	piece->next = NULL;
	return (piece);
}
*/

void print_t_piece(t_piece *pieces)
{
	while (pieces != NULL)
	{
		ft_putchar(pieces->symbol);
		ft_putchar('\n');
		ft_putstr(pieces->content);
//		ft_putnbr(pieces->boundry);
		pieces = pieces->next;
	}
	return ;
}
