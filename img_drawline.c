/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:43:55 by bparker           #+#    #+#             */
/*   Updated: 2019/01/15 07:17:02 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	drwln_init(t_vec4 dot0, t_vec4 dot1, t_drwln *dl)
{
	dl->er.y = 0;
	dl->dxy.x = abs(dot1.x - dot0.x);
	dl->dxy.y = abs(dot1.y - dot0.y);
	dl->sxy.x = dot0.x < dot1.x ? 1 : -1;
	dl->sxy.y = dot0.y < dot1.y ? 1 : -1;
	dl->er.x = (dl->dxy.x > dl->dxy.y ? dl->dxy.x : -dl->dxy.y) / 2;
	dl->col.argb[0] = 0;
}

static void	drwln_change(t_vec4 *dot0, t_vec4 dot1, t_drwln *dl)
{
	int d;
	int i;

	dl->er.y = dl->er.x;
	if (dl->er.y > -dl->dxy.x)
		dl->er.x -= dl->dxy.y;
	if (dl->er.y > -dl->dxy.x)
		dot0->x += dl->sxy.x;
	if (dl->er.y < dl->dxy.y)
		dl->er.x += dl->dxy.x;
	if (dl->er.y < dl->dxy.y)
		dot0->y += dl->sxy.y;
	d = abs(dl->dxy.x > dl->dxy.y ? dot0->x - dot1.x : dot0->y - dot1.y);
	if (!d)
		return ;
	if (dot0->color != dot1.color)
	{
		i = 4;
		while (i--)
		{
			dl->col.argb[i] = (((t_color)dot0->color).argb[i] -
					((unsigned char *)&dot1.color)[i]) / d;
			((unsigned char *)&dot0->color)[i] -= dl->col.argb[i];
		}
	}
}

void	img_drawline(t_vec4 dot0, t_vec4 dot1, t_mlx mlx, t_img cimg)
{
	t_drwln	dl;

	drwln_init(dot0, dot1, &dl);
	while (1)
	{
		img_drawpxl(cimg.img_data, mlx.mlx_ptr, dot0, cimg.size_line);
		if (dot0.x == dot1.x && dot0.y == dot1.y)
			break ;
		drwln_change(&dot0, dot1, &dl);
	}
}

void	img_drawlinesafe(t_vec4 dot0, t_vec4 dot1, t_mlx mlx, t_img cimg)
{
	t_drwln	dl;

	drwln_init(dot0, dot1, &dl);
	while (1)
	{
		img_drawpxlsafe(cimg.img_data, mlx, dot0, cimg.size_line);
		if (dot0.x == dot1.x && dot0.y == dot1.y)
			break ;
		drwln_change(&dot0, dot1, &dl);
	}
}
