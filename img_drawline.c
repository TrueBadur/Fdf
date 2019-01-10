/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:43:55 by bparker           #+#    #+#             */
/*   Updated: 2019/01/10 17:38:29 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_drawline(t_vec4 dot0, t_vec4 dot1, t_mlx mlx, t_img cimg)
{
	t_vec2	dxy;
	t_vec2	sxy;
	t_vec2	er;

//	printf("Drawline1'n:\n");
	er.y = 0;
	dxy.x = abs(dot1.x - dot0.x);
	dxy.y = abs(dot1.y - dot0.y);
	sxy.x = dot0.x < dot1.x ? 1 : -1;
	sxy.y = dot0.y < dot1.y ? 1 : -1;
	er.x = (dxy.x > dxy.y ? dxy.x : -dxy.y) / 2;
	while (1)
	{
//		printf("Drawline2\n");
//		printf("0:%d|%d, 1:%d|%d\n", dot0.x, dot0.y, dot1.x, dot1.y);
		img_drawpixel(cimg.img_data, mlx.mlx_ptr, dot0, cimg.size_line);
//		printf("Drawline3\n");
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
