/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:43:55 by bparker           #+#    #+#             */
/*   Updated: 2019/01/09 13:28:14 by bparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_drawline(t_vec4 dot0, t_vec4 dot1, t_mlx mlx, t_img cimg)
{
	t_vec2	dxy;
	t_vec2	sxy;
	t_vec2	er;

	er.y = 0;
	dxy.x = abs(dot1.x - dot0.x);
	dxy.y = abs(dot1.y - dot0.y);
	sxy.x = dot0.x < dot1.x ? 1 : -1;
	sxy.y = dot0.y < dot1.y ? 1 : -1;
	er.x = (dxy.x > dxy.y ? dxy.x : -dxy.y) / 2;
	while (1)
	{
		img_drawpixel(cimg.img_data, mlx.mlx_ptr, dot0.x, dot0.y, (dot0.color) ? dot0.color : 0x0000FF, cimg.size_line);
		if (dot0.x == dot1.x && dot0.y == dot1.y)
			break ;
		er.y = er.x;
		if (er.y > -dxy.x)
			er.x -= dxy.y;
		if (er.y > -dxy.x)
			dot0.x += sxy.x;
		if (er.y < dxy.y)
			er.x += dxy.x;
		if (er.y < dxy.y)
			dot0.y += sxy.y;
	}
}