/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 01:59:09 by dkotov            #+#    #+#             */
/*   Updated: 2018/06/24 01:59:10 by dkotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*mem;
	int	i;
	int	j;
	int	z;

	if(!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	j = 0;
	z = ft_strlen(str);
	while (ft_isspace(str[z - 1]) != 0)
		z--;
	while (ft_isspace(str[i]) != 0)
		i++;
	if (z == 0)
	{
		mem = (char *)malloc(sizeof(char));
		mem[j] = '\0';
		return (mem);
	}
	mem = (char *)malloc(sizeof(char) * (z - i + 1));
	if (!mem)
		return (NULL);
	while (i < z && str[i])
	{
		mem[j] = str[i];
		j++;
		i++;
	}
	mem[j] = '\0';
	return (mem);
}
