/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:29:50 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/15 02:59:05 by ehugh-be         ###   ########.fr       */
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
