/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:00:21 by dkotov            #+#    #+#             */
/*   Updated: 2018/06/29 19:00:36 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_putstr(argv[1]);
	}
	else
	{
		ft_putstr("usage: ");
	}
	return (0);
}
