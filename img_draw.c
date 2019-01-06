/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:32:21 by bparker           #+#    #+#             */
/*   Updated: 2019/01/06 12:33:47 by bparker          ###   ########.fr       */
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
/*
int	get_dcol(int col0, int col1, int iter)
{
	int	r;
	int	g;
	int	b;

	r = ;
	g = ;
	b = ;
	return ()
}
*/
void	img_drawline(t_vec4 dot0, t_vec4 dot1, t_img cimg, t_mlx mlx)
{
	double dx;
	double dy;
	double dc;

	dx = fabs(dot1.y - dot0.y) > fabs(dot1.x - dot0.x) ? fabs(dot1.x - dot0.x) / fabs(dot1.y - dot0.y): 1;
	dy = fabs(dot1.y - dot0.y) < fabs(dot1.x - dot0.x) ? fabs(dot1.y - dot0.y) / fabs(dot1.x - dot0.x): 1;
	dx = dot0.x > dot1.x ? dx * - 1 : dx;
	dy = dot0.y > dot1.y ? dy * - 1 : dy;
//	dc = get_dcol(dot0.color, dot1.color, fabs(dot1.y - dot0.y) > fabs(dot1.x - dot0.x) ? fabs(dot1.y - dot0.y) : fabs(dot1.x - dot0.x));
//	printf("GoodBye x:%f y:%f\n", dx, dy);
	while((int)dot0.x != (int)dot1.x || (int)dot0.y != (int)dot1.y)
	{
		dot0.x += dx;
		dot0.y += dy;
//		dot1.color;
		printf("0:%f|%f, 1:%f|%f\n", dot0.x, dot0.y, dot1.x, dot1.y);
//		exit (1);
//		img_drawpixel(cimg.img_data, mlx.mlx_ptr, dot0.x, dot0.y, 0x00FFFF, cimg.size_line);
	}
	img_drawpixel(cimg.img_data, mlx.mlx_ptr, dot1.x, dot1.y, 0xFF0000, cimg.size_line);
//	printf("GoodBye\n");
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
	printf("Hello1\n");
	while (i < map.h - 1)
	{
		j = 0;
		while (j < map.w - 1)
		{
			printf("Hello2\n");
			img_drawline(dot[i * map.w + j], dot[(i + 1) * map.w + j], cimg, mlx);
			printf("Hello2\n");
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
	printf("Hello\n");
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, size_x, size_y, title);
	printf("Hello\n");
//	start = map;
//	save default coords
//	img_rotate(map);
	cimg = img_drawmap(map, size_x, size_y, mlx);//?
	printf("Hello\n");
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, cimg.img_ptr, 0, 0);
	mlx_key_hook(mlx.win_ptr, hook_keydown, (void *)0);
	mlx_loop(mlx.mlx_ptr);
	printf("END\n");
}
