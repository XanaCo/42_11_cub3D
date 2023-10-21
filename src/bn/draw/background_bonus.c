/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:58:47 by atardif           #+#    #+#             */
/*   Updated: 2023/10/15 15:39:31 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Init the data used to draw background in perspective
*/
static void	ft_set_scanline(t_back *back, t_ray *coord, int y)
{
	back->ray_dir_a.x = coord->dir.x - coord->plane.x;
	back->ray_dir_a.y = coord->dir.y - coord->plane.y;
	back->ray_dir_b.x = coord->dir.x + coord->plane.x;
	back->ray_dir_b.y = coord->dir.y + coord->plane.y;
	back->p = y - WIN_H / 2;
	back->pos_z = 0.5 * WIN_H;
	back->row_dist = back->pos_z / back->p;
	back->floor_step.x = back->row_dist * (back->ray_dir_b.x
			- back->ray_dir_a.x) / WIN_W;
	back->floor_step.y = back->row_dist * (back->ray_dir_b.y
			- back->ray_dir_a.y) / WIN_W;
	back->floor.x = coord->pos.x + back->row_dist * back->ray_dir_a.x;
	back->floor.y = coord->pos.y + back->row_dist * back->ray_dir_a.y;
}

/*
Function that get the good pixel in the texture according
to position of pixel on screen
*/
static void	ft_set_back_tex(t_back *back)
{
	back->cell.x = (int)(back->floor.x);
	back->cell.y = (int)(back->floor.y);
	back->tex.x = ((int)(TEX_W * (back->floor.x - back->cell.x))) & (TEX_W - 1);
	back->tex.y = ((int)(TEX_H * (back->floor.y - back->cell.y))) & (TEX_H - 1);
	back->floor.x += back->floor_step.x;
	back->floor.y += back->floor_step.y;
}	

/*
Function that draw the floor and the ceiling as horizontal lines
*/
void	render_background(t_game *data, t_back *back, t_ray *coord, t_map *map)
{
	int		y;
	int		x;
	char	*pixel;

	y = -1;
	while (++y < WIN_H)
	{
		ft_set_scanline(back, coord, y);
		x = -1;
		while (++x < WIN_W)
		{
			ft_set_back_tex(back);
			pixel = map->r_tab[FLOOR_T].addr + (int)((back->tex.y
						* map->r_tab[FLOOR_T].size_line) + (back->tex.x
						* (map->r_tab[FLOOR_T].bpp / 8)));
			coord->color = *(int *)pixel;
			ft_img_pix_put(&data->main_img, x, y, coord->color);
			pixel = map->r_tab[CEIL_T].addr + (int)((back->tex.y
						* map->r_tab[CEIL_T].size_line) + (back->tex.x
						* (map->r_tab[CEIL_T].bpp / 8)));
			coord->color = *(int *)pixel;
			ft_img_pix_put(&data->main_img, x, WIN_H - y - 1, coord->color);
		}
	}
}
