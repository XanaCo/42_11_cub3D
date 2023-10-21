/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:11:06 by atardif           #+#    #+#             */
/*   Updated: 2023/10/04 17:56:37 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D.h"

/*
Fills the img with pixels and
prints the images on the screen
*/
void	ft_display(t_game *data)
{
	render_background(data);
	ft_raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->main_img.img, 0, 0);
}
