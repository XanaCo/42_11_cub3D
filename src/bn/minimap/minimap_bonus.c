/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:28:01 by atardif           #+#    #+#             */
/*   Updated: 2023/10/15 13:22:56 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Checks if the given coordinates are inside the map
*/
static int	is_map(t_game *data, t_points pos)
{
	if (pos.x < 0 || pos.y < 0)
		return (0);
	if (pos.x > data->map.map_w - 1)
		return (0);
	if (pos.y > data->map.map_h - 1)
		return (0);
	return (1);
}

/*
Initializes some of the minimap fix data
*/
static void	init_minimap(t_game *data, t_mini *map)
{
	map->height = 175;
	map->width = 175;
	map->case_size = 14;
	map->center.x = map->width / 2;
	map->center.y = map->height / 2;
	map->pl_pos.x = map->width / 2;
	map->pl_pos.y = 0;
	map->c_dist = dist_coord(map->pl_pos, map->center);
	map->case_zero.x = data->coord.pos.x - (double)map->center.x / 14;
	map->case_zero.y = data->coord.pos.y - (double)map->center.y / 14;
}

/*
Checks the coordinates and puts the right color in
*/
static void	check_and_print_minimap(t_game *data, t_points pos, t_coord px)
{
	t_color	c;

	c = get_palette(data);
	if (is_map(data, pos) && data->map.map[(int)pos.y][(int)pos.x] == '1')
		ft_img_pix_put(&(data->main_img), px.y + 10, px.x + 10, c.wall);
	else if (is_map(data, pos) && data->map.map[(int)pos.y][(int)pos.x] == '2')
		ft_img_pix_put(&(data->main_img), px.y + 10, px.x + 10, c.ext);
	else if (is_map(data, pos) && data->map.map[(int)pos.y][(int)pos.x] == 'X')
		ft_img_pix_put(&(data->main_img), px.y + 10, px.x + 10, 98);
	else if (is_map(data, pos) && data->map.map[(int)pos.y][(int)pos.x] == 'P')
		ft_img_pix_put(&(data->main_img), px.y + 10, px.x + 10, c.door);
	else if (is_map(data, pos) && (data->map.map[(int)pos.y][(int)pos.x] == 'Q'
		|| data->map.map[(int)pos.y][(int)pos.x] == 'R'
		|| data->map.map[(int)pos.y][(int)pos.x] == 'S'
		|| data->map.map[(int)pos.y][(int)pos.x] == 'B'
		|| data->map.map[(int)pos.y][(int)pos.x] == 'A'))
		ft_img_pix_put(&(data->main_img), px.y + 10, px.x + 10, c.b_door);
	else if (is_map(data, pos) && (data->map.map[(int)pos.y][(int)pos.x] == '0'
		|| data->map.map[(int)pos.y][(int)pos.x] == '9'))
		ft_img_pix_put(&(data->main_img), px.y + 10, px.x + 10, c.floor);
}

/*
Prints a square in the middle of the circle
*/
static void	print_player(t_game *data, t_mini *map)
{
	t_coord	player;
	int		i;
	int		j;

	player.x = map->center.x + 7;
	player.y = map->center.y + 7;
	i = 0;
	while (i < map->case_size)
	{
		j = 0;
		while (j < map->case_size)
		{
			ft_img_pix_put(&(data->main_img),
				player.y + j / 2, player.x + i / 2, 16777215);
			j++;
		}
		i++;
	}
}

/*
Calls all function to print the minimap to the window
*/
void	ft_draw_minimap(t_game *data)
{
	t_mini		map;
	t_coord		px_iter;
	t_points	pos;

	init_minimap(data, &map);
	px_iter.y = 0;
	while (px_iter.y < map.height)
	{
		px_iter.x = 0;
		while (px_iter.x < map.width)
		{
			pos.y = map.case_zero.x + (double)px_iter.x / map.case_size;
			pos.x = map.case_zero.y + (double)px_iter.y / map.case_size;
			if (dist_coord(px_iter, map.center) < map.c_dist - 2)
				check_and_print_minimap(data, pos, px_iter);
			px_iter.x++;
		}
		px_iter.y++;
	}
	print_player(data, &map);
}
