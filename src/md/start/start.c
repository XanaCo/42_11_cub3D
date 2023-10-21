/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:58:36 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/13 16:12:18 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D.h"

/*
Starts the program, launches mlx loop and hooks
*/
void	start_game(t_game *data)
{
	mlx_hook(data->win, 17, (1L << 0), exit_succes, (void *)data);
	mlx_hook(data->win, 2, 1L << 0, key_press_handler, (void *)data);
	mlx_hook(data->win, 3, 1L << 1, key_release_handler, (void *)data);
	mlx_loop_hook(data->mlx, update_game, (void *)data);
	mlx_loop(data->mlx);
}

/*
Game loop, where the magic loops
*/
int	update_game(t_game *data)
{
	data->loops++;
	if (data->loops > RATE)
		data->loops = 0;
	get_move(data);
	get_rotation(data);
	ft_display(data);
	return (0);
}

/*
Takes the event and transforms it into movement
*/
void	set_moves(t_game *data, double *mov_x, double *mov_y)
{
	if (data->key.key_w == 1)
	{
		*mov_x += data->coord.dir.x / MOV_SPEED;
		*mov_y += data->coord.dir.y / MOV_SPEED;
	}
	if (data->key.key_s == 1)
	{
		*mov_x -= data->coord.dir.x / MOV_SPEED;
		*mov_y -= data->coord.dir.y / MOV_SPEED;
	}
	if (data->key.key_a == 1)
	{
		*mov_x -= data->coord.plane.x / MOV_SPEED;
		*mov_y -= data->coord.plane.y / MOV_SPEED;
	}
	if (data->key.key_d == 1)
	{
		*mov_x += data->coord.plane.x / MOV_SPEED;
		*mov_y += data->coord.plane.y / MOV_SPEED;
	}
}

/*
Checks if the movement is possible, if it is, it moves
*/
void	get_move(t_game *data)
{
	double	mov_x;
	double	mov_y;

	mov_x = 0.0;
	mov_y = 0.0;
	set_moves(data, &mov_x, &mov_y);
	if (data->map.map[(int)(data->coord.pos.x + mov_x)] \
		[(int)(data->coord.pos.y)] == '0')
		data->coord.pos.x += mov_x;
	if (data->map.map[(int)(data->coord.pos.x)] \
		[(int)(data->coord.pos.y + mov_y)] == '0')
		data->coord.pos.y += mov_y;
}

/*
Rotates our cone of view. This movement is always possible, no checks needed
*/
void	get_rotation(t_game *data)
{
	if (data->key.right == 1)
	{
		data->coord.dir = rotate(data->coord.dir, (-0.1 / ROT_SPEED));
		data->coord.plane = rotate(data->coord.plane, (-0.1 / ROT_SPEED));
		data->coord.screen_dir = rotate(data->coord.screen_dir,
				(-0.1 / ROT_SPEED));
	}
	if (data->key.left == 1)
	{
		data->coord.dir = rotate(data->coord.dir, (0.1 / ROT_SPEED));
		data->coord.plane = rotate(data->coord.plane, (0.1 / ROT_SPEED));
		data->coord.screen_dir = rotate(data->coord.screen_dir,
				(0.1 / ROT_SPEED));
	}
}
