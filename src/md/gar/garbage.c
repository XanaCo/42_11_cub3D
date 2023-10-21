/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:17:49 by ancolmen          #+#    #+#             */
/*   Updated: 2023/09/22 17:23:36 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D.h"

/*
Adds node to garbage collector
*/
int	add_to_garbage(t_game *data, void *ptr, int id)
{
	t_gcol	*new;

	new = (t_gcol *)malloc(sizeof(t_gcol));
	if (!new)
		return (1);
	new->ptr = ptr;
	new->id = id;
	new->next = NULL;
	if (!data->gc)
		data->gc = new;
	else
	{
		new->next = data->gc;
		data->gc = new;
	}
	return (0);
}

/*
Adds node[i] to garbage collector 
when we allocate tabs and arrays
*/
int	add_matrix_to_garbage(t_game *data, int id, void **ptr)
{
	int	i;

	i = 0;
	while (ptr + i)
	{
		if (add_to_garbage(data, ptr + i, id))
			return (1);
		i++;
	}
	return (0);
}

/*
Cleans all the garbage list
*/
void	clean_all(t_game *data)
{
	t_gcol	*tmp;
	t_gcol	*iter;

	iter = data->gc;
	while (iter)
	{
		if (iter->ptr)
			free(iter->ptr);
		tmp = iter->next;
		free(iter);
		iter = tmp;
	}
	data->gc = NULL;
}

/*
Cleans only the TMP garbage, rearranging the list
*/
void	clean_tmp(t_game *data)
{
	t_gcol	*tmp;
	t_gcol	*iter;
	t_gcol	*prev;

	prev = NULL;
	iter = data->gc;
	while (iter)
	{
		if (iter->id == END)
		{
			prev = iter;
			iter = iter->next;
			continue ;
		}
		if (prev)
			prev->next = iter->next;
		else
			data->gc = iter->next;
		tmp = iter;
		iter = iter->next;
		free(tmp->ptr);
		free(tmp);
	}
}

/*
Goes through the linked list and frees 
all allocated memory depending on id
*/
void	clean_garbage(t_game *data, int flag)
{
	if (!data->gc)
		return ;
	if (flag == TMP)
		clean_tmp(data);
	if (flag == END)
		clean_all(data);
}
