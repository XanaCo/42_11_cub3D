/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:26:25 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 20:30:10 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Updates the image of the door
*/
void	ft_degrade_door(char *door, int keycode)
{
	if (keycode == ESPACE)
	{
		if (*door == 'P')
			*door = 'Q';
		else if (*door == 'Q')
			*door = 'R';
		else if (*door == 'R')
			*door = 'S';
		else if (*door == 'S')
			*door = '9';
	}
	else
	{
		if (*door == '9')
			*door = 'P';
	}
}

/*
Checks to update the image of the door and if we can open it
*/
void	ft_update_door(t_points pos, int side, char **map, int keycode)
{
	if (side == SOUTH && map[(int)pos.x - 2][(int)pos.y] == '0')
		ft_degrade_door(&map[(int)pos.x - 1][(int)pos.y], keycode);
	if (side == NORTH && (map[(int)pos.x + 2][(int)pos.y]) == '0')
		ft_degrade_door(&map[(int)pos.x + 1][(int)pos.y], keycode);
	if (side == EAST && (map[(int)pos.x][(int)pos.y - 2] == '0'))
		ft_degrade_door(&map[(int)pos.x][(int)pos.y - 1], keycode);
	if (side == WEST && (map[(int)pos.x][(int)pos.y + 2] == '0'))
		ft_degrade_door(&map[(int)pos.x][(int)pos.y + 1], keycode);
}

/*
Checks the side of the door and updates it status
*/
void	ft_in_front_door(t_ray *coord, int side, char **map, int keycode)
{
	if (side == SOUTH && ft_is_door(map[(int)coord->pos.x - 1]
			[(int)coord->pos.y]) && ft_far_enough(coord->pos.x,
			(int)coord->pos.x - 1, 1))
		ft_update_door(coord->pos, side, map, keycode);
	if (side == NORTH && ft_is_door(map[(int)coord->pos.x + 1]
			[(int)coord->pos.y]) && ft_far_enough(coord->pos.x,
			(int)coord->pos.x + 1, 0))
		ft_update_door(coord->pos, side, map, keycode);
	if (side == EAST && ft_is_door(map[(int)coord->pos.x]
			[(int)coord->pos.y - 1]) && ft_far_enough(coord->pos.y,
			(int)coord->pos.y - 1, 1))
		ft_update_door(coord->pos, side, map, keycode);
	if (side == WEST && ft_is_door(map[(int)coord->pos.x]
			[(int)coord->pos.y + 1]) && ft_far_enough(coord->pos.y,
			(int)coord->pos.y + 1, 0))
		ft_update_door(coord->pos, side, map, keycode);
}

/*
Gets the direction of our view
*/
int	ft_get_dir(t_ray *coord)
{
	if (coord->dir.x >= 0.90 && coord->dir.x <= 1)
		return (NORTH);
	else if (coord->dir.x <= -0.90 && coord->dir.x >= -1)
		return (SOUTH);
	else if (coord->dir.y >= 0.90 && coord->dir.y <= 1)
		return (WEST);
	else if (coord->dir.y <= -0.90 && coord->dir.y >= -1)
		return (EAST);
	return (-1);
}

/*
Changes the door img when we try to break it
*/
void	ft_handle_door_state(t_game *data, int keycode)
{
	t_ray	*coord;
	char	**map;
	int		dir;

	coord = &data->coord;
	map = data->map.map;
	dir = ft_get_dir(coord);
	if (dir >= 0)
		ft_in_front_door(coord, dir, map, keycode);
}
