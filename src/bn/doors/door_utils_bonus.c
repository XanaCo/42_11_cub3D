/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:37:58 by atardif           #+#    #+#             */
/*   Updated: 2023/10/15 15:39:14 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Checks if we are in front of a normal door
*/
bool	ft_is_door(char door)
{
	if (door == 'P' || door == 'Q' || door == 'R' || door == 'S' || door == '9')
		return (true);
	else
		return (false);
}

/*
Checks that we are located far enough of a door before
resetting it so we don't get stuck
*/
bool	ft_far_enough(float pos, int goal, int i)
{
	if (i)
	{
		if (pos - (float)goal > 1.15)
			return (true);
	}
	else
	{
		if ((float)goal - pos > 0.15)
			return (true);
	}
	return (false);
}
