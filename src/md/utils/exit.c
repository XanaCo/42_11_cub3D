/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:17:49 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/13 18:23:02 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D.h"

/*
Exits if everything went well
*/
int	exit_succes(t_game *data)
{
	destroy_mlx_img_tab(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	clean_garbage(data, TMP);
	clean_garbage(data, END);
	exit(0);
}

/*
Exits in error, with the right error code
*/
void	exit_failure(t_game *data, char *str, int error)
{
	if (error > 0)
	{
		ft_putstr_fd("Error\n", 2);
		perror(str);
	}
	if (error < 0)
		error_msg(data, str, error);
	clean_all(data);
	exit(error);
}

/*
A custom error handling for some messages that cannot be printed with errno 
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
	return (1);
}

/*
Destroys the tab stocked with all images created
*/
void	destroy_mlx_img_tab(t_game *data)
{
	int	i;

	i = 0;
	while (data->img_tab[i])
	{
		mlx_destroy_image(data->mlx, data->img_tab[i]);
		i++;
	}
}

/*
Finishes the reading od the fd to avoid gnl memory leaks
*/
void	finish_fd_read(t_game *data)
{
	char	*line;

	line = get_next_line(data->fd);
	if (add_to_garbage(data, line, TMP))
		exit_failure(data, "Not enough memory", -2);
	while (line)
	{
		line = get_next_line(data->fd);
		if (add_to_garbage(data, line, TMP))
			exit_failure(data, "Not enough memory", -2);
	}
}
