/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:00:21 by dkotov            #+#    #+#             */
/*   Updated: 2018/06/29 21:36:21 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_putnbr(valid_tetrominoe(argv[1]));
	}
	else
	{
		ft_putstr("usage: ./fillit file_with_tetrominoes");
	}
	return (0);
}
