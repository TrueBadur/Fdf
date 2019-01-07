/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:29:50 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/07 19:55:54 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_rotate_map(t_map *mp, int xr, int yr, int zr)
{
	double tmp[3];

	tmp[0] = xr * M_PI / 180;
	tmp[1] = yr * M_PI / 180;
	tmp[2] = zr * M_PI / 180;
	return (ft_mapiter_c(mp, &ft_point_rot, &tmp));
}
