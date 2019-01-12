/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 11:17:51 by bparker           #+#    #+#             */
/*   Updated: 2019/01/12 16:17:31 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"
#include "fdf.h"

t_map	*ft_transform_map(t_map *mp, t_trnsfrm *trnsfrm)
{
	t_mtrx	*tmtrx;
	t_map	*map_c;

	tmtrx = ft_mtrx_ident(4, MTRX_DOUBLE);
//	printf("=================================\n");
//	ft_mtrx_print(tmtrx);
//	printf("=================================\n");
	tmtrx = ft_mtrx_mlt_destr(tmtrx, ft_move_mtrx(trnsfrm->mov));
	if (trnsfrm->persp)
		tmtrx = ft_mtrx_mlt_destr(tmtrx, ft_persp_mtrx(trnsfrm->persp));
//	printf("=================================\n");
//	ft_mtrx_print(tmtrx);
//	printf("=================================\n");
	tmtrx = ft_mtrx_mlt_destr(tmtrx, ft_move_mtrx(trnsfrm->mov1));
	tmtrx = ft_mtrx_mlt_destr(tmtrx, ft_rotate_mtrx(trnsfrm->rot));
//	printf("=================================\n");
//	ft_mtrx_print(tmtrx);
//	printf("=================================\n");
	tmtrx = ft_mtrx_mlt_destr(tmtrx, ft_scale_mtrx(trnsfrm->scale));
//	printf("=================================\n");
//	ft_mtrx_print(tmtrx);
//	printf("=================================\n");
	trnsfrm->b = 0;
//	printf("=================================\n");
//	ft_mtrx_print(tmtrx);
//	printf("=================================\n");
	map_c = ft_mapiter_c(mp, &ft_transform_point, tmtrx);
	ft_mtrx_destroy(&tmtrx);
	return (map_c);
}

int		img_to_win(void *param)
{
	t_img		img;
	t_map		*mp;
	t_map		*mp_c;
	t_mlx		*mlx;
	t_trnsfrm	*t;

	mp = (t_map *)(((int **)param)[0]);
	t = (t_trnsfrm *)(((int **)param)[1]);
	mlx = (t_mlx *)(((int **)param)[2]);
	//printf("-------------------------------------------\ntransform before img_to_win\nrot.x = %d, rot.y = %d, rot.z = %d\nmove.x = %d, move.y = %d, move.z = %d\nscale.x = %f, scale.y = %f, scale.z = %f\npersp = %d\nb = %d\n-------------------------------------------\n",
	//		t->rot.x, t->rot.y, t->rot.z,
	//		t->mov.x, t->mov.y, t->mov.z,
	//		t->scale.x, t->scale.y, t->scale.z,
	//		t->persp, t->b);
	if (!t->b)
		return (1);
	mp_c = ft_transform_map(mp, t);
	ft_mapiter(mp_c, &print_map, NULL);
	img = img_draw(*mp_c, mlx->res, *mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img_ptr, 0, 0);
	map_free(&mp_c);
	mlx_destroy_image(mlx->mlx_ptr, img.img_ptr);
	return (0);
}

int		hook_keydwn(int key, void *param)
{
	t_map		*c_map;
	t_trnsfrm	*t;
	t_map		*mp;

	printf("%d\n", key);
	if (key == 53)
		exit(0);
	t = (t_trnsfrm *)(((int **)param)[1]);
	mp = (t_map *)(((int **)param)[0]);
	if (key == 35 || key == 30 || key == 33)
	{
		t->b = 1;
		if (key == 35)
			t->persp = t->persp ? 0 : 1;
		if (key == 30 && t->persp > 1)
			t->persp--;
		if (key == 33 && t->persp != 0)
			t->persp++;
	}
	if (key == 5 || key == 17)
	{
		t->b = 1;
		if (key == 5)
			t->mov1.z += 3 *  mp->w;
		if (key == 17)
			t->mov1.z -= 3 * mp->w;
	}
	if (key == 0 || key == 1 || key == 12 || key == 13 || key == 6 || key == 7)
	{
		t->b = 1;
		if (key == 0)
			t->rot.z -= 5;
		else if (key == 1)
			t->rot.z += 5;
		else if (key == 6)
			t->rot.x -= 5;
		else if (key == 7)
			t->rot.x += 5;
		else if (key == 12)
			t->rot.y -= 5;
		else if (key == 13)
			t->rot.y += 5;
	}	
	if (t->b)
		img_to_win(param);
	return (0);
}

static void init(int ac, char **av, t_trnsfrm *t, t_mlx *mlx)
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
	t->mov.x = mlx->res.x / 2;
	t->mov.y = mlx->res.y / 2;
	t->mov.z = 0;
	t->mov1.x = 0;
	t->mov1.y = 0;
	t->mov1.z = 0;
	t->persp = 0;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->res.x, mlx->res.y,
			MW_NAME);
	t->b = 1;
}

int		main(int ac, char **av)
{
	t_mlx		mlx;
	t_map		*b_map;
	t_trnsfrm	trnsfrm;

	//	t_coords	xy;

	if (ac == 1 || ac == 3 || ac > 4)
		exit(ft_error(ARG_ERROR));
	b_map = ft_get_map(av[1]);
	init(ac, av, &trnsfrm, &mlx);
	//ft_fit_map(b_map, &trnsfrm, mlx.res);
	img_to_win((int *[]){(int *)b_map, (int *)&trnsfrm, (int *)&mlx});
	mlx_hook(mlx.win_ptr, 2, 5,  hook_keydwn,
			(int *[]){(int *)b_map, (int *)&trnsfrm, (int *)&mlx});
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
