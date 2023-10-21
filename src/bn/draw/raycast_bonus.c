/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:04:44 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 20:31:28 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Set the dir of the ray projected
*/
void	ft_set_ray_dir(t_ray *p, int x)
{
	p->camera_x = 2 * x / (double)WIN_W - 1;
	p->raydir = sum_coord(p->dir, prod_coord(p->plane, p->camera_x));
	p->map.x = (int)p->pos.x;
	p->map.y = (int)p->pos.y;
	p->deltadist = abs_coord(p->raydir);
	if (p->raydir.x < 0)
	{
		p->step.x = -1;
		p->sidedist.x = (p->pos.x - p->map.x) * p->deltadist.x;
	}
	else
	{
		p->step.x = 1;
		p->sidedist.x = (p->map.x + 1.0 - p->pos.x) * p->deltadist.x;
	}
	if (p->raydir.y < 0)
	{
		p->step.y = -1;
		p->sidedist.y = (p->pos.y - p->map.y) * p->deltadist.y;
	}
	else
	{
		p->step.y = 1;
		p->sidedist.y = (p->map.y + 1.0 - p->pos.y) * p->deltadist.y;
	}
}

/*
Function that will define the side macro of the obstacle hit according to 
the side (x, y) and direction of the ray
*/
void	ft_get_side(t_ray *p)
{
	if (p->sidedist.x < p->sidedist.y && p->step.x >= 0)
	{
		p->sidedist.x += p->deltadist.x;
		p->map.x += p->step.x;
		p->side = NORTH;
	}
	else if (p->sidedist.x < p->sidedist.y && p->step.x < 0)
	{
		p->sidedist.x += p->deltadist.x;
		p->map.x += p->step.x;
		p->side = SOUTH;
	}
	else if (p->sidedist.x > p->sidedist.y && p->step.y >= 0)
	{
		p->sidedist.y += p->deltadist.y;
		p->map.y += p->step.y;
		p->side = WEST;
	}
	else
	{
		p->sidedist.y += p->deltadist.y;
		p->map.y += p->step.y;
		p->side = EAST;
	}
}

/*
Function that identify that an obstacle is hit by the ray 
and return the good texture index
*/
bool	ft_identify_obstacle(char obs, t_game *data, int i)
{
	if (obs == '0' || obs == '9')
		return (false);
	if (obs == '1')
		return (ft_get_wall_side(&data->coord.side, &data->coord.tex_i), true);
	if (obs == 'B')
		return (data->coord.tex_i = BEAR_T, true);
	if (i == 1)
	{
		if ((obs == 'P' || obs == 'Q' || obs == 'R' || obs == 'S'))
			return (ft_get_door_side(&data->coord.side,
					&data->coord.tex_i, obs), true);
		if (obs == 'A')
			return (data->coord.tex_i = ELE_D, true);
		if (obs == 'D')
			return (data->coord.tex_i = C_D1, true);
		if (obs == 'T')
			return (data->coord.tex_i = C_T1, true);
		if (obs == 'B')
			return (data->coord.tex_i = BEAR_T, true);
		if (obs == 'X')
			return (data->coord.tex_i = EXIT_T, true);
	}
	return (false);
}

/*
Function that will get the size of the wall drawn in a given pixel column
*/
void	ft_get_wall_size(t_ray *p)
{
	if (p->side == NORTH || p->side == SOUTH)
		p->perp_w_dist = (p->sidedist.x - p->deltadist.x);
	else
		p->perp_w_dist = (p->sidedist.y - p->deltadist.y);
	p->line_height = (int)(WIN_H / p->perp_w_dist);
	p->draw.start = -p->line_height / 2 + WIN_H / 2;
	if (p->draw.start < 0)
		p->draw.start = 0;
	p->draw.end = p->line_height / 2 + WIN_H / 2;
	if (p->draw.end >= WIN_H)
		p->draw.end = WIN_H - 1;
}

/*
Function that will draw the walls on screen using raycasting
*/
void	ft_raycasting(t_game *data, int i)
{
	t_ray	*p;
	int		x;

	x = 0;
	p = &data->coord;
	while (x < WIN_W)
	{
		ft_set_ray_dir(p, x);
		p->hit = 0;
		while (p->hit == 0)
		{
			ft_get_side(p);
			if (ft_identify_obstacle(data->map.map[p->map.x][p->map.y],
				data, i))
				p->hit = 1;
		}
		ft_get_wall_size(p);
		ft_draw_walls(data, p, x, p->tex_i);
		data->coord.dist_tab[x] = data->coord.perp_w_dist;
		x++;
	}
}
