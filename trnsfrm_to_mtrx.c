/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trnsfrm_to_mtrx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 01:14:04 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/12 13:47:52 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mtrx	*ft_scale_mtrx(t_vec3_f v)
{
	t_mtrx	*ret;

	if (!(ret = ft_mtrx_init(4, 4, MTRX_DOUBLE)))
		return (NULL);
	((double *)ret->mtrx)[0] = (double)v.x;
	((double *)ret->mtrx)[5] = (double)v.y;
	((double *)ret->mtrx)[10] = (double)v.z;
	((double *)ret->mtrx)[15] = 1;
	ft_mtrx_print(ret);
	return (ret);
}

t_mtrx	*ft_rotate_mtrx(t_vec3 v)
{
	t_mtrx *ret;

	if (!(ret = x_rot_mtrx(v.x)))
		return (NULL);
	if (!(ret = ft_mtrx_mlt_destr(ret, y_rot_mtrx(v.y))))
		return (NULL);
	if (!(ret = ft_mtrx_mlt_destr(ret, z_rot_mtrx(v.z))))
		return (NULL);
	ft_mtrx_print(ret);
	return (ret);
}
t_mtrx	*ft_move_mtrx(t_vec3 v)
{
	t_mtrx *ret;

	if (!(ret = ft_mtrx_init(4, 4, MTRX_DOUBLE)))
		return (NULL);
	((double *)ret->mtrx)[0] = 1;
	((double *)ret->mtrx)[3] = v.x;
	((double *)ret->mtrx)[5] = 1;
	((double *)ret->mtrx)[7] = v.y;
	((double *)ret->mtrx)[10] = 1;
	((double *)ret->mtrx)[11] = v.z;
	((double *)ret->mtrx)[15] = 1;
	ft_mtrx_print(ret);
	return (ret);
}

t_mtrx	*ft_persp_mtrx(int z)
{
	t_mtrx *ret;

	if (!(ret = ft_mtrx_init(4, 4, MTRX_DOUBLE)))
		return (NULL);
	((double *)ret->mtrx)[0] = 1;
	((double *)ret->mtrx)[5] = 1;
	((double *)ret->mtrx)[10] = 1;
	((double *)ret->mtrx)[12] = 0;
	((double *)ret->mtrx)[13] = 0;
	((double *)ret->mtrx)[14] = -.0001 * z;
	((double *)ret->mtrx)[15] = 1;
	ft_mtrx_print(ret);
	return (ret);
}
