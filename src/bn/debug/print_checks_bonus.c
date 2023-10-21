/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_checks_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:02:31 by atardif           #+#    #+#             */
/*   Updated: 2023/10/03 17:26:16 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

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
