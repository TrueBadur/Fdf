/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:29:50 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/16 21:39:46 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fit_map(t_map *mp, t_trnsfrm *tr, t_vec2 res)
{
	int t;
	int t2;

	t2 = res.x > res.y ? res.y : res.x;
	t = (mp->w > mp->h) ? t2 / (mp->w + 1) : t2 / (mp->h + 1);
	t2 = (mp->d > mp->h / 2 || mp->d > mp->w / 2) ? t / 2 : t;
	tr->scale.x = t;
	tr->scale.y = t;
	tr->scale.z = t2;
}

void	ft_center_map(t_map *fdf)
{
	t_vec3 v;

	v.x = -(fdf->w / 2);
	v.y = -(fdf->h / 2);
	v.z = 0;
	ft_mapiter(fdf, &ft_point_move, &v);
}
