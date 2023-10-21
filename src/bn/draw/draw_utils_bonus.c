/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:12:59 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 18:45:56 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Checks if the pixel position is in the size of the texture and gets its color
*/
int	mlx_sprite_get_pixel_color(t_img *spr, int x, int y)
{
	if (x < 0 || x >= spr->width || y < 0 || y >= spr->height)
		return (-1);
	return (*(int *)(spr->addr + (x * (spr->bpp / 8)
			+ y * spr->size_line)));
}

/*
Puts the chosen color into the wanted pixel
*/
int	mlx_sprite_pixel_put(t_img *spr, t_px point)
{
	char	*pixel;

	if (((unsigned char *)&point.color)[3] == 255)
		return (1);
	pixel = spr->addr + (point.y * spr->size_line
			+ point.x * (spr->bpp / 8));
	*(unsigned int *)pixel = point.color;
	return (0);
}
