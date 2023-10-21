/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:06:25 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 18:52:18 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Checks if the mouse pointer is in one of the two sides of the window
*/
int	mouse_handler(int x, int y, t_game *data)
{
	(void)y;
	if (data->end || data->start)
		return (0);
	if (data->in && (x <= WIN_W / 6 && x >= 0))
	{	
		data->key.left = 1;
		data->key.right = 0;
	}
	if (data->in && (x <= WIN_W && x >= (WIN_W - WIN_W / 6)))
	{	
		data->key.left = 0;
		data->key.right = 1;
	}
	if (data->in && (x > WIN_W / 6 && x < (WIN_W - WIN_W / 6)))
	{	
		data->key.left = 0;
		data->key.right = 0;
	}
	return (0);
}

/*
Updates value that tells us if the mouse pointer is in or out of the window
*/
int	enter_win(t_game *data)
{
	if (data->end || data->start)
		return (0);
	data->in = 1;
	return (0);
}

/*
Updates value that tells us if the mouse pointer is in or out of the window
*/
int	leave_win(t_game *data)
{
	if (data->end || data->start)
		return (0);
	data->in = 0;
	data->key.left = 0;
	data->key.right = 0;
	return (0);
}
