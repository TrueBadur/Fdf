/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:29:50 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/09 18:02:49 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_rotate_map(t_map *mp, t_vec3 v)
{
	double tmp[3];

	tmp[0] = v.x * M_PI / 180;
	tmp[1] = v.y * M_PI / 180;
	tmp[2] = v.z * M_PI / 180;
	return (ft_mapiter_c(mp, &ft_point_rot, &tmp));
}

void	ft_fit_map(t_map *mp, t_vec2 res)
{
	int t;
	int t2;

	t2 = res.x > res.y ? res.y : res.x;
	t = (mp->w > mp->h) ? t2 / (mp->w + 1) : t2 / (mp->h + 1);
	t2 = (mp->d > mp->h / 2 || mp->d > mp->w / 2) ? t / 2 : t;
	ft_mapiter(mp, &ft_point_scale, (int[]){t, t, t2});
}
