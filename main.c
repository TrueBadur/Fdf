/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 11:17:51 by bparker           #+#    #+#             */
/*   Updated: 2019/01/14 20:33:02 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"
#include "fdf.h"

t_map		*ft_transform_map(t_map *mp, t_trnsfrm *trnsfrm)
{
	t_mtrx	*tmtrx;
	t_map	*map_c;

	tmtrx = ft_mtrx_ident(4, MTRX_DOUBLE);
	tmtrx = ft_mtrx_mlt_destr(tmtrx, ft_move_mtrx(trnsfrm->mov_scr));
	if (trnsfrm->persp)
		tmtrx = ft_mtrx_mlt_destr(tmtrx, ft_persp_mtrx(trnsfrm->persp));
	tmtrx = ft_mtrx_mlt_destr(tmtrx, ft_move_mtrx(trnsfrm->mov_wrld));
	tmtrx = ft_mtrx_mlt_destr(tmtrx, ft_rotate_mtrx(trnsfrm->rot));
	tmtrx = ft_mtrx_mlt_destr(tmtrx, ft_scale_mtrx(trnsfrm->scale));
	trnsfrm->b = 0;
	map_c = ft_mapiter_c(mp, &ft_transform_point, tmtrx);
	ft_mtrx_destroy(&tmtrx);
	return (map_c);
}

int			img_to_win(void *param)
{
	t_img		img;
	t_map		*mp;
	t_map		*mp_c;
	t_mlx		*mlx;
	t_trnsfrm	*t;

	mp = (t_map *)(((int **)param)[0]);
	t = (t_trnsfrm *)(((int **)param)[1]);
	mlx = (t_mlx *)(((int **)param)[2]);
	if (!t->b)
		return (1);
	mp_c = ft_transform_map(mp, t);
	img = img_draw(*mp_c, mlx->res, *mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img_ptr, 0, 0);
	map_free(&mp_c);
	mlx_destroy_image(mlx->mlx_ptr, img.img_ptr);
	return (0);
}

static void	init(int ac, char **av, t_trnsfrm *t, t_mlx *mlx)
{
	mlx->res.x = 1024;
	mlx->res.y = 1024;
	if (ac == 4)
	{
		mlx->res.x = ft_atoi(av[2]);
		mlx->res.x = mlx->res.x ? mlx->res.x : 1024;
		mlx->res.y = ft_atoi(av[3]);
		mlx->res.y = mlx->res.y ? mlx->res.y : 1024;
	}
	t->rot.x = 55;
	t->rot.y = 0;
	t->rot.z = 45;
	t->scale.x = 30.0;
	t->scale.y = 30.0;
	t->scale.z = 6.0;
	t->mov_scr.x = mlx->res.x / 2;
	t->mov_scr.y = mlx->res.y / 2;
	t->mov_scr.z = 0;
	t->mov_wrld.x = 0;
	t->mov_wrld.y = 0;
	t->mov_wrld.z = 0;
	t->persp = 0;
	t->b = 1;
}

int			main(int ac, char **av)
{
	t_mlx		mlx;
	t_map		*b_map;
	t_trnsfrm	trnsfrm;

	if (ac == 1 || ac == 3 || ac > 4)
		exit(ft_error(ARG_ERROR));
	b_map = ft_get_map(av[1]);
	init(ac, av, &trnsfrm, &mlx);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.res.x, mlx.res.y, MW_NAME);
	img_to_win((int *[]){(int *)b_map, (int *)&trnsfrm, (int *)&mlx});
	mlx_hook(mlx.win_ptr, 2, 5, hook_keydwn,
			(int *[]){(int *)b_map, (int *)&trnsfrm, (int *)&mlx});
	mlx_mouse_hook(mlx.win_ptr, &mouse_hook,
			(int *[]){(int *)b_map, (int *)&trnsfrm, (int *)&mlx});
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
