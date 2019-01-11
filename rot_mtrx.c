/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_mtrx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 02:39:05 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/11 02:50:26 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mtrx	*x_rot_mtrx(int x)
{
	double	xr;
	t_mtrx	*ret;

	if (!(ret = ft_mtrx_init(4, 4, MTRX_DOUBLE)))
		return (NULL);
	xr = x * M_PI /180;
	((double *)ret->mtrx)[0] = 1;
	((double *)ret->mtrx)[5] = cos(xr);
	((double *)ret->mtrx)[6] = -sin(xr);
	((double *)ret->mtrx)[9] = sin(xr);
	((double *)ret->mtrx)[10] = cos(xr);
	((double *)ret->mtrx)[15] = 1;
	return (ret);
}

t_mtrx	*y_rot_mtrx(int y)
{
	double	yr;
	t_mtrx	*ret;
	if (!(ret = ft_mtrx_init(4, 4, MTRX_DOUBLE)))
		return (NULL);
	yr = y * M_PI /180;
	((double *)ret->mtrx)[0] = cos(yr);
	((double *)ret->mtrx)[2] = sin(yr);
	((double *)ret->mtrx)[5] = 1;
	((double *)ret->mtrx)[8] = -sin(yr);
	((double *)ret->mtrx)[10] = cos(yr);
	((double *)ret->mtrx)[15] = 1;
	return (ret);
}

t_mtrx	*z_rot_mtrx(int z)
{
	double	zr;
	t_mtrx	*ret;

	if (!(ret = ft_mtrx_init(4, 4, MTRX_DOUBLE)))
		return (NULL);
	zr = z * M_PI /180;
	((double *)ret->mtrx)[0] = cos(zr);
	((double *)ret->mtrx)[1] = -sin(zr);
	((double *)ret->mtrx)[4] = sin(zr);
	((double *)ret->mtrx)[5] = cos(zr);
	((double *)ret->mtrx)[10] = 1;
	((double *)ret->mtrx)[15] = 1;
	return (ret);
}
