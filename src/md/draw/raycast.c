/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:58:26 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 18:26:02 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D.h"

/*
Sets the direction of the raycast ray
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
Searches for the wall side to choose the right texture
*/
void	ft_get_wall_side(t_ray *p)
{
	if (p->sidedist.x < p->sidedist.y && p->step.x >= 0)
	{
		p->sidedist.x += p->deltadist.x;
		p->map.x += p->step.x;
		p->side = NORTH_T;
	}
	else if (p->sidedist.x < p->sidedist.y && p->step.x < 0)
	{
		p->sidedist.x += p->deltadist.x;
		p->map.x += p->step.x;
		p->side = SOUTH_T;
	}
	else if (p->sidedist.x > p->sidedist.y && p->step.y >= 0)
	{
		p->sidedist.y += p->deltadist.y;
		p->map.y += p->step.y;
		p->side = WEST_T;
	}
	else
	{
		p->sidedist.y += p->deltadist.y;
		p->map.y += p->step.y;
		p->side = EAST_T;
	}
}

/*
Calculates the wall size to print correctly
*/
void	ft_get_wall_size(t_ray *p)
{
	if (p->side == NORTH_T || p->side == SOUTH_T)
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
Main raycast function to print walls
*/
void	ft_raycasting(t_game *data)
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
			ft_get_wall_side(p);
			if (data->map.map[p->map.x][p->map.y] == '1')
				p->hit = 1;
		}
		ft_get_wall_size(p);
		ft_draw_walls(data, &data->coord, x, p->side);
		x++;
	}
}
