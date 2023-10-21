/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:17:49 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/04 13:17:34 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D.h"

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
