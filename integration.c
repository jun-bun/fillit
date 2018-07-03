/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integration.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 16:27:22 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/02 16:27:25 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*

t_piece tetro_new_valid(char *s, int tetro_amount)
{
	t_piece	*tetro;

	if ((tetro = (t_piece *)malloc(sizeof(*tetro))) == NULL)
		return (NULL);
	if (symbol == NULL || piece == NULL)
	{
		tetro->symbol = NULL;
		tetro->piece = NULL;
	}
	else
	{
		tetro->symbol = tetro_symbol();
	}
}

*/

char	tetro_symbol(int tetro_num)
{
	char	sym;

	sym = tetro_num + 64;

	return (sym);
}

int	*tetro_next_coordinate(char *s, int start)
{
	int	x;
	int	y;
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * 3);
	i = start;
	x = 0;
	y = 0;
	while (s[i] != '#')
	{
		if (s[i] == '.')
			i++;
		if (s[i] == '\n')
			y++;
		i++;
	}
	(i > 5) ? (x = i % 10 - 5) : (x = i % 10);
	arr[0] = x;
	arr[1] = y;
	arr[2] = i;
	return (arr);
}

int	**tetro_get_coordinates(char *s, int start, int end)
{
	int	i;
	int	p;
	int	**arr;

	i = start;
	p = 0;
	arr = (int **)malloc(sizeof(int) * 9);
	while (p < 4 && start < end)
	{
		arr[p] = (int *)malloc(sizeof(int) * 3);
		arr[p][0] = tetro_next_coordinate(s, i)[0];
		arr[p][1] = tetro_next_coordinate(s, i)[1];
		i = tetro_next_coordinate(s, i)[2] + 1;
		p++;
	}
	return(arr);
}

/* char tetro_clean_map(int **tetro)
{
	int	i;

	i = 0;

}
*/
