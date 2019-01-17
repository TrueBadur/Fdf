/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:44:47 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/17 17:38:49 by bparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		hook_keydwn(int key, void *param)
{
	t_trnsfrm	*t;
	t_map		*mp;

	printf("%d\n", key);
	if (key == 53)
		exit(0);
	t = (t_trnsfrm *)(((int **)param)[1]);
	mp = (t_map *)(((int **)param)[0]);
	if (key == 35 || key == 30 || key == 33)
		key_persp(key, t);
	if (key == 5 || key == 17 || (key >= 123 && key <= 126))
		key_move(key, t, mp);
	if (key == 0 || key == 1 || key == 12 || key == 13 || key == 6 || key == 7)
		key_rot(key, t);
	if (key == 41 || key == 43 || key == 39 || key == 47)
		key_scale(key, t);
	if (key == 82)
		key_rot_reset(t);
	if (t->b)
		img_to_win(param);
	return (0);
}

int		mouse_hook(int but, int x, int y, void *param)
{
	if (but && x && y && param)
		return (0);
	return (0);
}
