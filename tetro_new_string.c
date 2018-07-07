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

#define INT char *s;int i;int p;int y;int x;
#define ZERO i=0;p=0;y=0;x=0;
#define END s[i++] = '\n';x = 0;y++;

char	*tetro_new_string(int **arr)
{
	INT;
	ZERO;
	s = (char *)malloc(sizeof(char) * 25);
	while (p < 4)
	{
		if (y == arr[p][1])
			if (x++ == arr[p][0])
			{
				p++;
				s[i++] = '#';
			}
			else
				s[i++] = '.';
		else
		{
			while (x <= (arr[3][0] || x <= arr[2][0] || x <= arr[1][0]))
			{
				s[i++] = '.';
				x++;
			}
			END;
		}
	}
	s[i] = '\0';
	return (s);
}
