/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:17:49 by ancolmen          #+#    #+#             */
/*   Updated: 2023/09/25 13:56:00 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D.h"

/*
Prints garbage collector linked list
*/
void	print_garbage(t_game *data)
{
	t_gcol	*iter;

	iter = data->gc;
	if (!iter)
		printf("Garbage empty...\n");
	while (iter)
	{
		printf("Garbage NODE : %d - %p \n",
			iter->id,
			iter->ptr);
		iter = iter->next;
	}
}

/*
Prints the stocked map
*/
void	print_tab(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
