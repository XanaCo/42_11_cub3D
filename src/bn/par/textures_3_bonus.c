/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:58:36 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/13 20:36:43 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Prepares th path of the 33 xpm files to init
*/
static char	*prepare_path(t_game *data, int i)
{
	char	*new_path;
	char	num[7];

	if (i < 10)
	{
		num[0] = i % 10 + 48;
		num[1] = '.';
		num[2] = 'x';
		num[3] = 'p';
		num[4] = 'm';
		num[5] = '\0';
	}
	else
	{
		num[0] = i / 10 + 48;
		num[1] = i % 10 + 48;
		num[2] = '.';
		num[3] = 'x';
		num[4] = 'p';
		num[5] = 'm';
		num[6] = '\0';
	}
	new_path = ft_strjoin_gc(data, END, END_PATH, num);
	return (new_path);
}

/*
Initializes the 33 images of the end screen animation
*/
void	add_end_screen_texture(t_game *data)
{
	char	*new_path;
	int		i;

	i = 0;
	while (i < 34)
	{
		new_path = prepare_path(data, i);
		if (!new_path)
			exit_failure(data, "Not enough memory", -2);
		if (!data->screen_end[i].img
			&& init_texture(data, &(data->screen_end[i]), new_path))
			exit_failure(data, "Invalid Screen End texture\n", -2);
		i++;
	}
}
