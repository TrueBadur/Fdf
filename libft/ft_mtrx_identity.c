/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrx_identity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 07:22:29 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/11 07:33:54 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtrx.h"

t_mtrx	*ft_mtrx_ident(int w, unsigned char el_size)
{
	t_mtrx	*ret;
	int		t;

	if (!w)
		return (NULL);
	if (!(ret = malloc(sizeof(t_mtrx))))
		return (NULL);
	if (el_size == MTRX_INT)
		t = sizeof(int);
	else
		t = sizeof(double);
	if (!(ret->mtrx = malloc(w * w * t)))
	{
		free(ret);
		return (NULL);
	}
	ret->w = w;
	ret->h = w;
	ret->el_size = el_size;
	t = w;
	if (el_size == MTRX_DOUBLE)
		while (t--)
			((double *)ret->mtrx)[t * ret->w + t] = 1.0f;
	else
		while (t--)
			((int *)ret->mtrx)[t * ret->w + t] = 1;
	return (ret);
}
