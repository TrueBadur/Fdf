/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 07:52:26 by bparker           #+#    #+#             */
/*   Updated: 2019/01/12 18:19:18 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	border_check(t_vec4 dot0, t_vec4 dot1, t_vec2 map)
{
	if ((dot0.z >= 10000 && dot1.z >= 10000) ||
			(dot0.z < -10000 && dot1.z < -10000))
		return (0);
	if ((dot0.x >= map.x && dot1.x >= map.x) || 
			(dot0.y >= map.y && dot1.y >= map.y) ||
			(dot0.y >= map.y && dot1.y < 0) ||
			(dot0.y < 0 && dot1.y >= map.y) ||
			(dot0.x >= map.x && dot1.x < 0) ||
			(dot0.x < 0 && dot1.x >= map.y) ||
			(dot0.x < 0 && dot1.x < 0) || (dot0.y < 0 && dot1.y < 0))
		return (0);
	if (dot0.x >= map.x || dot0.y >= map.y || dot0.x < 0 || dot0.y < 0 ||
			dot1.x >= map.x || dot1.y >= map.y || dot1.x < 0 || dot1.y < 0)
	{
	if (dot0.z < -10000 || dot0.z > 10000 || dot1.z < -10000 || dot1.z > 10000)
		printf("dot0.x = %d, dot0.y = %d, dot0.z = %d\ndot1.x = %d, dot1.y = %d, dot1.z = %d\n",
				dot0.x, dot0.y, dot0.z, dot1.x, dot1.y, dot1.z);
		return (-1);
	}
	return (1);
}
