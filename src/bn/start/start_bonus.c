/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:13:10 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 20:42:01 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Starts the program, launches mlx loop and hooks
*/
void	start_game(t_game *data)
{
	mlx_hook(data->win, 17, (1L << 0), exit_succes, (void *)data);
	mlx_hook(data->win, 2, 1L << 0, key_press_handler, (void *)data);
	mlx_hook(data->win, 3, 1L << 1, key_release_handler, (void *)data);
	mlx_hook(data->win, 7, 1L << 4, enter_win, (void *)data);
	mlx_hook(data->win, 8, 1L << 5, leave_win, (void *)data);
	mlx_hook(data->win, 6, 1L << 6, mouse_handler, (void *)data);
	mlx_loop_hook(data->mlx, update_game, (void *)data);
	mlx_loop(data->mlx);
}

/*
Updates the loops of the game
*/
void	update_loops(t_game *data)
{
	data->loops++;
	if (data->loops > BIG_RATE)
		data->loops = 0;
	if (data->loops % 51 == 0)
	{
		if (data->rev_text == 0)
			data->rev_text = 1;
		else
			data->rev_text--;
	}
}

/*
Game loop, where the magic is done
*/
int	update_game(t_game *data)
{
	update_loops(data);
	if (data->start)
		load_screen_title(data);
	if (data->sprite[T_SPRITE].anim <= 500)
	{
		if (is_near_twins(&data->coord, &data->sprite[T_SPRITE]))
			data->sprite[T_SPRITE].anim++;
	}
	if (data->sprite[T_SPRITE].anim && data->sprite[T_SPRITE].anim <= 500)
		twins_proximity(data, &data->map, &data->sprite[T_SPRITE]);
	else if (data->end)
		ft_handle_final_door(data);
	else if (!data->end && !data->start)
	{
		get_move(data);
		get_rotation(data);
		danny_follows(data);
		ft_display(data);
	}
	return (0);
}
