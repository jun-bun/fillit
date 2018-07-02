/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 18:16:49 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/01 17:28:25 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include "libft/libft.h"

typedef struct	s_piece
{
	int					piece;
	char				symbol;
	char				**piece_object;
	struct s_piece		*next;
}				t_piece;

int	*piece_cords(int piece);
char	**piece_create(int	piece);
char	**make_board(size_t size);
int		put_piece(t_list *piece, char ***board);
short	*get_boundry_piece(char *piece);
int	valid_tetro_chars(char *s, int start, int end);
int	valid_tetro_map(char *s);
/* int	valid_tetro_connections(char *s, int start, int end); */

#endif
