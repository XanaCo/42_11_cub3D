/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_stock_sprite_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:12:04 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 20:15:32 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Flags the position of the twins and stocks the coord of the sprite
*/
static void	stock_sprite(t_sprites *sprite, char name, int x, int y)
{
	int	i;

	i = 0;
	if (name == 'T')
		i = 1;
	sprite[i].pos.x = x + 0.5;
	sprite[i].pos.y = y + 0.5;
}	

/*
Searches and stocks the sprite position
*/
void	search_sprites(t_game *data, char **map, char sprite)
{
	int	i;
	int	j;

	i = 0;
	if (!map)
		exit_failure(data, "Map was not stocked\n", -2);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == sprite)
			{	
				stock_sprite(data->sprite, sprite, i, j);
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}
