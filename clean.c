/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 02:57:48 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/18 16:56:01 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_free(t_map **mp)
{
	ft_vecdel((void **)&(*mp)->vec);
	free(*mp);
	*mp = NULL;
}

void	mlx_free(t_mlx **mlx)
{
	mlx_destroy_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
	free(*mlx);
	*mlx = NULL;
}

void	fdf_finish(t_map **mp, t_mlx **mlx)
{
	map_free(mp);
	mlx_free(mlx);
}
