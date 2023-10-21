/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_danny_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:28:40 by atardif           #+#    #+#             */
/*   Updated: 2023/10/15 15:17:55 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Converts the angle we got
*/
static double	convert_angle(double angle)
{
	if (angle < 0)
		return (convert_angle(2 * 3.14159 + angle));
	else if (angle >= 2 * 3.14159)
		return (convert_angle(angle - 2 * 3.14159));
	else
		return (angle);
}

/*
Searches the angle of the direction between danny and the player
*/
static double	get_angle_danny(t_game *data, t_points danny)
{
	double	ang;

	ang = atan2((danny.y - data->coord.pos.y), danny.x - data->coord.pos.x);
	return (ang);
}

/*
Sets the direction of the movement 01 int he main structure
(25 line max alowed functions)
*/
static void	get_dir_danny_02(t_sprites *danny, double ang)
{
	if (ang > 0 && ang < 3.14159 / 2)
	{
		danny->dir.x = cos(ang);
		danny->dir.y = -sin(ang);
	}
	if (ang > 3.14159 / 2 && ang < 3.14159)
	{
		danny->dir.x = -cos(3.14159 - ang);
		danny->dir.y = -sin(3.14159 - ang);
	}
	if (ang > 3.14159 && ang < 3 * 3.14159 / 2)
	{
		danny->dir.x = -cos(ang - 3.14159);
		danny->dir.y = sin(ang - 3.14159);
	}
	if (ang > 3 * 3.14159 / 2 && ang < 2 * 3.14159)
	{
		danny->dir.x = cos(2 * 3.14159 - ang);
		danny->dir.y = sin(2 * 3.14159 - ang);
	}
}

/*
Sets the direction of the movement 01 int he main structure
(25 line max alowed functions)
*/
static void	get_dir_danny_01(t_sprites *danny, double ang)
{
	if (ang == 0)
		danny->dir.x = 1;
	if (ang == 3.14159)
		danny->dir.x = -1;
	if (ang == 3.14159 / 2)
		danny->dir.y = -1;
	if (ang == 3 * 3.14159 / 2)
		danny->dir.y = 1;
	else
		get_dir_danny_02(danny, ang);
}

/*
The algorithm that makes danny follow the coordinates
of the player or makes him stop if he is too close
*/
void	danny_follows(t_game *data)
{
	t_sprites	*danny;

	danny = &data->sprite[D_SPRITE];
	danny->dist = fabs(dist_points(data->coord.pos, danny->pos));
	if (!danny->anim)
		return ;
	if (danny->dist >= 1)
	{
		danny->ang = convert_angle(get_angle_danny(data, danny->pos));
		get_dir_danny_01(danny, danny->ang);
		danny->new_pos.x = danny->dir.x / (MOV_SPEED * 2);
		danny->new_pos.y = danny->dir.y / (MOV_SPEED * 2);
		if (ft_check_all_coords(danny->pos.x - danny->new_pos.x,
				data->map.map, &danny->pos, 1))
			danny->pos.x -= danny->new_pos.x;
		if (ft_check_all_coords(danny->pos.y + danny->new_pos.y,
				data->map.map, &danny->pos, 0))
			danny->pos.y += danny->new_pos.y;
	}
	if (danny->dist < 1)
	{	
		danny->anim = 0;
		return ;
	}
}
