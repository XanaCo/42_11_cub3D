/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:10:23 by ancolmen          #+#    #+#             */
/*   Updated: 2023/09/20 16:42:03 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
This function will erase all types of ASCII spaces from the line and return 
a new cleaned line
*/
char	*ft_clean_whitespaces(char *line)
{
	char	*res;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (line[++i])
	{
		if (ft_iswspace(line[i]))
			j++;
	}
	res = (char *)ft_calloc((i - j + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	while (line[++i])
	{
		if (ft_iswspace(line[i]))
			continue ;
		res[j] = line[i];
		j++;
	}
	return (res);
}
