/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_drawpixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 21:41:41 by bparker           #+#    #+#             */
/*   Updated: 2019/01/11 11:49:43 by bparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_drawpixel(char *img_data, void *mlx_ptr, t_vec4 dot, int line_size)
{
	unsigned int	col1;
	unsigned int	*pix_ptr;

	printf("start[%d][%d]\n", dot.x, dot.y);
	col1 = mlx_get_color_value(mlx_ptr, dot.color == 0 ? 0xFFFFFF : dot.color);
	pix_ptr = (unsigned int *)(img_data + dot.x * 4 + line_size * dot.y);
//	printf("%p\n", pix_ptr);
	*pix_ptr = col1;
//	printf("end\n");
}

void	 img_drawpixelsafe(char *img_data, void *mlx_ptr, t_vec4 dot, int line_size, t_vec2 map)
{
	unsigned int	col1;
	unsigned int	*pix_ptr;

	printf("hello\n");
	if (dot.x < 0 || dot.x >= map.x || dot.y < 0 || dot.y >= map.y)
		return ;
	printf("???%d\n", map.y);
	col1 = mlx_get_color_value(mlx_ptr, dot.color == 0 ? 0xFFFFFF : dot.color);
	pix_ptr = (unsigned int *)(img_data + dot.x * 4 + line_size * dot.y);
	*pix_ptr = col1;
	printf("ne fact\n");
}
