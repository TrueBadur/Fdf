/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_drawpixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 21:41:41 by bparker           #+#    #+#             */
/*   Updated: 2019/01/09 15:36:14 by bparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_drawpixel(char *img_data, void *mlx_ptr, t_vec4 dot, int line_size)
{
	unsigned int	col1;
	unsigned int	*pix_ptr;

	col1 = mlx_get_color_value(mlx_ptr, dot.color == 0 ? 0xFFFFFF : dot.color);
	pix_ptr = (unsigned int *)(img_data + dot.x * 4 + line_size * dot.y);
	*pix_ptr = col1;
}
