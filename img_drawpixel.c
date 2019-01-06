/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_drawpixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 21:41:41 by bparker           #+#    #+#             */
/*   Updated: 2019/01/06 12:16:09 by bparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_drawpixel(char *img_data, void *mlx_ptr, int x, int y, int col, int line_size)
{
	unsigned int	col1;
	unsigned int	*pix_ptr;

	col1 = mlx_get_color_value(mlx_ptr, col);
	pix_ptr = (unsigned int *)(img_data + x * 4 +	line_size * y);
//	printf("pix2\n");
	*pix_ptr = col1;
	printf("pix3:%p [%d] col: %d\n", pix_ptr, *pix_ptr, col);
}
