// Do not add this to final git
#include "fillit.h"
#include <stdio.h>

int		Main()
{
	char	**piece;
	piece = piece_create(0);

	while (*piece)
        ft_putstr(*piece++);

	return (0);
}
