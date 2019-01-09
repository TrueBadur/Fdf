/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 11:17:51 by bparker           #+#    #+#             */
/*   Updated: 2019/01/09 11:23:50 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"
/*
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
*/
void	print_map(t_vec4 *v, void *data)
{
	printf("%s (x = %f, y = %f, z = %f, col = %X)\n",(char *)data, v->x, v->y, v->z, v->color);
}

int		main(int ac, char **av)
{
	t_mlx	mlx;
	t_map	*b_map;
	t_map	*c_map;
	t_vec2	res;

	//	t_coords	xy;

	if (ac == 1 || ac == 3 || ac > 4)
		exit(ft_error(ARG_ERROR));
	if (ac == 4)
	{
		res.x = ft_atoi(av[2]);
		res.x = res.x ? res.x : 1024;
		res.y = ft_atoi(av[3]);
		res.y = res.y ? res.y : 1024;
	}
	mlx.mlx_ptr = mlx_init();
	b_map = ft_get_map(av[1]);
//	ft_fit_map(b_map, res);
	c_map = ft_rotate_map(b_map, 55, 0, 45);
	printf("___________________\n");
	ft_mapiter(c_map, &ft_point_move, (int[]){300, 300, 0});
	ft_mapiter(c_map, &print_map, &"1");
	img_draw(*c_map, 2048, 2048, av[1]);
		//	ft_scale(map);
		//	ft_rotate(map);
		//		mlx_ptr = mlx_init();
		//		win_ptr = mlx_new_window(mlx_ptr, 1024, 1024, "SuperTittle");
	//		mlx_key_hook(win_ptr, hook_keydown, (void *)0);
		//		mlx_loop(mlx_ptr);
	return (0);
}
