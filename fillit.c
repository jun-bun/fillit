/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:00:21 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/08 15:13:46 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

#define BUF_SIZE 560

int	opener(int fd, char *buf)
{
	t_piece	*l_piece;
	t_piece	*f_piece;
	int		max_tetro;

	read(fd, buf, BUF_SIZE);
	max_tetro = valid_tetro_map(buf);
	if (max_tetro > 0 && max_tetro <= 26)
	{
		f_piece = struct_new_piece(buf, 1);
		l_piece = struct_make_list(f_piece, buf, valid_tetro_map(buf));
		start_solve(l_piece);
		return (1);
	}
	else
	{
		ft_putstr("error\n");
		return (0);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	char	buf[BUF_SIZE];

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			opener(fd, buf);
		}
		else
		{
			ft_putstr("cannot read the file");
			return (0);
		}
		close(fd);
	}
	else
	{
		ft_putstr("usage: ./fillit file_with_tetrominoes");
	}
}
