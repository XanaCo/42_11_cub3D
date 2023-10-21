/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:13:52 by atardif           #+#    #+#             */
/*   Updated: 2023/10/15 16:00:07 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
A custom error handling for some messages 
that cannot be printed with errno 
*/
int	error_msg(t_game *data, char *str, int error)
{
	if (error == -1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(str, 2);
	}
	if (error == -2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(str, 2);
		finish_fd_read(data);
		clean_garbage(data, TMP);
		destroy_mlx_img_tab(data);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		close(data->fd);
	}
	else
		return (error_msg_continuation(data, str, error));
	return (1);
}

/*
A custom error handling for some messages 
that cannot be printed with errno (cont)
*/
int	error_msg_continuation(t_game *data, char *str, int error)
{
	if (error == -3)
	{
		ft_putstr_fd("Error\n", 2);
		close(data->fd);
		clean_all(data);
		ft_putstr_fd(str, 2);
	}
	if (error == -4)
	{
		ft_putstr_fd("Error\n", 2);
		close(data->fd);
		mlx_destroy_image(data->mlx, data->main_img.img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		clean_all(data);
		ft_putstr_fd(str, 2);
	}
	return (1);
}
