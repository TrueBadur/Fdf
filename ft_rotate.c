/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:29:50 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/07 18:52:14 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_point_rot(t_vec4 *v, void *data)
{
	int *d;

	d = (int *)data;
	if (d[0])
	{
		v->y = v->y * cos(d[0]) - v->z * sin(d[0]);
		v->z = v->y * sin(d[0]) + v->z * cos(d[0]);
	}
	if (d[1])
	{
		v->x = v->x * cos(d[1]) + v->z * sin(d[1]);
		v->z = - v->x * sin(d[1]) + v->z * cos(d[1]);
	}
	if (d[2])
	{
		v->x = v->x * cos(d[2]) - v->y * sin(d[2]);
		v->y = v->x * sin(d[2]) + v->y * cos(d[2]);
	}
}

t_map	*ft_rotate_map(t_map *mp, int xr, int yr, int zr)
{
	int tmp[3];

	tmp[0] = xr;
	tmp[1] = yr;
	tmp[2] = zr;
	return (ft_mapiter_c(mp, &ft_point_rot, &tmp));
}
