/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:04:29 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 20:31:03 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Function that sets a pixel located at given coordinates
with the given color 
*/
void	ft_img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + ((y * img->size_line) + (x * (img->bpp / 8)));
	*(int *)pixel = color;
}

/*
FInit all the data needed to print the wall in perspective
*/
void	ft_set_wall_points(t_tex *t, t_ray *coord, int side)
{
	if (side == NORTH || side == SOUTH)
		t->wall_x = coord->pos.y + coord->perp_w_dist * coord->raydir.y;
	else
		t->wall_x = coord->pos.x + coord->perp_w_dist * coord->raydir.x;
	t->wall_x -= floor(t->wall_x);
	t->tex.x = (int)(t->wall_x * (double)TEX_W);
	if ((side == NORTH || side == SOUTH) && coord->raydir.x > 0)
		t->tex.x = TEX_W - t->tex.x - 1;
	if ((side == EAST || side == WEST) && coord->raydir.y < 0)
		t->tex.x = TEX_W - t->tex.x - 1;
	t->t_step = 1.0 * TEX_H / coord->line_height;
	t->tex_pos = (coord->draw.start - WIN_H / 2 + coord->line_height / 2)
		* t->t_step;
}

/*
Function that get the good pixel in the texture 
*/
int	ft_get_wall_color(t_game *data, t_tex *t, int tex_i, char *pixel)
{
	t->tex.y = (int)t->tex_pos & (TEX_H - 1);
	t->tex_pos += t->t_step;
	pixel = data->map.r_tab[tex_i].addr + (int)((t->tex.y
				* data->map.r_tab[tex_i].size_line) + (t->tex.x
				* (data->map.r_tab[tex_i].bpp / 8)));
	return (*(int *) pixel);
}

/*
Function used to draw the walls according to coordinate obtained before 
*/
void	ft_draw_walls(t_game *data, t_ray *coord, int x, int tex_i)
{
	int		y;
	char	*pixel;
	t_tex	t;

	pixel = NULL;
	t = data->tex;
	ft_set_wall_points(&t, coord, coord->side);
	y = coord->draw.start + 1;
	while (y <= coord->draw.end)
	{
		coord->color = ft_get_wall_color(data, &t, tex_i, pixel);
		if (((unsigned char *)&coord->color)[3] != 255)
			ft_img_pix_put(&data->main_img, x, y, coord->color);
		y++;
	}	
}
