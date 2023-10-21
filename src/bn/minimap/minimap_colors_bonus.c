/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_colors_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:28:01 by atardif           #+#    #+#             */
/*   Updated: 2023/10/15 13:23:01 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Checks the textures and chooses the palette accordingly
*/
t_color	get_palette(t_game *data)
{
	t_color	c;

	if (data->colors == 1)
	{
		c.floor = 8388631;
		c.wall = 16119285;
		c.door = 16747520;
		c.b_door = 16767093;
		c.ext = 12039866;
		c.end = 2955857;
	}
	else
	{
		c.floor = 865070;
		c.wall = 16119285;
		c.door = 16747520;
		c.b_door = 16767093;
		c.ext = 12039866;
		c.end = 8388631;
	}
	return (c);
}
