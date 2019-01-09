/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:32:21 by bparker           #+#    #+#             */
/*   Updated: 2019/01/09 14:42:43 by bparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		hook_keydown(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(1);
	return (0);
}

t_img	img_draw(t_map map, t_vec2 vec, t_mlx mlx)
{
	int		i;
	int		j;
	t_vec4	*dot;
	t_img	cimg;

	i = -1;
	cimg.img_ptr = mlx_new_image(mlx.mlx_ptr, vec.x, vec.y);
	cimg.img_data = mlx_get_data_addr(cimg.img_ptr, &cimg.bpp,
			&cimg.size_line, &cimg.endian);
	dot = (t_vec4*)(map.vec->data);
	while (++i < map.h)
	{
		j = 0;
		while (j < map.w)
		{
			if (i != map.h - 1)
				img_drawline(dot[i * map.w + j],
						dot[(i + 1) * map.w + j], mlx, cimg);
			if (j != map.w - 1)
				img_drawline(dot[i * map.w + j],
						dot[i * map.w + j + 1], mlx, cimg);
			j++;
		}
	}
	return (cimg);
}
