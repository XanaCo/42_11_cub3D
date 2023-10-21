/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:00:53 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 16:14:01 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D.h"

/*
Puts one pixel into the screen with a given color
*/
void	ft_img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + ((y * img->size_line) + (x * (img->bpp / 8)));
	*(int *)pixel = color;
}

/*
Inits all the data needed to rpint the wall in perspective
*/
void	ft_set_wall_points(t_tex *t, t_ray *coord, int side)
{
	if (side == NORTH_T || side == SOUTH_T)
		t->wall_x = coord->pos.y + coord->perp_w_dist * coord->raydir.y;
	else
		t->wall_x = coord->pos.x + coord->perp_w_dist * coord->raydir.x;
	t->wall_x -= floor(t->wall_x);
	t->tex.x = (int)(t->wall_x * (double)TEX_W);
	if ((side == NORTH_T || side == SOUTH_T) && coord->raydir.x > 0)
		t->tex.x = TEX_W - t->tex.x - 1;
	if ((side == EAST_T || side == WEST_T) && coord->raydir.y < 0)
		t->tex.x = TEX_W - t->tex.x - 1;
	t->t_step = 1.0 * TEX_H / coord->line_height;
	t->tex_pos = (coord->draw.start - WIN_H / 2 + coord->line_height / 2)
		* t->t_step;
}

/*
Searches for the pixel color of the texture
*/
int	ft_get_wall_color(t_game *data, t_tex *t, int side, char *pixel)
{
	t->tex.y = (int)t->tex_pos & (TEX_H - 1);
	t->tex_pos += t->t_step;
	pixel = data->map.r_tab[side].addr + (int)((t->tex.y
				* data->map.r_tab[side].size_line) + (t->tex.x
				* (data->map.r_tab[side].bpp / 8)));
	return (*(int *) pixel);
}

/*
Prints a vertical line of the texture wall
*/
void	ft_draw_walls(t_game *data, t_ray *coord, int x, int side)
{
	int		y;
	char	*pixel;
	t_tex	t;

	pixel = NULL;
	t = data->tex;
	ft_set_wall_points(&t, coord, side);
	y = coord->draw.start + 1;
	while (y <= coord->draw.end)
	{
		coord->color = ft_get_wall_color(data, &t, side, pixel);
		ft_img_pix_put(&data->main_img, x, y, coord->color);
		y++;
	}	
}

/*
Prints ground and sky color
*/
void	render_background(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			if (i < WIN_H / 2)
				ft_img_pix_put(&data->main_img, j, i, data->map.c_color);
			else
				ft_img_pix_put(&data->main_img, j, i, data->map.f_color);
			j++;
		}
		i++;
	}
}
