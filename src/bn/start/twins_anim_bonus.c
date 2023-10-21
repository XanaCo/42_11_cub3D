/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twins_anim_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:05:41 by atardif           #+#    #+#             */
/*   Updated: 2023/10/15 13:30:19 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Check if we are located two squares from the twins sprite
*/
bool	is_near_twins(t_ray *coord, t_sprites *sp)
{
	if (coord->pos.x >= sp->pos.x - 2 && coord->pos.x <= sp->pos.x + 2)
	{
		if (coord->pos.y >= sp->pos.y - 2 && coord->pos.y <= sp->pos.y + 2)
			return (true);
	}
	return (false);
}

/*
Put images to window according to time (Second part)
*/
int	second_anim_twins(t_game *data, t_map *map, t_sprites *sp)
{
	if (sp->anim >= 400 && sp->anim <= 500)
	{
		init_sprites(data, map->map, map->r_tab, C_T1);
		ft_display(data);
		if (sp->anim == 500)
		{
			sp->anim = 0;
			return (1);
		}
	}
	return (0);
}

/*
Put images to window according to time (First part)
*/
int	first_anim_twins(t_game *data, t_map *map, t_sprites *sp, int i)
{
	if (sp->anim < 150)
		mlx_put_image_to_window(data->mlx,
			data->win, map->r_tab[C_T2].img, 0, 0);
	if (sp->anim >= 150 && sp->anim < 250)
	{
		init_sprites(data, map->map, map->r_tab, C_T3);
		ft_display(data);
	}
	if (sp->anim >= 250 && sp->anim < 400)
	{	
		mlx_put_image_to_window(data->mlx, data->win,
			map->r_tab[C_T4].img, 0, 0);
		if (i == 1 && sp->anim == 399)
		{
			init_sprites(data, map->map, map->r_tab, C_TRANSP);
			return (1);
		}
	}
	return (0);
}

/*
Handle the animation when in front of twins
*/
void	twins_proximity(t_game *data, t_map *map, t_sprites *sp)
{
	static int	i = 0;

	if (i < 2)
	{
		if (first_anim_twins(data, map, sp, i))
			i++;
		if (second_anim_twins(data, map, sp))
			i++;
	}
}
