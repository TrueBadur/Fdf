/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:49:03 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/07 20:24:42 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTRX_H
# define MTRX_H
# include "libft.h"

typedef struct	s_matrix_i
{
	int			w;
	int			h;
	int			*mtrx;
}				t_mtrx_i;

typedef struct	s_matrix_d
{
	int			w;
	int			h;
	double		*mtrx;
}				t_mtrx_d;

t_mtrx_i		*ft_mtrx_mlt_i(t_mtrx_i *mtrx1, t_mtrx_i *mtrx2);
t_mtrx_d		*ft_mtrx_mlt_d(t_mtrx_d *mtrx1, t_mtrx_d *mtrx2);
#endif
