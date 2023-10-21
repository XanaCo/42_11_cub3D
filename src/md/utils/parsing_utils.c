/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:17:49 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/13 18:25:08 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D.h"

/*
Checks if the name of the file is in the correct format
*/
int	check_filename(char *argv)
{
	int		i;
	int		size;

	if (!argv || ft_strrncmp(argv, ".cub", 4))
		return (1);
	size = ft_strlen(argv);
	i = size;
	while (argv[i] != '/')
		i--;
	i++;
	size = size - i;
	if (size <= 4)
		return (1);
	return (0);
}

/*
Get next line of the map, handy version of get next line
*/
char	*get_next_map_line(t_game *data)
{
	char	*line;
	char	*tmp;

	line = get_next_line(data->fd);
	if (!line)
		return (NULL);
	while (line)
	{
		if (line[0] != '\n' || line[0] != '\0')
			break ;
		line = get_next_line(data->fd);
	}
	tmp = ft_strtrim(line, "\n");
	free(line);
	return (tmp);
}

/*
An RGB check version of the libft atoi
*/
int	ft_atoi_rgb(const char *nptr)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		return (-1);
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	if (nptr[i] || result > INT_MAX || result > 255)
		return (-1);
	return ((int)result);
}

/*
Adds the image to the image tab
*/
void	add_img_to_tab(t_game *data, void *ptr)
{
	static int	i = 0;

	data->img_tab[i] = ptr;
	i++;
}
