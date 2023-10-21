/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_stock_pl_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:12:04 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 19:45:31 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Searches for the player position in the map tab
*/
void	search_player(t_game *data, char **map)
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
			if (map[i][j] == 'N' || map[i][j] == 'S'
			|| map[i][j] == 'E' || map[i][j] == 'W')
			{	
				stock_player(data, map[i][j], i, j);
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

/*
Stocks the player position and inits the
directions for North and South start views
*/
static void	stock_player_ns(t_game *data, char dir)
{
	if (dir == 'N')
	{
		data->coord.dir.x = -1;
		data->coord.plane.y = 0.66;
		data->coord.screen_dir.y = 1;
	}
	if (dir == 'S')
	{
		data->coord.dir.x = 1;
		data->coord.plane.y = -0.66;
		data->coord.screen_dir.y = -1;
	}
}

/*
Stocks the player position and inits the
directions for West and East start views
*/
static void	stock_player_ew(t_game *data, char dir)
{
	if (dir == 'E')
	{
		data->coord.dir.y = 1;
		data->coord.plane.x = 0.66;
		data->coord.screen_dir.x = 1;
	}
	if (dir == 'W')
	{
		data->coord.dir.y = -1;
		data->coord.plane.x = -0.66;
		data->coord.screen_dir.x = -1;
	}
}

/*
Calls the correct stock player function depending on start position
*/
void	stock_player(t_game *data, char dir, int pos_x, int pos_y)
{
	data->coord.pos.x = (double)pos_x + 0.5;
	data->coord.pos.y = (double)pos_y + 0.5;
	if (dir == 'N' || dir == 'S')
		stock_player_ns(data, dir);
	if (dir == 'E' || dir == 'W')
		stock_player_ew(data, dir);
}
