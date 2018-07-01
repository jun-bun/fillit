/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:38:48 by dkotov            #+#    #+#             */
/*   Updated: 2018/06/30 12:38:56 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid_tetro_chars(char *s, int start, int end)
{
	int	i;
	int	t;
	int endline;

	i = start;
	t = 0;
	endline = i + 4;
	while (endline < end)
	{
		if (s[endline] != '\n')
			return (0);
		endline = endline + 5;
	}
	while (i < end)
	{
		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
			return (0);
		if (s[i] == '#')
			t++;
		i++;
	}
	if (t == 4)
		return (1);
	else
		return (0);
}

/* connections are halfway done
**
int	valid_tetro_connections(char *s, int start, int end)
{
	int	i;
	int	c;

	i = start;
	c = 0;
	while(i < end)
	{
		if (s[i] == '#' && i == start)
		{
			if (s[i + 1] == '#')
				c++;
			if (s[i + 5] == '#')
				c++;
		}
		if (s[i] == '#' && i > start && i < start + 3)
		{
			if (s[i - 1] == '#')
				c++;
			if (s[i + 1] == '#')
				c++;
			if (s[i + 5] == '#')
				c++;
		}
		if (s[i] == '#' && i == start + 3)
		{
			if (s[i - 1] == '#')
				c++;
			if (s[i + 5] == '#')
				c++;
		}
		i++;
	}
	return (c);
}*/

/*
** valid_tetro_map doesn't account for ending with an empty line
*/

int	valid_tetro_map(char *s)
{
	int	i;
	int	tetro;

	i = 0;
	tetro = 0;
	while (s[i])
	{
		if (valid_tetro_chars(s, i, i + 19) == 1)
		{
			i = i + 21;
			if (s[i] == '\n')
				i++;
			tetro++;
		}
		else
			return (0);
	}
	return (tetro);
}
