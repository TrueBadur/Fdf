/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrx_mlt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:36:33 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/10 23:06:22 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtrx.h"

static void	intiter(t_mtrx *ret, t_mtrx *m1, t_mtrx *m2)
{
	int		i;
	int		j;

	i = m1->h * m2->w;
	while (i--)
	{
		j = m1->w;
		while (j--)
		{
			((int *)(ret->mtrx))[i] += ((int *)(m1->mtrx))[(i / m1->h - 1) *
					m1->w + j] * ((int *)(m2->mtrx))[m2->w * j + i % m2->w];
		}
	}
}

static void doubleiter(t_mtrx *ret, t_mtrx *m1, t_mtrx *m2)
{
	int		i;
	int		j;

	i = m1->h * m2->w;
	while (i--)
	{
		j = m1->w;
		while (j--)
		{
			((double *)(ret->mtrx))[i] += ((double *)(m1->mtrx))[(i / m1->h - 1)
				* m1->w + j] * ((double *)(m2->mtrx))[m2->w * j + i % m2->w];
		}
	}
}

t_mtrx	*ft_mtrx_mlt(t_mtrx *m1, t_mtrx *m2)
{
	t_mtrx	*ret;

	if (m1->w != m2->h || m1->el_size != m2->el_size)
		return (NULL);
	if (!(ret = ft_mtrx_init(m1->h, m2->w, m1->el_size)))
		return (NULL);
	if (m1->el_size == MTRX_INT)
		intiter(ret, m1, m2);
	else if (m1->el_size == MTRX_DOUBLE)
		doubleiter(ret, m1, m2);
	return (ret);
}
