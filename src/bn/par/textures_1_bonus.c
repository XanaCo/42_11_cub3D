/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:58:36 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/13 20:35:40 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Calls all functions to add image textures
*/
void	add_texture_to_map(t_game *data, char *line)
{
	if (!line)
		exit_failure(data, "Invalid line\n", -2);
	add_wall_texture(data, line);
	add_floor_ceiling_texture(data, line);
	add_door_texture(data, line);
	add_surprise_texture(data, line);
	add_characters_texture(data, line);
}

/*
Calls all functions to add image sprites
*/
void	add_sprites_to_map(t_game *data)
{
	add_door_sprite_texture(data);
	add_characters_sprite_texture(data);
	add_weapon_sprite_texture(data);
	add_end_screen_texture(data);
}

/*
Initializes and checks if extra door images are good to print
*/
void	add_door_sprite_texture(t_game *data)
{
	if (!data->map.pns2_texture.img
		&& init_texture(data, &(data->map.pns2_texture), NS2_D_PATH))
		exit_failure(data, "Invalid NS2_D door texture\n", -2);
	if (!data->map.pns3_texture.img
		&& init_texture(data, &(data->map.pns3_texture), NS3_D_PATH))
		exit_failure(data, "Invalid NS3_D door texture\n", -2);
	if (!data->map.pns4_texture.img
		&& init_texture(data, &(data->map.pns4_texture), NS4_D_PATH))
		exit_failure(data, "Invalid NS4_D door texture\n", -2);
	if (!data->map.pwe2_texture.img
		&& init_texture(data, &(data->map.pwe2_texture), WE2_D_PATH))
		exit_failure(data, "Invalid WE2_D door texture\n", -2);
	if (!data->map.pwe3_texture.img
		&& init_texture(data, &(data->map.pwe3_texture), WE3_D_PATH))
		exit_failure(data, "Invalid WE3_D door texture\n", -2);
	if (!data->map.pwe4_texture.img
		&& init_texture(data, &(data->map.pwe4_texture), WE4_D_PATH))
		exit_failure(data, "Invalid WE4_D door texture\n", -2);
}

/*
Initializes and checks if extra sprite images are good to print
*/
void	add_characters_sprite_texture(t_game *data)
{
	if (!data->map.t0_texture.img
		&& init_texture(data, &(data->map.t0_texture), C_TRANSP_PATH))
		exit_failure(data, "Invalid T0 Sprite texture\n", -2);
	if (!data->map.t2_texture.img
		&& init_texture(data, &(data->map.t2_texture), C_T2_PATH))
		exit_failure(data, "Invalid T2 Sprite texture\n", -2);
	if (!data->map.t3_texture.img
		&& init_texture(data, &(data->map.t3_texture), C_T3_PATH))
		exit_failure(data, "Invalid T3 Sprite texture\n", -2);
	if (!data->map.t4_texture.img
		&& init_texture(data, &(data->map.t4_texture), C_T4_PATH))
		exit_failure(data, "Invalid T4 Sprite texture\n", -2);
	if (!data->map.d2_texture.img
		&& init_texture(data, &(data->map.d2_texture), D_2_PATH))
		exit_failure(data, "Invalid D2 Sprite texture\n", -2);
}

/*
Initializes and checks if weapon images are good to print
*/
void	add_weapon_sprite_texture(t_game *data)
{
	if (!data->weapon.img_1.img
		&& init_texture(data, &(data->weapon.img_1), W1_PATH))
		exit_failure(data, "Invalid T2 Sprite texture\n", -2);
	if (!data->weapon.img_2.img
		&& init_texture(data, &(data->weapon.img_2), W2_PATH))
		exit_failure(data, "Invalid T3 Sprite texture\n", -2);
	if (!data->weapon.img_3.img
		&& init_texture(data, &(data->weapon.img_3), W3_PATH))
		exit_failure(data, "Invalid T4 Sprite texture\n", -2);
	if (!data->weapon.img_4.img
		&& init_texture(data, &(data->weapon.img_4), W4_PATH))
		exit_failure(data, "Invalid D2 Sprite texture\n", -2);
}
