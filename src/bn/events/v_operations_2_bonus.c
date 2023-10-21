/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_operations_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:06:53 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 20:02:35 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D_bonus.h"

/*
Takes the coordinates given and returns the new absolute position
*/
t_points	abs_coord(t_points coord)
{
	t_points	res;

	res.x = fabs(1 / coord.x);
	res.y = fabs(1 / coord.y);
	return (res);
}

/*
Gets the distance between two points (int)
*/
double	dist_coord(t_coord a, t_coord b)
{
	double	res;

	res = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	return (res);
}

/*
Gets the distance between two points (double)
*/
double	dist_points(t_points a, t_points b)
{
	double	res;

	res = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	return (res);
}
