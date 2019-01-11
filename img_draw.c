/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:32:21 by bparker           #+#    #+#             */
/*   Updated: 2019/01/11 11:58:29 by bparker          ###   ########.fr       */
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

void print_map(t_vec4 *v, void * data)
{
	printf("(x = %d, y = %d, z = %d, color = %X)\n", v->x, v->y, v->z, v->color);
}

t_img	img_draw(t_map map, t_vec2 vec, t_mlx mlx)
{
	int		i;
	int		j;
	t_vec4	*dot;
	t_img	cimg;
	t_vec2	check;

	i = -1;
	cimg.img_ptr = mlx_new_image(mlx.mlx_ptr, vec.x, vec.y);
	cimg.img_data = mlx_get_data_addr(cimg.img_ptr, &cimg.bpp,
			&cimg.size_line, &cimg.endian);
	dot = (t_vec4*)(map.vec->data);
//	ft_mapiter(&map, &print_map, NULL);
	while (++i < map.h)
	{
		j = 0;
		while (j < map.w)
		{
			check.x = border_check(dot[i * map.w + j], dot[(i + 1) * map.w + j], vec);
			printf("check.x:%d\n", check.x);
			if (i != map.h - 1 && check.x == 1)
				img_drawline(dot[i * map.w + j],
						dot[(i + 1) * map.w + j], mlx, cimg);
			if (i != map.h - 1 && check.x == -1)
				img_drawlinesafe(dot[i * map.w + j],
						dot[(i + 1) * map.w + j], mlx, cimg, vec);
			check.y = border_check(dot[i * map.w + j], dot[i * map.w + j + 1], vec);
			printf("check.y:%d\n", check.y);
			if (j != map.w - 1 && check.y == 1)
				img_drawline(dot[i * map.w + j],
						dot[i * map.w + j + 1], mlx, cimg);
			if (j != map.w - 1 && check.y == -1)
				img_drawlinesafe(dot[i * map.w + j],
						dot[i * map.w + j + 1], mlx, cimg, vec);
			j++;
		}
	}
	return (cimg);
}
