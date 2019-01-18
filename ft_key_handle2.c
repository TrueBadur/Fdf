/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handle2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:43:34 by bparker           #+#    #+#             */
/*   Updated: 2019/01/18 17:53:04 by bparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_parralel(t_trnsfrm *t)
{
	t->rot.x = 0;
	t->rot.y = 0;
	t->rot.z = 0;
	t->scale.x = 30.0;
	t->scale.y = 30.0;
	t->scale.z = 6.0;
	t->persp = 0;
	t->b = 1;
	t->mov_wrld.x = 0;
	t->mov_wrld.y = 0;
	t->mov_wrld.z = 0;
}

void	key_isometric(t_trnsfrm *t)
{
	t->rot.x = 55;
	t->rot.y = 0;
	t->rot.z = 45;
	t->scale.x = 30.0;
	t->scale.y = 30.0;
	t->scale.z = 6.0;
	t->persp = 0;
	t->b = 1;
	t->mov_wrld.x = 0;
	t->mov_wrld.y = 0;
	t->mov_wrld.z = 0;
}
