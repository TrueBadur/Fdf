/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:08:34 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/30 04:21:43 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# define CONTENT_ERROR 5
# define CONTENT_ERROR_MSG "error: wrong data in file\n"
# define FILE_ERROR 3
# define FILE_ERROR_MSG "error: can't open file\n"


typedef struct	s_map
{
	int			w;
	int			h;
	int			d;
	t_vector	*vec;
}				t_map;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

t_map	*ft_get_map(char *fname);
int		ft_error(int er);
#endif
