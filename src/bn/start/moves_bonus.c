/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:13:10 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 20:40:17 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Takes the event and transforms it into movement
*/
void	set_moves(t_game *data, double *mov_x, double *mov_y)
{
	if (data->key.key_w == 1)
	{
		*mov_x += data->coord.dir.x / MOV_SPEED;
		*mov_y += data->coord.dir.y / MOV_SPEED;
	}
	if (data->key.key_s == 1)
	{
		*mov_x -= data->coord.dir.x / MOV_SPEED;
		*mov_y -= data->coord.dir.y / MOV_SPEED;
	}
	if (data->key.key_a == 1)
	{
		*mov_x -= data->coord.plane.x / MOV_SPEED;
		*mov_y -= data->coord.plane.y / MOV_SPEED;
	}
	if (data->key.key_d == 1)
	{
		*mov_x += data->coord.plane.x / MOV_SPEED;
		*mov_y += data->coord.plane.y / MOV_SPEED;
	}
}

/*
Checks if we walk into a wall
*/
bool	ft_walk(char walk)
{
	if (walk == '0' || walk == '9')
		return (true);
	return (false);
}

/*
Checks all the possible coordinates to avoid bumping into walls
*/
bool	ft_check_all_coords(float new_coord, char **map, t_points *coord, int i)
{
	if (i)
	{
		if (ft_walk(map[(int)(new_coord + 0.15)][(int)(coord->y + 0.15)])
			&& ft_walk(map[(int)(new_coord + 0.15)][(int)(coord->y - 0.15)])
			&& ft_walk(map[(int)(new_coord - 0.15)][(int)(coord->y + 0.15)])
			&& ft_walk(map[(int)(new_coord - 0.15)][(int)(coord->y - 0.15)]))
			return (true);
	}
	else
	{
		if (ft_walk(map[(int)(coord->x + 0.15)][(int)(new_coord + 0.15)])
			&& ft_walk(map[(int)(coord->x - 0.15)][(int)(new_coord + 0.15)])
			&& ft_walk(map[(int)(coord->x + 0.15)][(int)(new_coord - 0.15)])
			&& ft_walk(map[(int)(coord->x - 0.15)][(int)(new_coord - 0.15)]))
			return (true);
	}
	return (false);
}

/*
Checks if the movement is possible, if it is, it moves
*/
void	get_move(t_game *data)
{
	double	mov_x;
	double	mov_y;
	t_ray	*coord;

	mov_x = 0.0;
	mov_y = 0.0;
	coord = &data->coord;
	set_moves(data, &mov_x, &mov_y);
	if (ft_check_all_coords(coord->pos.x + mov_x,
			data->map.map, &coord->pos, 1))
		data->coord.pos.x += mov_x;
	if (ft_check_all_coords(coord->pos.y + mov_y,
			data->map.map, &coord->pos, 0))
		data->coord.pos.y += mov_y;
	return ;
}

/*
Rotates our cone of view. This movement is always possible, no checks needed
*/
void	get_rotation(t_game *data)
{
	if (data->key.right == 1)
	{
		data->coord.dir = rotate(data->coord.dir, (-0.1 / ROT_SPEED));
		data->coord.plane = rotate(data->coord.plane, (-0.1 / ROT_SPEED));
		data->coord.screen_dir = rotate(data->coord.screen_dir,
				(-0.1 / ROT_SPEED));
	}
	if (data->key.left == 1)
	{
		data->coord.dir = rotate(data->coord.dir, (0.1 / ROT_SPEED));
		data->coord.plane = rotate(data->coord.plane, (0.1 / ROT_SPEED));
		data->coord.screen_dir = rotate(data->coord.screen_dir,
				(0.1 / ROT_SPEED));
	}
}
