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

int	valid_tetro_chars(char *s)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while(s[i])
	{
		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
			return (0);
		if (s[i] == '#')
			t++;
		i++;
	}
	if (t == 4 && i == 20)
		return (1);
	else
		return (0);
}

int valid_
