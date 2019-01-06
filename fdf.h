/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:08:34 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/06 10:14:52 by bparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# define CONT_ERR 5
# define CONT_ERR_MSG "error: wrong data in file\n"
# define CONT_ERR_CS 51
# define CONT_ERR_CS_MSG "wrong start of color sequence\n"
# define CONT_ERR_CE 52
# define CONT_ERR_CE_MSG "wrong end of color sequence\n"
# define CONT_ERR_NE 53
# define CONT_ERR_NE_MSG "wrong number format\n"
# define CONT_ERR_NO 54
# define CONT_ERR_NO_MSG "wrong number of objects in line\n"
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

typedef struct  s_img
{
	void    *img_ptr;
	char    *img_data;
	int     bpp;
	int     size_line;
	int     endian;
}               t_img;

t_map	*ft_get_map(char *fname);
int		ft_error(int er);
void	ft_mapiter(t_map *mp, void (*f)(t_vec4 *, void *), void *data);
t_map	*ft_mapiter_c(t_map *mp, void (*f)(t_vec4 *, void *), void *data);
void    img_drawpixel(char *img_data, void *mlx_ptr, int x, int y, int col, int line_size);
void    img_draw(t_map map, int size_x, int size_y, char *title);

#endif
