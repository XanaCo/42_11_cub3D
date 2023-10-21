/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_operations_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:53:48 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/04 13:28:31 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3D.h"

/*
Calculates the rotation and returns the new position
*/
t_points	rotate(t_points coord, double angle)
{
	t_points	res;

	res.x = coord.x * cos(angle) - coord.y * sin(angle);
	res.y = coord.x * sin(angle) + coord.y * cos(angle);
	return (res);
}

/*
Adds the coordinates given and returns the new position
*/
t_points	sum_coord(t_points v1, t_points v2)
{
	t_points	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	return (res);
}

/*
Subtracts the coordinates given and returns the new position
*/
t_points	diff_coord(t_points v1, t_points v2)
{
	t_points	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	return (res);
}

/*
Multiplies the coordinates given and returns the new position
*/
t_points	prod_coord(t_points v1, double factor)
{
	t_points	res;

	res.x = v1.x * factor;
	res.y = v1.y * factor;
	return (res);
}

/*
Divides the coordinates given and returns the new position
*/
t_points	div_coord(t_points v1, double factor)
{
	t_points	res;

	res.x = v1.x / factor;
	res.y = v1.y / factor;
	return (res);
}
