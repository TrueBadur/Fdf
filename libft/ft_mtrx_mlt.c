/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrx_mlt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:36:33 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/07 18:18:31 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mtrx_d	*ft_mtrx_mlt_d(t_mtrx_d *m1, t_mtrx_d *m2)
{
	t_mtrx_d	*ret;
	int			i;
	int			j;

	if (m1->w != m2->h)
		return (NULL);
	i = m1->h * m2->w;
	if (!(ret->mtrx = malloc(sizeof(double) * i)))
		return (NULL);
	ft_bzero(ret->mtrx, sizeof(double) * i);
	while (i--)
	{
		j = m1->w;
		while (j--)
		{
			(ret->mtrx)[i] += (m1->mtrx)[(i / m1->h - 1) * m1->w + j] *
							(m2->mtrx)[m2->w * j + i % m2->w]; 
		}
	}
	return (ret);
}
