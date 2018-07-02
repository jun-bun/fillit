/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 18:16:49 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/02 16:15:14 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include "libft/libft.h"

typedef struct	s_piece
{
	char				symbol;
	char				**piece;
	int					*boundry;
	struct s_piece		*next;
}				t_piece;

void	ft_print_board(char **board);
void	solve(t_list *pieces);
int		*piece_cords(int piece);
char	**piece_create(int	piece);
char	**make_board(size_t size);
size_t	get_min_board_size(t_list *pieces);
int		*get_boundry_piece(char *piece);
int		check_valid_space(t_list *piece, char ***board, int x, int y);
int		put_piece(t_list *piece, char ***board);
int	valid_tetro_chars(char *s, int start, int end);
int	valid_tetro_map(char *s);
int	valid_tetro_connections(char *s, int start, int end, int pos);
int valid_tetro_connections_checker(char *s, int start, int end);

#endif
