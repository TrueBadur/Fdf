/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrx_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 04:31:51 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/11 09:19:15 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtrx.h"
#include <stdio.h>

void	ft_mtrx_print(t_mtrx *m)
{
	printf("matrix %d x %d:\n", m->w, m->h);
	for (int i = 0; i < m->w * m->h; i++)
	{
		if (i % m->w == 0 && i > 0)
			printf("\n");
		printf("%.10f ", ((double *)m->mtrx)[i]);
	}
	printf("\n");
}
