/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 11:17:51 by bparker           #+#    #+#             */
/*   Updated: 2019/01/11 10:53:11 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

t_map	*ft_transform_map(t_map *mp, t_trnsfrm *trnsfrm)
{
	t_mtrx	*tmtrx;
	t_map	*map_c;

	tmtrx = ft_mtrx_ident(4, MTRX_DOUBLE);
	tmtrx = ft_mtrx_mlt_destr(tmtrx, ft_move_mtrx(trnsfrm->mov));
	tmtrx = ft_mtrx_mlt_destr(tmtrx, ft_rotate_mtrx(trnsfrm->rot));
	tmtrx = ft_mtrx_mlt_destr(tmtrx, ft_scale_mtrx(trnsfrm->scale));
	printf("+++++++++++++++\n");
	ft_mtrx_print(tmtrx);
	printf("---------------\n");
	printf("+++++++++++++++\n");
	ft_mtrx_print(tmtrx);
	printf("---------------\n");
	printf("+++++++++++++++\n");
	ft_mtrx_print(tmtrx);
	printf("---------------\n");
	if (trnsfrm->persp)
		tmtrx = ft_mtrx_mlt_destr(tmtrx, ft_persp_mtrx(trnsfrm->persp));
	printf("+++++++++++++++\n");
	ft_mtrx_print(tmtrx);
	printf("---------------\n");
	trnsfrm->b = 0;
	return (ft_mapiter_c(mp, &ft_transform_point, tmtrx));
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
	if (!t->b)
		return (1);
	printf("HELLO!1\n");
	mp_c = ft_transform_map(mp, t);
	ft_mapiter(mp_c, &print_map, NULL);
	img = img_draw(*mp_c, mlx->res, *mlx);
	printf("HELLO!3\n");
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img_ptr, 0, 0);
	printf("HELLO!4\n");
	map_free(&mp_c);
	printf("HELLO!5\n");
	mlx_destroy_image(mlx->mlx_ptr, img.img_ptr);
	printf("HELLO!^\n");
	return (0);
}

int		hook_keydwn(int key, void *param)
{
	t_map *c_map;

	printf("%d\n", key);
	if (key == 53)
		exit(0);
	if (key == 0 || key == 1 || key == 12 || key == 13 || key == 6 || key == 7)
	{
		((t_trnsfrm *)(((size_t *)param)[1]))->b = 1;
		if (key == 0)
			((t_trnsfrm *)(((size_t *)param)[1]))->rot.z -= 5;
		else if (key == 1)
			((t_trnsfrm *)(((size_t *)param)[1]))->rot.z += 5;
		else if (key == 6)
			((t_trnsfrm *)(((size_t *)param)[1]))->rot.x -= 5;
		else if (key == 7)
			((t_trnsfrm *)(((size_t *)param)[1]))->rot.x += 5;
		else if (key == 12)
			((t_trnsfrm *)(((size_t *)param)[1]))->rot.y -= 5;
		else if (key == 13)
			((t_trnsfrm *)(((size_t *)param)[1]))->rot.y += 5;
//		c_map = ft_rotate_map(((t_map **)param)[0], *(((t_vec3 **)param)[1]));
//		img_to_win(param);
//		printf("xr = %d, yr = %d, zr = %d\n", (*(((t_vec3 **)param)[1])).x, (*(((t_vec3 **)param)[1])).y,(*(((t_vec3 **)param)[1])).z);
	}	
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
	t->scale.x = 30;
	t->scale.y = 30;
	t->scale.z = 6;
	t->mov.x = mlx->res.x / 2;
	t->mov.y = mlx->res.y / 2;
	t->mov.z = 0;
	t->persp = 1;
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
	mlx_loop_hook(mlx.mlx_ptr, &img_to_win,
			(int *[]){(int *)b_map, (int *)&trnsfrm, (int *)&mlx});
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
