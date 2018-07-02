/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:51:07 by juwong            #+#    #+#             */
/*   Updated: 2018/07/01 14:29:32 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** make_piece(1) -> {{###},
**					 {..#}}
**
**{#.}
**{#.}
**{##}
**{#}
**{#}
**{#}
**{#}
**{####}
char **make_piece(int piece, int	piece_num)
*/

/*
** Might go in a different direction and not need this code
int 	*piece_cords(int piece)
{
	int		s[2][8] = {{0,0,0,1,1,0,1,1},{0,0,0,1,0,2,0,3}};

//s = (int**)malloc(sizeof(int*) * 2);
//*s = (int*)malloc(sizeof(int) * 16);
//s[0] = {0,0,0,1,1,0,1,1};
//s[1] = {0,0,0,1,0,2,0,3};
if (!piece)
	return s[piece];
else
	return (NULL);
}

char	**piece_create(int	piece)
{
	int		*cords;
	char	**piece_array;
	int		i;

	if (!piece)
		return NULL;
	cords = piece_cords(piece);
	i = 0;
	if (!(piece_array = (char**)malloc(sizeof(char*) * cords[6] + 1)))
		return (NULL);
	while(i <= cords[6])
	{
		if (!(piece_array[i] = ft_strnew(cords[7])))
			return (NULL);
		ft_strset(piece_array[i], '.');
		i++;
	}
	i = 0;
	while (i < 8)
	{
		piece_array[cords[i]][cords[i + 1]] = '#';
		i = i + 2;
	}
	piece_array[cords[i]] = NULL;
	return (piece_array);
}
*/

t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list	*list;

	if ((list = (t_list *)malloc(sizeof(*list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if ((list->content = malloc(content_size)) == NULL)
			return (NULL);
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
