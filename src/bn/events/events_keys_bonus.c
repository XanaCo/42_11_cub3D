/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keys_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:06:25 by atardif           #+#    #+#             */
/*   Updated: 2023/10/15 14:48:00 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Checks if any of the keys has been pressed and changes its value
*/
int	key_press_handler(int keycode, t_game *data)
{
	if (keycode == ESC || keycode == QUIT)
		exit_succes(data);
	if (keycode == ENTER)
		data->start = 0;
	if (data->end || data->start)
		return (0);
	if (keycode == W)
		data->key.key_w = 1;
	if (keycode == A)
		data->key.key_a = 1;
	if (keycode == S)
		data->key.key_s = 1;
	if (keycode == D)
		data->key.key_d = 1;
	if (keycode == ESPACE)
		espace_handler(keycode, data);
	if (keycode == R)
		ft_handle_door_state(data, keycode);
	if (keycode == TWO)
		data->show_weapon = 1;
	if (keycode == F_RIGHT)
		data->key.right = 1;
	if (keycode == F_LEFT)
		data->key.left = 1;
	return (0);
}

/*
Handles the space key press
*/
void	espace_handler(int keycode, t_game *data)
{
	if (data->show_weapon && (!data->sprite[T_SPRITE].anim
			|| data->sprite[T_SPRITE].anim > 500))
	{
		ft_handle_door_state(data, keycode);
		data->key.espace = 1;
	}
	if (!data->show_weapon && is_237_door(data))
		data->end = 1;
}

/*
Checks if any of the keys has been pressed and changes its value
*/
int	key_release_handler(int keycode, t_game *data)
{
	if (data->end || data->start)
		return (0);
	if (keycode == W)
		data->key.key_w = 0;
	if (keycode == A)
		data->key.key_a = 0;
	if (keycode == S)
		data->key.key_s = 0;
	if (keycode == D)
		data->key.key_d = 0;
	if (keycode == ESPACE)
		data->key.espace = 0;
	if (keycode == ONE)
		data->show_weapon = 0;
	if (keycode == F_RIGHT)
		data->key.right = 0;
	if (keycode == F_LEFT)
		data->key.left = 0;
	return (0);
}
