/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:33:13 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/11 09:39:29 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_transform_point(t_vec4 *v, void *data)
{
	double	t;
	t_mtrx	*mtrx;
	t_mtrx	*tmp;

	if (!(mtrx = ft_mtrx_init(1, 4, MTRX_DOUBLE)))
		return ;
	((double *)mtrx->mtrx)[0] = v->x;
	((double *)mtrx->mtrx)[1] = v->y;
	((double *)mtrx->mtrx)[2] = v->z;
	((double *)mtrx->mtrx)[3] = 1;
	ft_mtrx_print(mtrx);
	ft_mtrx_print((t_mtrx *)data);
	if (!(tmp = ft_mtrx_mlt((t_mtrx *)data, mtrx)))
		return ;
	ft_mtrx_destroy(&mtrx);
	mtrx = tmp;
	t = (((double *)mtrx->mtrx)[3]);
	v->x = round((((double *)mtrx->mtrx)[0]) / t);
	v->y = round((((double *)mtrx->mtrx)[1]) / t);
	v->z = round((((double *)mtrx->mtrx)[2]) / t);
	printf("v.x = %d, v.y = %d, v.z = %d\n", v->x, v->y, v->z);
	ft_mtrx_print(mtrx);
	ft_mtrx_destroy(&mtrx);
}


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
	double	*d;
	int		t;

	d = (double *)data;
	if (d[2])
	{
		t = v->x;
		v->x = t * cos(d[2]) - v->y * sin(d[2]);
		v->y = t * sin(d[2]) + v->y * cos(d[2]);
	}
	if (d[0])
	{
		t = v->y;
		v->y = t * cos(d[0]) - v->z * sin(d[0]);
		v->z = t * sin(d[0]) + v->z * cos(d[0]);
	}
	if (d[1])
	{
		t = v->x;
		v->x = t * cos(d[1]) + v->z * sin(d[1]);
		v->z = -t * sin(d[1]) + v->z * cos(d[1]);
	}
}
