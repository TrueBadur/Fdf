/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:43:55 by bparker           #+#    #+#             */
/*   Updated: 2019/01/16 21:34:16 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	drwln_init(t_vec4 dot0, t_vec4 dot1, t_drwln *dl)
{
	int i;

	dl->er.y = 0;
	dl->dxy.x = abs(dot1.x - dot0.x);
	dl->dxy.y = abs(dot1.y - dot0.y);
	dl->sxy.x = dot0.x < dot1.x ? 1 : -1;
	dl->sxy.y = dot0.y < dot1.y ? 1 : -1;
	dl->colc = dl->dxy.x > dl->dxy.y ? dl->dxy.x : dl->dxy.y;
	dl->er.x = (dl->dxy.x > dl->dxy.y ? dl->dxy.x : -dl->dxy.y) / 2;
	i = 4;
	while (i--)
	{
		dl->dcol[i] = (float)(((unsigned char*)&dot0.color)[i] -
			(float)((unsigned char *)&dot1.color)[i]) / (float)dl->colc;
	}
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
	if (!dl->colc)
		return ;
	if (dot0->color != dot1.color)
	{
		i = 4;
		while (i--)
		{
			((unsigned char *)&dot0->color)[i] = (char)
				(((unsigned char *)&dot1.color)[i] + dl->dcol[i] * dl->colc);
		}
		(dl->colc > 0) ? dl->colc-- : dl->colc++;
	}
}

void		img_drawline(t_vec4 dot0, t_vec4 dot1, t_mlx mlx, t_img cimg)
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

void		img_drawlinesafe(t_vec4 dot0, t_vec4 dot1, t_mlx mlx, t_img cimg)
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
