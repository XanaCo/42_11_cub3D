/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:58:36 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/13 20:35:21 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Initializes and checks if wall images are good to print
*/
void	add_wall_texture(t_game *data, char *line)
{
	if (!ft_strncmp(line, "NO", 2) && !data->map.no_texture.img
		&& init_texture(data, &(data->map.no_texture), &line[2]))
		exit_failure(data, "Invalid North wall texture\n", -2);
	if (!ft_strncmp(line, "SO", 2) && !data->map.so_texture.img
		&& init_texture(data, &(data->map.so_texture), &line[2]))
		exit_failure(data, "Invalid South wall texture\n", -2);
	if (!ft_strncmp(line, "EA", 2) && !data->map.ea_texture.img
		&& init_texture(data, &(data->map.ea_texture), &line[2]))
		exit_failure(data, "Invalid East wall texture\n", -2);
	if (!ft_strncmp(line, "WE", 2) && !data->map.we_texture.img
		&& init_texture(data, &(data->map.we_texture), &line[2]))
		exit_failure(data, "Invalid West wall texture\n", -2);
}

/*
Initializes and checks if ceiling images are good to print
*/
void	add_floor_ceiling_texture(t_game *data, char *line)
{
	if (!ft_strncmp(line, "C", 1) && !data->map.c_texture.img
		&& init_texture(data, &(data->map.c_texture), &line[1]))
		exit_failure(data, "Invalid ceiling texture\n", -2);
	if (!ft_strncmp(line, "F", 1) && !data->map.f_texture.img
		&& init_texture(data, &(data->map.f_texture), &line[1]))
		exit_failure(data, "Invalid floor texture\n", -2);
}

/*
Initializes and checks if static door images are good to print
*/
void	add_door_texture(t_game *data, char *line)
{
	if (!ft_strncmp(line, "PNS", 3) && !data->map.pns1_texture.img
		&& init_texture(data, &(data->map.pns1_texture), &line[3]))
		exit_failure(data, "Invalid North / South door texture\n", -2);
	if (!ft_strncmp(line, "PWE", 3) && !data->map.pwe1_texture.img
		&& init_texture(data, &(data->map.pwe1_texture), &line[3]))
		exit_failure(data, "Invalid East / West door texture\n", -2);
	if (!ft_strncmp(line, "ELE", 3) && !data->map.ele_texture.img
		&& init_texture(data, &(data->map.ele_texture), &line[3]))
		exit_failure(data, "Invalid elevator texture\n", -2);
}

/*
Initializes and checks if bear door and final door images are good to print
*/
void	add_surprise_texture(t_game *data, char *line)
{
	if (!ft_strncmp(line, "B", 1) && !data->map.b_texture.img
		&& init_texture(data, &(data->map.b_texture), &line[1]))
		exit_failure(data, "Invalid Surprise door texture\n", -2);
	if (!ft_strncmp(line, "X", 1) && !data->map.x_texture.img
		&& init_texture(data, &(data->map.x_texture), &line[1]))
		exit_failure(data, "Invalid Final door texture\n", -2);
}

/*
Initializes and checks if sprites images are good to print
*/
void	add_characters_texture(t_game *data, char *line)
{
	if (!ft_strncmp(line, "T", 1) && !data->map.t1_texture.img
		&& init_texture(data, &(data->map.t1_texture), &line[1]))
		exit_failure(data, "Invalid Sprite texture\n", -2);
	if (!ft_strncmp(line, "D", 1) && !data->map.d1_texture.img
		&& init_texture(data, &(data->map.d1_texture), &line[1]))
		exit_failure(data, "Invalid Sprite texture\n", -2);
}
