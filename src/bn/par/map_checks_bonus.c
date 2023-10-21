/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:58:36 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/13 19:36:55 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Checks and stocks if there are no errors
*/
void	check_and_stock_map(t_game *data, t_list *lst)
{
	t_list	*iter;

	if (!lst)
		exit_failure(data, "Map not found\n", -2);
	iter = lst;
	while (iter && check_charset(data, iter->content))
		iter = iter->next;
	while (iter)
	{
		if (check_charset(data, iter->content))
			break ;
		data->map.map_h++;
		if ((int)ft_strlen(iter->content) > data->map.map_w)
			data->map.map_w = (int)ft_strlen(iter->content);
		iter = iter->next;
	}
	if (iter && iter->content)
		exit_failure(data, "Extra lines in map\n", -2);
	if (data->map.error != 1)
		exit_failure(data, "No players at all\n", -2);
	stock_map_tab(data, lst);
	check_walls(data, data->map.map);
}

/*
Stock the checked map in the main structure tab
*/
void	stock_map_tab(t_game *data, t_list *lst)
{
	t_list	*iter;
	char	*new;
	int		i;

	i = 0;
	iter = lst;
	data->map.error = 0;
	data->map.sp_error = 0;
	data->map.map = ft_calloc_gc(data, END, \
					data->map.map_h + 1, sizeof(char *));
	if (!data->map.map)
		exit_failure(data, "Not enough memory", -2);
	while (iter && check_charset(data, iter->content))
		iter = iter->next;
	while (iter)
	{
		if (check_charset(data, iter->content))
			break ;
		new = ft_strdup_gc(data, TMP, (char *)iter->content);
		fill_espaces(data, &new);
		data->map.map[i] = ft_strdup_gc(data, END, (const char *)new);
		free(new);
		iter = iter->next;
		i++;
	}
}

/*
Checks if the characters in the given line are valid map characters
*/
int	check_charset(t_game *data, char *map_line)
{
	int			i;

	i = 0;
	if (map_line[0] == '\0')
		return (1);
	while (map_line && map_line[i])
	{
		if (map_line[i] == '0' || map_line[i] == '1' || map_line[i] == 'P'
			|| map_line[i] == 'B' || map_line[i] == 'X' || map_line[i] == ' '
			|| map_line[i] == 'A')
			i++;
		else if (map_line[i] == 'T' || map_line[i] == 'D' || map_line[i] == 'N'
			|| map_line[i] == 'S' || map_line[i] == 'W' || map_line[i] == 'E')
		{
			check_players_and_sprites(data, map_line[i]);
			i++;
		}
		else
			exit_failure(data, "Invalid char in map\n", -2);
	}
	return (0);
}

/*
Checks if we have the right number of players and sprites
*/
void	check_players_and_sprites(t_game *data, int map_char)
{
	if (map_char == 'T' || map_char == 'D')
	{
		data->map.sp_error++;
		if (data->map.sp_error > 2)
			exit_failure(data, "Wrong number of Sprites\n", -2);
	}
	if (map_char == 'N' || map_char == 'S'
		|| map_char == 'W' || map_char == 'E')
	{
		if (data->map.error)
			exit_failure(data, "Too many players\n", -2);
		data->map.error++;
	}
}

/*
Changes map spaces into '2' to check if the perimeter is closed
*/
void	fill_espaces(t_game *data, char **map_line)
{
	char	*line;
	char	*new;
	int		i;

	i = 0;
	line = *map_line;
	new = ft_calloc(data->map.map_w + 1, sizeof(char));
	if (!new)
		exit_failure(data, "Not enough memory\n", -2);
	while (new && i < data->map.map_w)
	{
		if (i > (int)ft_strlen(line) || !line[i]
			|| (line[i] == ' ' || line[i] == '\0'))
			new[i] = '2';
		else
			new[i] = line[i];
		i++;
	}
	*map_line = new;
}
