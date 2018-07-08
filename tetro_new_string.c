/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro_new_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 17:07:00 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/06 17:07:02 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*max(int **arr)
{
	int	*max;
	int bx;
	int by;

	max = (int *)malloc(sizeof(int) * 3);
	bx = 0;
	by = 0;
	while (bx < arr[0][0] || bx < arr[1][0] || bx < arr[2][0] || bx < arr[3][0])
		bx++;
	while (by < arr[0][1] || by < arr[1][1] || by < arr[2][1] || by < arr[3][1])
		by++;
	max[0] = bx;
	max[1] = by;
	return (max);
}

int		*coord_conversion(int i, int bx, int by)
{
	int *coord;

	coord = (int *)malloc(sizeof(int) * 3);
	if (by != 0)
	{
		coord[1] = i / (bx + 2);
		coord[0] = i % (bx + 2);
	}
	else
	{
		coord[1] = 0;
		coord[0] = i;
	}
	return (coord);
}

char	counter(int **arr, int i, int p)
{
	int	y;
	int	x;
	int	max_x;
	int max_y;

	max_x = max(arr)[0];
	max_y = max(arr)[1];
	y = coord_conversion(i, max_x, max_y)[1];
	x = coord_conversion(i, max_x, max_y)[0];
	if (y == arr[p][1])
	{
		if (x == arr[p][0])
			return ('#');
		else
			return ('.');
	}
	else
	{
		if (x <= max(arr)[0])
			return ('.');
		else
			return ('\n');
	}
}

char	*tetro_new_string(int **arr)
{
	char	*s;
	int		i;
	int		p;

	i = 0;
	p = 0;
	s = (char *)malloc(sizeof(char) * 25);
	while (p < 4)
	{
		s[i] = counter(arr, i, p);
		if (s[i] == '#')
			p++;
		i++;
	}
	s[i] = '\0';
	return (s);
}
