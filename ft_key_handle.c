/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:45:28 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/14 21:59:21 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_rot(int key, t_trnsfrm *t)
{
	t->b = 1;
	if (key == 0)
		t->rot.z -= 5;
	else if (key == 1)
		t->rot.z += 5;
	else if (key == 6)
		t->rot.x -= 5;
	else if (key == 7)
		t->rot.x += 5;
	else if (key == 12)
		t->rot.y -= 5;
	else if (key == 13)
		t->rot.y += 5;
}

void	key_persp(int key, t_trnsfrm *t)
{
	t->b = 1;
	if (key == 35)
		t->persp = t->persp ? 0 : 1;
	if (key == 30 && t->persp > 1)
		t->persp--;
	if (key == 33 && t->persp != 0)
		t->persp++;
}

void	key_move(int key, t_trnsfrm *t, t_map *mp)
{
	t->b = 1;
	if (key == 5)
		t->mov_wrld.z += 3 * mp->w;
	if (key == 17)
		t->mov_wrld.z -= 3 * mp->w;
}
