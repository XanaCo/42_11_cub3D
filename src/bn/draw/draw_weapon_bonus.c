/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weapon_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:12:59 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 18:43:44 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Initializes all images of the axe
*/
void	init_weapon(t_game *data)
{
	data->weapon.img_1.img = mlx_xpm_file_to_image(data->mlx,
			W1_PATH,
			&data->weapon.img_1.width,
			&data->weapon.img_1.height);
	data->weapon.img_2.img = mlx_xpm_file_to_image(data->mlx,
			W2_PATH,
			&data->weapon.img_2.width,
			&data->weapon.img_2.height);
	data->weapon.img_3.img = mlx_xpm_file_to_image(data->mlx,
			W3_PATH,
			&data->weapon.img_3.width,
			&data->weapon.img_3.height);
	data->weapon.img_4.img = mlx_xpm_file_to_image(data->mlx,
			W4_PATH,
			&data->weapon.img_4.width,
			&data->weapon.img_4.height);
	add_img_to_tab(data, data->weapon.img_1.img);
	add_img_to_tab(data, data->weapon.img_2.img);
	add_img_to_tab(data, data->weapon.img_3.img);
	add_img_to_tab(data, data->weapon.img_4.img);
}

/*
Prints the axe in the screen if called
*/
void	load_weapon(t_game *data)
{
	t_px	px;
	t_img	*weapon;

	weapon = get_w_status(data);
	if (!weapon)
		return ;
	px.y = 0;
	while (px.y < weapon->height)
	{
		px.x = 0;
		while (px.x < weapon->width)
		{
			px.color = mlx_sprite_get_pixel_color(weapon, px.x, px.y);
			if (px.color >= 0)
				mlx_sprite_pixel_put(&(data->main_img), px);
			(px.x)++;
		}
		(px.y)++;
	}
}

/*
Chooses between the two images of the axe, low or high
*/
t_img	*get_w_status(t_game *data)
{
	if (data->show_weapon && data->key.espace)
		return (&(data->weapon.img_3));
	if (data->show_weapon)
		return (&(data->weapon.img_1));
	return (NULL);
}
