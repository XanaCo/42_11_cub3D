/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:58:36 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/15 15:55:09 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

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
		return (error_msg(data, "Initiating Minilibx\n", -3));
	data->coord.dist_tab = ft_calloc_gc(data, END, WIN_W, sizeof(double));
	if (!data->coord.dist_tab)
		return (error_msg(data, "Initiating dist_TAB\n", -4));
	get_textures(data);
	lst = get_map(data);
	check_and_stock_map(data, lst);
	ref_img_tab(data->map.r_tab, data->map);
	search_player(data, data->map.map);
	init_sprites(data, data->map.map, data->map.r_tab, C_T1);
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
	while (i < 13)
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
	if (data->map.n_textures != 13)
		exit_failure(data, "Invalid Textures\n", -2);
	add_sprites_to_map(data);
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
	r_tab[4] = map.f_texture;
	r_tab[5] = map.c_texture;
	r_tab[6] = map.pns1_texture;
	r_tab[7] = map.pns2_texture;
	r_tab[8] = map.pns3_texture;
	r_tab[9] = map.pns4_texture;
	r_tab[10] = map.pwe1_texture;
	r_tab[11] = map.pwe2_texture;
	r_tab[12] = map.pwe3_texture;
	r_tab[13] = map.pwe4_texture;
	r_tab[14] = map.b_texture;
	r_tab[15] = map.x_texture;
	r_tab[16] = map.ele_texture;
	r_tab[17] = map.t1_texture;
	r_tab[18] = map.t2_texture;
	r_tab[19] = map.t3_texture;
	r_tab[20] = map.t4_texture;
	r_tab[21] = map.d1_texture;
	r_tab[22] = map.d2_texture;
	r_tab[23] = map.t0_texture;
}

/*
Initializes the sprites depending on its type
*/
void	init_sprites(t_game *data, char **map, t_img *r_tab, int i)
{
	if (!data->init_sprite)
	{
		data->sprite[D_SPRITE].texture = r_tab[C_D1];
		data->sprite[D_SPRITE].id = 'D';
		search_sprites(data, map, 'D');
		data->sprite[T_SPRITE].id = 'T';
		search_sprites(data, map, 'T');
	}
	data->sprite[T_SPRITE].texture = r_tab[i];
	data->init_sprite++;
}
