/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:33:13 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/07 20:18:12 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_point_scale(t_vec4 *v, void *scale)
{
	t_vec3 *i;

	i = (t_vec3 *)scale;
	v->x = v->x * i->x;
	v->y = v->y * i->y;
	v->z = v->z * i->z;
}

void	ft_point_move(t_vec4 *vec4, void *data)
{
	vec4->x += ((t_vec3*)data)->x;
	vec4->y += ((t_vec3*)data)->y;
	vec4->z += ((t_vec3*)data)->z;
}

void	ft_point_rot(t_vec4 *v, void *data)
{
	double *d;

	d = (double *)data;
	if (d[0])
	{
		v->y = v->y * cos(d[0]) - v->z * sin(d[0]);
		v->z = v->y * sin(d[0]) + v->z * cos(d[0]);
	}
	if (d[1])
	{
		v->x = v->x * cos(d[1]) + v->z * sin(d[1]);
		v->z = -v->x * sin(d[1]) + v->z * cos(d[1]);
	}
	if (d[2])
	{
		v->x = v->x * cos(d[2]) - v->y * sin(d[2]);
		v->y = v->x * sin(d[2]) + v->y * cos(d[2]);
	}
}
