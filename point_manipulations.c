/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:33:13 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/15 06:56:40 by ehugh-be         ###   ########.fr       */
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
	if (!(tmp = ft_mtrx_mlt((t_mtrx *)data, mtrx)))
		return ;
	ft_mtrx_destroy(&mtrx);
	mtrx = tmp;
	t = (((double *)mtrx->mtrx)[3]);
	v->x = round((((double *)mtrx->mtrx)[0]) / t);
	v->y = round((((double *)mtrx->mtrx)[1]) / t);
	v->z = round((((double *)mtrx->mtrx)[2]) / t);
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
