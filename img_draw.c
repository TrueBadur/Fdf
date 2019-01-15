/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:32:21 by bparker           #+#    #+#             */
/*   Updated: 2019/01/15 03:07:14 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_check_x(t_map map, t_mlx mlx, t_img cimg, t_vec2 ij)
{
	int		check;
	t_vec4	*dot;

	dot = (t_vec4*)(map.vec->data);
	check = border_check(dot[ij.x * map.w + ij.y], dot[(ij.x + 1) * map.w +
			ij.y], mlx.res);
	if (check == 1)
		img_drawline(dot[ij.x * map.w + ij.y], dot[(ij.x + 1) * map.w + ij.y],
				mlx, cimg);
	if (check == -1)
		img_drawlinesafe(dot[ij.x * map.w + ij.y],
				dot[(ij.x + 1) * map.w + ij.y], mlx, cimg);
}

static void	ft_check_y(t_map map, t_mlx mlx, t_img cimg, t_vec2 ij)
{
	int		check;
	t_vec4	*dot;

	dot = (t_vec4*)(map.vec->data);
	check = border_check(dot[ij.x * map.w + ij.y], dot[ij.x * map.w + ij.y + 1],
			mlx.res);
	if (check == 1)
		img_drawline(dot[ij.x * map.w + ij.y], dot[ij.x * map.w + ij.y + 1],
				mlx, cimg);
	if (check == -1)
		img_drawlinesafe(dot[ij.x * map.w + ij.y], dot[ij.x * map.w + ij.y + 1],
				mlx, cimg);
}

t_img		img_draw(t_map map, t_vec2 vec, t_mlx mlx)
{
	int		i;
	int		j;
	t_img	cimg;

	i = -1;
	cimg.img_ptr = mlx_new_image(mlx.mlx_ptr, vec.x, vec.y);
	cimg.img_data = mlx_get_data_addr(cimg.img_ptr, &cimg.bpp,
			&cimg.size_line, &cimg.endian);
	while (++i < map.h)
	{
		j = 0;
		while (j < map.w)
		{
			if (i != map.h - 1)
				ft_check_x(map, mlx, cimg, (t_vec2){i, j});
			if (j != map.w - 1)
				ft_check_y(map, mlx, cimg, (t_vec2){i, j});
			j++;
		}
	}
	return (cimg);
}
