/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_door_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:26:01 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 18:36:27 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Checks if we are in front of 237 door
*/
int	is_237_door(t_game *data)
{
	t_ray	*coord;
	char	door;
	char	**map;
	int		side;

	coord = &data->coord;
	map = data->map.map;
	side = ft_get_dir(coord);
	if (side == NORTH)
		door = map[(int)coord->pos.x + 1][(int)coord->pos.y];
	if (side == SOUTH)
		door = map[(int)coord->pos.x - 1][(int)coord->pos.y];
	if (side == WEST)
		door = map[(int)coord->pos.x][(int)coord->pos.y + 1];
	if (side == EAST)
		door = map[(int)coord->pos.x][(int)coord->pos.y - 1];
	if (door == 'X')
		return (1);
	else
		return (0);
}

/*
Puts the final animation to the screen
*/
void	ft_handle_final_door(t_game *data)
{
	static int	i = 0;

	if (i < 34 && !(data->loops % BIG_RATE))
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->screen_end[i].img, 0, 0);
		i++;
	}
}
