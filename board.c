/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:25:08 by juwong            #+#    #+#             */
/*   Updated: 2018/06/29 20:25:03 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

char	**make_board(size_t size);
{
	char	**board;
	size_t	i;

	i = 0;
	board = (char**)malloc(sizeof(char**) * size + 1);
	while (i < size)
	{
		*board = ft_strnew(size);
		*board = ft_memset(*board, '.', size);
		board++;
		i++;
	}
	*board = 0;
	return (board);
}