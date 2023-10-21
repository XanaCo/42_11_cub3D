/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:11:44 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 19:38:13 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Checks if the first and last line of the map is filled with '1'
*/
static void	first_line_last_line(t_game *data, char **map)
{
	int	i;
	int	last;

	i = 0;
	last = data->map.map_h - 1;
	while (map[0][i])
	{
		if (map[0][i] != '1' && map[0][i] != '2')
			exit_failure(data, "Map perimeter is not closed\n", -2);
		i++;
	}
	i = 0;
	while (map[last][i])
	{
		if (map[last][i] != '1' && map[last][i] != '2')
			exit_failure(data, "Map perimeter is not closed\n", -2);
		i++;
	}
}

/*
Checks if the first and last column of the map is filled with '1'
*/
static void	first_column_last_column(t_game *data, char **map)
{
	int	i;
	int	last;

	i = 0;
	last = data->map.map_w - 1;
	while (map[i])
	{
		if (map[i][0] != '1' && map[i][0] != '2')
			exit_failure(data, "Map perimeter is not closed\n", -2);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][last] != '1' && map[i][last] != '2')
			exit_failure(data, "Map perimeter is not closed\n", -2);
		i++;
	}
}

/*
Checks the filled map if 0 or the player is next to a 2 (an empty space)
*/
static void	closed_perim(t_game *data, char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i + 1])
	{
		j = 1;
		while (map[i][j + 1])
		{
			if (map[i][j] != '1' && map[i][j] != '2')
			{
				if (map[i - 1][j] == '2'
					|| map[i + 1][j] == '2'
					|| map[i][j - 1] == '2'
					|| map[i][j + 1] == '2')
					exit_failure(data, "Map perimeter is not closed\n", -2);
			}
			j++;
		}
		i++;
	}
}

/*
Calls all wall checks
*/
void	check_walls(t_game *data, char **map)
{
	first_line_last_line(data, map);
	first_column_last_column(data, map);
	closed_perim(data, map);
}
