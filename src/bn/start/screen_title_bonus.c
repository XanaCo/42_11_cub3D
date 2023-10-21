/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_title_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:12:59 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 20:41:07 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
This function will put the screen_title image into the window, centering it 
*/
void	init_screen_title(t_game *data)
{
	data->screen_title.img_1.img = mlx_xpm_file_to_image(data->mlx,
			"./img/XPM/start_title/Screen_Title_01.xpm",
			&data->screen_title.img_1.width,
			&data->screen_title.img_1.height);
	data->screen_title.img_2.img = mlx_xpm_file_to_image(data->mlx,
			"./img/XPM/start_title/Screen_Title_02.xpm",
			&data->screen_title.img_2.width,
			&data->screen_title.img_2.height);
	add_img_to_tab(data, data->screen_title.img_1.img);
	add_img_to_tab(data, data->screen_title.img_2.img);
}

/*
Loads the start screen into the window
*/
void	load_screen_title(t_game *data)
{
	static int	loops = 0;

	if (loops >= RATE)
		loops = 0;
	loops++;
	if (loops < RATE / 2)
		mlx_put_image_to_window(data->mlx, data->win,
			data->screen_title.img_1.img, 0, 0);
	if (loops >= RATE / 2)
		mlx_put_image_to_window(data->mlx, data->win,
			data->screen_title.img_2.img, 0, 0);
}
