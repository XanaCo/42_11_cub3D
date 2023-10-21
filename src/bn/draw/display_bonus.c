/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:04:14 by atardif           #+#    #+#             */
/*   Updated: 2023/10/15 14:42:35 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Function that call the different functions used to draw pixels 
on the image before puting it on window
*/
void	ft_display(t_game *data)
{
	render_background(data, &data->back, &data->coord, &data->map);
	ft_raycasting(data, 0);
	ft_raycasting(data, 1);
	ft_draw_sprites(data, &data->coord, data->sprite, &data->spdraw);
	load_weapon(data);
	ft_draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->main_img.img, 0, 0);
}
