/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bparker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 07:52:26 by bparker           #+#    #+#             */
/*   Updated: 2019/01/11 11:59:38 by bparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	border_check(t_vec4 dot0, t_vec4 dot1, t_vec2 map)
{
	if ((dot0.x >= map.x && dot1.x >= map.x)
			|| (dot0.y >= map.y && dot1.y >= map.y) ||
			(dot0.x < 0 && dot1.x < 0) || (dot0.y < 0 && dot1.y < 0))
		return (0);
	if (dot0.x >= map.x || dot0.y >= map.y || dot0.x < 0 || dot0.y < 0 ||
			dot1.x >= map.x || dot1.y >= map.y || dot1.x < 0 || dot1.y < 0)
		return (-1);
	return (1);
}
