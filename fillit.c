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
#include <fcntl.h>

#define BUF_SIZE 560

int	main(int argc, char **argv)
{
	int	fd;
	int	ret;
	char	buf[BUF_SIZE];

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == 3)
		{
			ret = read(fd, buf, BUF_SIZE);
			if (valid_tetro_map(buf) > 0 && valid_tetro_map(buf) <= 26)
			{
				ft_putstr("I found: ");
				ft_putnbr(valid_tetro_map(buf));
				ft_putchar('\n');
				ft_putnbr(tetro_clean_coordinates(tetro_get_coordinates(buf, 0, 19))[0][0]);
				ft_putchar(';');
				ft_putnbr(tetro_clean_coordinates(tetro_get_coordinates(buf, 0, 19))[0][1]);
				ft_putchar(';');
				ft_putnbr(tetro_clean_coordinates(tetro_get_coordinates(buf, 0, 19))[0][2]);
				ft_putchar('\n');
				ft_putchar('\n');
				ft_putnbr(tetro_clean_coordinates(tetro_get_coordinates(buf, 0, 19))[1][0]);
				ft_putchar(';');
				ft_putnbr(tetro_clean_coordinates(tetro_get_coordinates(buf, 0, 19))[1][1]);
				ft_putchar(';');
				ft_putnbr(tetro_clean_coordinates(tetro_get_coordinates(buf, 0, 19))[1][2]);
				ft_putchar('\n');
				ft_putchar('\n');
				ft_putnbr(tetro_clean_coordinates(tetro_get_coordinates(buf, 0, 19))[2][0]);
				ft_putchar(';');
				ft_putnbr(tetro_clean_coordinates(tetro_get_coordinates(buf, 0, 19))[2][1]);
				ft_putchar(';');
				ft_putnbr(tetro_clean_coordinates(tetro_get_coordinates(buf, 0, 19))[2][2]);
				ft_putchar('\n');
				ft_putchar('\n');
				ft_putnbr(tetro_clean_coordinates(tetro_get_coordinates(buf, 0, 19))[3][0]);
				ft_putchar(';');
				ft_putnbr(tetro_clean_coordinates(tetro_get_coordinates(buf, 0, 19))[3][1]);
				ft_putchar(';');
				ft_putnbr(tetro_clean_coordinates(tetro_get_coordinates(buf, 0, 19))[3][2]);
				/* ft_putstr("Connections: ");
				ft_putnbr(valid_tetro_connections_checker(buf, 0, 20));*/
				return (0);
			}
			else
			{
				ft_putstr("invalid input\n");
				ft_putstr(buf);
				return (1);
			}
		}
		else
		{
			ft_putstr("cannot read the file");
			return (2);
		}
		close(fd);
	}
	else
	{
		ft_putstr("usage: ./fillit file_with_tetrominoes");
	}
	return (0);
}
