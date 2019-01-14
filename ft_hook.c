/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:44:47 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/14 20:28:31 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		hook_keydwn(int key, void *param)
{
	t_map		*c_map;
	t_trnsfrm	*t;
	t_map		*mp;

	printf("%d\n", key);
	if (key == 53)
		exit(0);
	t = (t_trnsfrm *)(((int **)param)[1]);
	mp = (t_map *)(((int **)param)[0]);
	if (key == 35 || key == 30 || key == 33)
	{
		t->b = 1;
		if (key == 35)
			t->persp = t->persp ? 0 : 1;
		if (key == 30 && t->persp > 1)
			t->persp--;
		if (key == 33 && t->persp != 0)
			t->persp++;
	}
	if (key == 5 || key == 17)
	{
		t->b = 1;
		if (key == 5)
			t->mov_wrld.z += 3 *  mp->w;
		if (key == 17)
			t->mov_wrld.z -= 3 * mp->w;
	}
	if (key == 0 || key == 1 || key == 12 || key == 13 || key == 6 || key == 7)
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
	if (t->b)
		img_to_win(param);
	return (0);
}

int		mouse_hook(int but, int x, int y, void *param)
{
	printf("mouse = %d: x = %d, y = %d\n", but, x, y);
	return (0);
}
