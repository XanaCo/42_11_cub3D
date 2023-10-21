/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:08:15 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 19:07:56 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
LIBFT ft_calloc() adding the allocated space 
to the garbage collector linked list
*/
void	*ft_calloc_gc(t_game *data, int id, size_t nmemb, size_t size)
{
	void	*res;

	res = ft_calloc(nmemb, size);
	if (!res)
		return (NULL);
	if (add_to_garbage(data, res, id))
		return (NULL);
	return (res);
}

/*
LIBFT ft_strdup() adding the allocated space 
to the garbage collector linked list
*/
char	*ft_strdup_gc(t_game *data, int id, const char *s)
{
	char	*res;

	res = ft_strdup(s);
	if (!res)
		return (NULL);
	if (add_to_garbage(data, res, id))
		return (NULL);
	return (res);
}

/*
LIBFT ft_strjoin() adding the allocated space 
to the garbage collector linked list
*/
char	*ft_strjoin_gc(t_game *data, int id, char const *s1, char const *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	if (!res)
		return (NULL);
	if (add_to_garbage(data, res, id))
		return (NULL);
	return (res);
}
