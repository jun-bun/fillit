/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 18:16:49 by dkotov            #+#    #+#             */
/*   Updated: 2018/07/03 21:11:43 by juwong           ###   ########.fr       */
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

typedef struct	s_point
{
	int					x;
	int					y;
}				t_point;

void	ft_print_board(char **board);
void	start_solve(t_list *pieces);
int		solve(t_list *l_pieces, char ***board, int size, t_point p);
char	**make_board(int size);
int		get_min_board_size(t_list *pieces);
int		*get_boundry_piece(char *piece);
int		check_valid_space(char *piece, char ***board, int x, int y);
int		piece_placeable(char *piece, char ***board, int size, t_point p);
int		put_piece(char *piece, char ***board, int size, t_point p);
char	*remove_piece(char ***board);
int	valid_tetro_chars(char *s, int start, int end);
int	valid_tetro_map(char *s);
int	valid_tetro_connections(char *s, int start, int end, int pos);
int valid_tetro_connections_checker(char *s, int start, int end);
char	tetro_symbol(int tetro_num);
int	*tetro_next_coordinate(char *s, int start);
int	**tetro_get_coordinates(char *s, int start, int end);

#endif