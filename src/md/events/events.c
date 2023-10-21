/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:53:48 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/13 16:05:19 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D.h"

/*
Checks if any of the keys has been pressed and changes its value
*/
int	key_press_handler(int keycode, t_game *data)
{
	if (keycode == ESC || keycode == QUIT)
		exit_succes(data);
	if (keycode == W)
		data->key.key_w = 1;
	if (keycode == A)
		data->key.key_a = 1;
	if (keycode == S)
		data->key.key_s = 1;
	if (keycode == D)
		data->key.key_d = 1;
	if (keycode == F_RIGHT)
		data->key.right = 1;
	if (keycode == F_LEFT)
		data->key.left = 1;
	return (0);
}

/*
Checks if any of the keys has been released and changes its value
*/
int	key_release_handler(int keycode, t_game *data)
{
	if (keycode == W)
		data->key.key_w = 0;
	if (keycode == A)
		data->key.key_a = 0;
	if (keycode == S)
		data->key.key_s = 0;
	if (keycode == D)
		data->key.key_d = 0;
	if (keycode == F_RIGHT)
		data->key.right = 0;
	if (keycode == F_LEFT)
		data->key.left = 0;
	return (0);
}
