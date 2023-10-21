/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:58:36 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/13 17:58:20 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D.h"

/*
Main function that calls all the parsing checks and stocks the data
*/
int	parsing(t_game *data, char *file)
{
	t_list	*lst;

	data->fd = open(file, O_RDONLY);
	if (data->fd < 0)
		return (error_msg(data, "File not found\n", -1));
	if (init_mlx_ptr(data))
		return (error_msg(data, "Initiating Minilibx\n", -1));
	get_textures(data);
	lst = get_map(data);
	check_and_stock_map(data, lst);
	ref_img_tab(data->map.r_tab, data->map);
	search_player(data, data->map.map);
	clean_tmp(data);
	close(data->fd);
	return (0);
}

/*
Parses the map given in the file, line by line,
stocks it in a linked list to future checks
*/
t_list	*get_map(t_game *data)
{
	char	*map_line;
	t_list	*node;
	t_list	*lst;

	lst = NULL;
	map_line = get_next_map_line(data);
	while (map_line)
	{
		if (add_to_garbage(data, map_line, TMP))
			exit_failure(data, "Not enough memory", -2);
		node = ft_lstnew(map_line);
		if (!node)
			exit_failure(data, "ft_lstnew failed\n", -2);
		if (add_to_garbage(data, node, TMP))
			exit_failure(data, "Not enough memory", -2);
		ft_lstadd_back(&lst, node);
		map_line = get_next_map_line(data);
	}
	return (lst);
}

/*
Parses the lines of the textures, cleans all kinds
of spaces, calls the function to init the images
*/
void	get_textures(t_game *data)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	while (i < 6)
	{
		line = get_next_line(data->fd);
		if (!line)
			exit_failure(data, "Texture / Color not found\n", -2);
		if (add_to_garbage(data, line, TMP))
			exit_failure(data, "Not enough memory", -2);
		tmp = ft_clean_whitespaces(line);
		if (!tmp)
			exit_failure(data, "ft_strtrim failed\n", -2);
		if (add_to_garbage(data, tmp, TMP))
			exit_failure(data, "Not enough memory", -2);
		if (tmp[0] == '\n' || tmp[0] == '\0')
			continue ;
		add_texture_to_map(data, tmp);
		i++;
	}
	if (data->map.n_textures != 6)
		exit_failure(data, "Invalid Textures\n", -2);
}

/*
Initializes each texture, checking if everything is good to go
*/
void	add_texture_to_map(t_game *data, char *line)
{
	if (!line)
		exit_failure(data, "Invalid line\n", -2);
	if (!ft_strncmp(line, "NO", 2) && !data->map.no_texture.img
		&& init_texture(data, &(data->map.no_texture), &line[2]))
		exit_failure(data, "Invalid North texture\n", -2);
	if (!ft_strncmp(line, "SO", 2) && !data->map.so_texture.img
		&& init_texture(data, &(data->map.so_texture), &line[2]))
		exit_failure(data, "Invalid South texture\n", -2);
	if (!ft_strncmp(line, "EA", 2) && !data->map.ea_texture.img
		&& init_texture(data, &(data->map.ea_texture), &line[2]))
		exit_failure(data, "Invalid East texture\n", -2);
	if (!ft_strncmp(line, "WE", 2) && !data->map.we_texture.img
		&& init_texture(data, &(data->map.we_texture), &line[2]))
		exit_failure(data, "Invalid West texture\n", -2);
	if (!ft_strncmp(line, "C", 1) && !data->map.c_color
		&& init_fc_color(data, &(data->map.c_color), &line[1]))
		exit_failure(data, "Invalid ceiling texture\n", -2);
	if (!ft_strncmp(line, "F", 1) && !data->map.f_color
		&& init_fc_color(data, &(data->map.f_color), &line[1]))
		exit_failure(data, "Invalid floor texture\n", -2);
}

/*
Stocks a t_img tab with specific indexes for each texture,
if the order is different in the file
*/
void	ref_img_tab(t_img *r_tab, t_map map)
{
	r_tab[0] = map.no_texture;
	r_tab[1] = map.so_texture;
	r_tab[2] = map.we_texture;
	r_tab[3] = map.ea_texture;
}
