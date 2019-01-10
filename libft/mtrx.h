/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:49:03 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/10 23:17:13 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTRX_H
# define MTRX_H
# define MTRX_INT 1
# define MTRX_DOUBLE 2
# include "libft.h"

typedef struct		s_matrix
{
	int				w;
	int				h;
	void			*mtrx;
	unsigned char	el_size;
}					t_mtrx;

void				ft_mtrx_destroy(t_mtrx **mtrx);
t_mtrx				*ft_mtrx_init(int w, int h, unsigned char el_size);
t_mtrx				*ft_mtrx_mlt(t_mtrx *mtrx1, t_mtrx *mtrx2);
#endif
