/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 02:57:48 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/11 03:05:00 by ehugh-be         ###   ########.fr       */
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
