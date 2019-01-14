/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_drawpixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 21:41:41 by bparker           #+#    #+#             */
/*   Updated: 2019/01/14 20:58:37 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_drawpxl(char *img_data, void *mlx_ptr, t_vec4 dot, int line_size)
{
	unsigned int	col1;
	unsigned int	*pix_ptr;

	col1 = mlx_get_color_value(mlx_ptr, dot.color == 0 ? 0xFFFFFF : dot.color);
	pix_ptr = (unsigned int *)(img_data + dot.x * 4 + line_size * dot.y);
	*pix_ptr = col1;
}

void	img_drawpxlsafe(char *img_data, t_mlx mlx, t_vec4 dot, int line_sz)
{
	unsigned int	col1;
	unsigned int	*pix_ptr;

	if (dot.x < 0 || dot.x >= mlx.res.x || dot.y < 0 || dot.y >= mlx.res.y)
		return ;
	col1 = mlx_get_color_value(mlx.mlx_ptr, dot.color == 0 ? 0xFFFFFF :
			dot.color);
	pix_ptr = (unsigned int *)(img_data + dot.x * 4 + line_sz * dot.y);
	*pix_ptr = col1;
}
