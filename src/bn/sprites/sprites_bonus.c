/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:29:18 by atardif           #+#    #+#             */
/*   Updated: 2023/10/15 15:38:59 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Get the distance between player and both sprites and sort 
it in order to know which one shall be drawn first
*/
void	ft_sort_sprites(double *sp_dist, int *sp_order,
		t_ray *coord, t_sprites *sp)
{
	int		i;

	i = 0;
	while (i <= 1)
	{
		sp_dist[i] = ((coord->pos.x - sp[i].pos.x)
				* (coord->pos.x - sp[i].pos.x)
				+ (coord->pos.y - sp[i].pos.y) * (coord->pos.y - sp[i].pos.y));
		i++;
	}
	if (sp_dist[0] < sp_dist[1])
	{
		sp_order[0] = 1;
		sp_order[1] = 0;
	}
	else
	{
		sp_order[0] = 0;
		sp_order[1] = 1;
	}
}

/*
Init data in order to draw sprites on screen
*/
void	ft_set_sprite_points(t_ray *coord, t_sprites sp[], t_spdraw *sd, int i)
{
	sd->sprite.x = sp[sd->sp_order[i]].pos.x - coord->pos.x;
	sd->sprite.y = sp[sd->sp_order[i]].pos.y - coord->pos.y;
	sd->inv_det = 1.0 / (coord->plane.x * coord->dir.y - coord->dir.x
			* coord->plane.y);
	sd->transform.x = sd->inv_det * (coord->dir.y * sd->sprite.x - coord->dir.x
			* sd->sprite.y);
	sd->transform.y = sd->inv_det * (-coord->plane.y * sd->sprite.x
			+ coord->plane.x * sd->sprite.y);
	sd->sprite_screen_x = (int)((WIN_W / 2) * (1 + sd->transform.x
				/ sd->transform.y));
	sd->sprite_height = abs((int)(WIN_H / sd->transform.y));
	sd->draw_start.y = -sd->sprite_height / 2 + WIN_H / 2;
	if (sd->draw_start.y < 0)
		sd->draw_start.y = 0;
	sd->draw_end.y = sd->sprite_height / 2 + WIN_H / 2;
	if (sd->draw_end.y >= WIN_H)
		sd->draw_end.y = WIN_H - 1;
	sd->sprite_width = abs((int)(WIN_H / sd->transform.y));
	sd->draw_start.x = -sd->sprite_width / 2 + sd->sprite_screen_x;
	if (sd->draw_start.x < 0)
		sd->draw_start.x = 0;
	sd->draw_end.x = sd->sprite_width / 2 + sd->sprite_screen_x;
	if (sd->draw_end.x >= WIN_W)
		sd->draw_end.x = WIN_W - 1;
}

/*
Put the pixels in sprites on screen
*/
void	ft_draw_sprites_points(t_game *data, t_sprites sp[], t_spdraw *sd)
{
	char	*pixel;
	int		color;

	data->sprite[D_SPRITE].anim = 1;
	sd->y = sd->draw_start.y;
	while (sd->y < sd->draw_end.y)
	{
		sd->d = (sd->y) * 256 - WIN_H * 128 + sd->sprite_height * 128;
		sd->tex.y = ((sd->d * TEX_H) / sd->sprite_height) / 256;
		if (!data->rev_text && sp[sd->sp_order[sd->i]].id == 'D'
			&& sp[sd->sp_order[sd->i]].dist > 1)
			pixel = (sp[sd->sp_order[sd->i]].texture.addr
					+ (int)((sd->tex.y * sp[sd->sp_order[sd->i]]
							.texture.size_line) + (WIN_W - sd->tex.x
							* sp[sd->sp_order[sd->i]].texture.bpp / 8)));
		else
			pixel = (sp[sd->sp_order[sd->i]].texture.addr
					+ (int)((sd->tex.y * sp[sd->sp_order[sd->i]]
							.texture.size_line) + (sd->tex.x
							* sp[sd->sp_order[sd->i]].texture.bpp / 8)));
		color = *(int *)pixel;
		if ((color & 0x00FFFFFF) != 0)
			ft_img_pix_put(&data->main_img, sd->stripe, sd->y, color);
		sd->y++;
	}
}

/*
Tries to draw sprites (further then closer), only if it's in our
view plane and located between a wall and us
*/
void	ft_draw_sprites(t_game *data, t_ray *coord, t_sprites sp[],
		t_spdraw *sd)
{
	sd->i = 0;
	ft_sort_sprites(sd->sp_dist, sd->sp_order, coord, sp);
	while (sd->i <= 1)
	{
		ft_set_sprite_points(coord, sp, sd, sd->i);
		sd->stripe = sd->draw_start.x;
		while (sd->stripe < sd->draw_end.x)
		{
			sd->tex.x = (int)(256 * (sd->stripe - (-sd->sprite_width / 2
							+ sd->sprite_screen_x)) * TEX_W
					/ sd->sprite_width) / 256;
			if (sd->transform.y > 0 && sd->stripe > 0 && sd->stripe < WIN_W
				&& sd->transform.y < coord->dist_tab[sd->stripe])
				ft_draw_sprites_points(data, sp, sd);
			sd->stripe++;
		}
		sd->i++;
	}
}
