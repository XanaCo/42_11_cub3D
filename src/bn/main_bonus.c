/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:32:42 by atardif           #+#    #+#             */
/*   Updated: 2023/10/11 14:12:30 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3D_bonus.h"

/*
# CUB3D #
Allowed functions :
open, close, read, write, printf, malloc, free, perror, strerror, exit
lib math functions (-lm man man 3 math)
MinilibX functions
*/
int	main(int argc, char **argv)
{
	t_game	data;

	if (argc != 2)
		return (error_msg(&data, "Invalid number of arguments\n", -1));
	if (check_filename(argv[1]))
		return (error_msg(&data, "Wrong format\n", -1));
	if (WIN_H != 720 || WIN_W != 1080)
		return (error_msg(&data, "Wrong Window format\n", -1));
	ft_memset(&data, 0, sizeof(t_game));
	print_instructions();
	if (parsing(&data, argv[1]))
		return (1);
	data.start = 1;
	init_screen_title(&data);
	start_game(&data);
	return (0);
}
