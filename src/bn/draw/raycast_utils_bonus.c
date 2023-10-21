/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:48:05 by atardif           #+#    #+#             */
/*   Updated: 2023/10/15 15:39:45 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Set the good macro to access the good texture in the 
t_img * according to the side faced
*/
void	ft_get_wall_side(int *side, int *tex_i)
{
	if (*side == NORTH)
		*tex_i = NORTH_T;
	if (*side == SOUTH)
		*tex_i = SOUTH_T;
	if (*side == WEST)
		*tex_i = WEST_T;
	if (*side == EAST)
		*tex_i = EAST_T;
}

/*
Used to choose the good texture according to door value in the char **map
*/
void	ft_get_door_state(int side, int *tex_i, char obs)
{
	if (side == 1)
	{
		if (obs == 'P')
			*tex_i = NS1_D;
		if (obs == 'Q')
			*tex_i = NS2_D;
		if (obs == 'R')
			*tex_i = NS3_D;
		if (obs == 'S')
			*tex_i = NS4_D;
	}
	else
	{
		if (obs == 'P')
			*tex_i = WE1_D;
		if (obs == 'Q')
			*tex_i = WE2_D;
		if (obs == 'R')
			*tex_i = WE3_D;
		if (obs == 'S')
			*tex_i = WE4_D;
	}
}

/*
Used to choose the good texture according to door facing side
*/
void	ft_get_door_side(int *side, int *tex_i, char obs)
{
	if (*side == NORTH || *side == SOUTH)
		ft_get_door_state(1, tex_i, obs);
	if (*side == WEST || *side == EAST)
		ft_get_door_state(2, tex_i, obs);
}
