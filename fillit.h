/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 18:16:49 by dkotov            #+#    #+#             */
/*   Updated: 2018/06/30 13:04:45 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

#include "libft/libft.h"

typedef struct	s_piece
{
	int					piece;
	char				symbol;
	char				**piece_object;
	struct s_piece		*next;
}						t_piece;

int		*piece_cords(int piece);
char	**piece_create(int	piece);

#endif
