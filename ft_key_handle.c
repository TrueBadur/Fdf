/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:45:28 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/18 18:16:05 by bparker          ###   ########.fr       */
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

void	key_projection(int key, t_trnsfrm *t)
{
	if (key == 18)
		key_parralel(t);
	if (key == 19)
		key_isometric(t);
	if (key == 20)
		key_isometric_1(t);
	if (key == 21)
		key_isometric_2(t);
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
	if (key == 123)
		t->mov_wrld.x -= 10;
	if (key == 124)
		t->mov_wrld.x += 10;
	if (key == 125)
		t->mov_wrld.y += 10;
	if (key == 126)
		t->mov_wrld.y -= 10;
}

void	key_scale(int key, t_trnsfrm *t)
{
	t->b = 1;
	if (key == 43)
	{
		t->scale.x *= 1.1;
		t->scale.y *= 1.1;
		t->scale.z *= 1.1;
	}
	if (key == 47)
	{
		t->scale.x /= 1.1;
		t->scale.y /= 1.1;
		t->scale.z /= 1.1;
	}
	if (key == 41)
		t->scale.z *= 1.1;
	if (key == 39)
		t->scale.z /= 1.1;
}
