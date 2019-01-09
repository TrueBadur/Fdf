/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 11:17:51 by bparker           #+#    #+#             */
/*   Updated: 2019/01/09 14:46:30 by bparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void	map_free(t_map **mp)
{
	ft_vecdel((void **)&(*mp)->vec);
	free(*mp);
	*mp = NULL;
}

void	img_to_win(t_map *mp, t_mlx mlx, t_vec2 res)
{
	t_img img;

	img = img_draw(*mp, res, mlx);
	printf("Hello!\n");
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
	map_free(&mp);
	mlx_destroy_image(mlx.mlx_ptr, img.img_ptr);
}

int		hook_keydwn(int key, void *param)
{
	t_map *c_map;

	if (key == 53)
		exit(0);
	if (key == 0 || key == 1)
	{
		if (key == 0)
			c_map = ft_rotate_map((t_map *)param, 0, 0, 5);
		else if (key == 1)
			c_map = ft_rotate_map((t_map *)param, 0, 0, -5);
		img_to_win(c_map, *((t_mlx *)param), ((t_vec2 *)param)[1]);
	}	
	return (0);
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
	res.x = 1024;
	res.y = 1024;
	if (ac == 4)
	{
		res.x = ft_atoi(av[2]);
		res.x = res.x ? res.x : 1024;
		res.y = ft_atoi(av[3]);
		res.y = res.y ? res.y : 1024;
	}
	mlx.mlx_ptr = mlx_init();
	b_map = ft_get_map(av[1]);
	ft_fit_map(b_map, res);
	c_map = ft_rotate_map(b_map, 55, 0, 45);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, res.x, res.y, "SuperTittle");
	img_to_win(c_map, mlx, res);
	mlx_key_hook(mlx.win_ptr, hook_keydwn, (int *[]){(int *)&mlx, (int *)&res});
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
