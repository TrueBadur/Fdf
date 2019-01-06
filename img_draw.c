/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:32:21 by bparker           #+#    #+#             */
/*   Updated: 2019/01/04 04:02:54 by bparker          ###   ########.fr       */
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

void	img_drawline(t_vec4 dot0, t_vec4 dot1, t_img cimg, t_mlx mlx)
{
	img_drawpixel(cimg.img_data, mlx.mlx_ptr, dot0.x, dot0.y, dot0.color, cimg.size_line);
}

t_img	img_drawmap(t_map map, int size_x, int size_y, t_mlx mlx) //похоже на костыль? если да - можно переписать :)
{
	int		i;
	int		j;
	t_vec4	*dot;
	t_img	cimg;

	i = 0;
	cimg.img_ptr = mlx_new_image(mlx.mlx_ptr, size_x, size_y);
	cimg.img_data = mlx_get_data_addr(cimg.img_ptr, &cimg.bpp, &cimg.size_line, &cimg.endian);
	dot = (t_vec4*)(map.vec->data);
	while (i < map.h - 1)
	{
		j = 0;
		while (j < map.w - 1)
		{
			img_drawline(dot[i * map.w + j], dot[(i + 1) * map.w + j], cimg, mlx);
			img_drawline(dot[i * map.w + j], dot[i * map.w + j + 1], cimg, mlx);
			j++;
		}
		i++;
	}
	return (cimg);
}

void	img_draw(t_map map, int size_x, int size_y, char *title)
{
	t_mlx	mlx;
	t_img	cimg;
//	t_map	start;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, size_x, size_y, title);
//	start = map;
//	save default coords || save default image.. i guess coords would be better
//	img_rotate(map);
	cimg = img_drawmap(map, size_x, size_y, mlx);//?
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, cimg.img_ptr, 0, 0);//check this coords
	mlx_key_hook(mlx.win_ptr, hook_keydown, (void *)0);
	mlx_loop(mlx.mlx_ptr);
}
