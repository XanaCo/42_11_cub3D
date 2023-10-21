/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:58:36 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/15 14:23:01 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D.h"

/*
Initializes the MLX pointer
*/
int	init_mlx_ptr(t_game *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	if (add_to_garbage(data, data->mlx, END))
		exit_failure(data, NULL, ENOMEM);
	data->win = mlx_new_window(data->mlx, WIN_W, WIN_H, "MD - This is CUB3D!");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		return (1);
	}
	if (init_mlx_img_addr(data))
		return (1);
	return (0);
}

/*
Initializes the MLX main window where we print all
*/
int	init_mlx_img_addr(t_game *data)
{
	data->main_img.img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	if (!data->main_img.img)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		return (1);
	}
	add_img_to_tab(data, data->main_img.img);
	data->main_img.addr = mlx_get_data_addr(data->main_img.img,
			&data->main_img.bpp,
			&data->main_img.size_line,
			&data->main_img.endian);
	if (!data->main_img.addr)
	{
		mlx_destroy_image(data->mlx, data->main_img.img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		return (1);
	}
	return (0);
}

/*
Initializes the images, adding them to the tab to destroy when we finish
*/
int	init_texture(t_game *data, t_img *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(data->mlx,
			path, &(texture->width), &(texture->height));
	if (!texture->img)
		return (1);
	add_img_to_tab(data, texture->img);
	texture->addr = mlx_get_data_addr(texture->img, &(texture->bpp),
			&(texture->size_line), &(texture->endian));
	if (!texture->addr)
		return (1);
	data->map.n_textures++;
	return (0);
}

/*
Initializes the colors of the floor and ceiling
*/
int	init_fc_color(t_game *data, int *color, char *path)
{
	int			r;
	int			g;
	int			b;
	char		**c_tab;

	if (!path || !path[0])
		return (1);
	c_tab = ft_split(path, ',');
	if (!c_tab)
		return (1);
	if (get_colors(&r, &g, &b, c_tab))
	{
		ft_free_matrix((void **)c_tab);
		return (1);
	}
	*color = r << 16 | g << 8 | b;
	data->map.n_textures++;
	ft_free_matrix((void **)c_tab);
	return (0);
}

/*
Divides the color given in the parsing into R G B values
*/
int	get_colors(int *r, int *g, int *b, char **color_tab)
{
	int	i;

	i = 0;
	if (!color_tab || !color_tab[0])
		return (1);
	while (color_tab[i])
		i++;
	if (i != 3)
		return (1);
	*r = ft_atoi_rgb(color_tab[0]);
	*g = ft_atoi_rgb(color_tab[1]);
	*b = ft_atoi_rgb(color_tab[2]);
	if (*r == -1 || *g == -1 || *b == -1)
		return (1);
	return (0);
}
