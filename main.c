/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 11:17:51 by bparker           #+#    #+#             */
/*   Updated: 2019/01/10 22:08:44 by ehugh-be         ###   ########.fr       */
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
	t_vec3 v;

	if (mp->y_m < 0 || mp->x_m < 0)
	{
		v.x = res.x / 2 - ((t_vec4 *)mp->vec->data)[mp->h / 2 * mp->w + mp->w / 2].x;
		v.y = res.y / 2 - ((t_vec4 *)mp->vec->data)[mp->h / 2 * mp->w + mp->w / 2].y;
		v.z = 0;
		ft_mapiter(mp, &ft_point_move, &v);
	}
	img = img_draw(*mp, res, mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
	map_free(&mp);
	mlx_destroy_image(mlx.mlx_ptr, img.img_ptr);
}

int		hook_keydwn(int key, void *param)
{
	t_map *c_map;

	printf("%d\n", key);
	if (key == 53)
		exit(0);
	if (key == 0 || key == 1 || key == 12 || key == 13 || key == 6 || key == 7)
	{
		if (key == 0)
			((t_vec3 *)(((size_t *)param)[1]))->z -= 5;
		else if (key == 1)
			((t_vec3 *)(((size_t *)param)[1]))->z += 5;
		else if (key == 6)
			((t_vec3 *)(((size_t *)param)[1]))->x -= 5;
		else if (key == 7)
			((t_vec3 *)(((size_t *)param)[1]))->x += 5;
		else if (key == 12)
			((t_vec3 *)(((size_t *)param)[1]))->y -= 5;
		else if (key == 13)
			((t_vec3 *)(((size_t *)param)[1]))->y += 5;
		c_map = ft_rotate_map(((t_map **)param)[0], *(((t_vec3 **)param)[1]));
		img_to_win(c_map, *((t_mlx *)(((size_t *)param)[2])), (*(((t_vec2 **)param)[3])));
		printf("xr = %d, yr = %d, zr = %d\n", (*(((t_vec3 **)param)[1])).x, (*(((t_vec3 **)param)[1])).y,(*(((t_vec3 **)param)[1])).z);
	}	
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx	mlx;
	t_map	*b_map;
	t_map	*c_map;
	t_vec2	res;
	t_vec3	rot;

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
	rot.x = 0;
	rot.y = 0;
	rot.z = 0;
	mlx.mlx_ptr = mlx_init();
	b_map = ft_get_map(av[1]);
	ft_fit_map(b_map, res);
	c_map = ft_rotate_map(b_map, rot);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, res.x, res.y, "SuperTittle");
	img_to_win(c_map, mlx, res);
	mlx_hook(mlx.win_ptr, 2, 5,  hook_keydwn, (size_t *[]){b_map, &rot, &mlx, &res});
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
