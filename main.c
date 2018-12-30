/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 11:17:51 by bparker           #+#    #+#             */
/*   Updated: 2018/12/30 05:39:50 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void	drawlineeasy(double x0, double x1, double y0, double y1, void *mlx_ptr, void *win_ptr, int color)
{
	double	dx;
	double	dy;
	double	nani;

	dx = (x1 - x0) / (y1 - y0);
	if (y1 < y0)
		dx *= -1;
	dy = (y1 - y0) / (x1 - x0);
	if (x1 < x0)
		dy *= -1;
	nani = 0;
	if (fabs(y1 - y0) > fabs(x1 - x0))
		while (y0 != y1)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x0 + nani, y0, color);
			if (y0 < y1)
				y0++;
			else if (y0 > y1)
				y0--;
			nani += dx;
		}
	else
		while (x0 != x1)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x0, y0 + nani, color);
			if (x0 < x1)
				x0++;
			else if (x0 > x1)
				x0--;
			nani += dy;
		}
	mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, color);
}

int		hook_keydown(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(1);
	return (0);
}

int		main(int ac, char **av)
{
//	void	*mlx_ptr;
//	void	*win_ptr;
	t_map	*map;
//	t_coords	xy;

	if (ac == 2)
	{
		printf("HELLO!\n");
		map = ft_get_map(av[1]);
		printf("map = %p\n", map);
		t_vec4 *po = (t_vec4*)(map->vec->data);
		for (int i = map->w * map->h; i; i--)
		{
			printf("point %d (x = %f, y = %f, z = %f, col = %X)\n", i, (po[i]).x, (po[i]).y, (po[i]).z, (po[i]).color);
		}
	//	ft_rotate(map);
//		mlx_ptr = mlx_init();
//		win_ptr = mlx_new_window(mlx_ptr, 1024, 1024, "SuperTittle");
		/*drawlineeasy(100, 150, 100, 200, mlx_ptr, win_ptr, 0xFF0000);
		drawlineeasy(100, 150, 100, 0, mlx_ptr, win_ptr, 0x00FF00);
		drawlineeasy(200, 150, 100, 200, mlx_ptr, win_ptr, 0xFFFFFF);
		drawlineeasy(200, 150, 100, 0, mlx_ptr, win_ptr, 0x0000FF);
		drawlineeasy(300, 450, 100, 200, mlx_ptr, win_ptr, 0xFF0000);
		drawlineeasy(300, 450, 200, 100, mlx_ptr, win_ptr, 0x00FF00);
		drawlineeasy(650, 500, 200, 100, mlx_ptr, win_ptr, 0x0000FF);
		drawlineeasy(650, 500, 100, 200, mlx_ptr, win_ptr, 0xFFFFFF);
		drawlineeasy(850, 1000, 100, 100, mlx_ptr, win_ptr, 0xFFFFFF);
		drawlineeasy(950, 950, 100, 200, mlx_ptr, win_ptr, 0xFFFFFF);*/
//		mlx_key_hook(win_ptr, hook_keydown, (void *)0);
//		mlx_loop(mlx_ptr);
	}
	return (0);
}
