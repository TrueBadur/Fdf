/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:08:34 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/14 20:26:41 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# define MW_NAME "FDF by bparker and ehugh-be"
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
# define ARG_ERROR 3
# define ARG_ERROR_MSG "error: insufficient number of arguments\n"
# define USAGE_MSG "usage: ./fdf file_to_open [window_width window_height]\n"

typedef struct	s_map
{
	int			w;
	int			h;
	int			x_m;
	int			x;
	int			y;
	int			y_m;
	int			d;
	t_vector	*vec;
}				t_map;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_vec2		res;
}				t_mlx;

typedef struct	s_transforms
{
	t_vec3		rot;
	t_vec3_f	scale;
	t_vec3		mov_scr;
	t_vec3		mov_wrld;
	int			persp;
	char		b;
}				t_trnsfrm;

typedef struct	s_img
{
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

t_map			*ft_get_map(char *fname);
int				ft_error(int er);
void			ft_mapiter(t_map *mp, void (*f)(t_vec4 *, void *), void *data);
t_map			*ft_mapiter_c(t_map *mp, void (*f)(t_vec4 *, void *),
								void *data);
void			img_drawpixel(char *img_data, void *mlx_ptr, t_vec4 dot, int line_size);
void			img_drawpixelsafe(char *img_data, void *mlx_ptr, t_vec4 dot, int line_size, t_vec2 map);
void			img_drawline(t_vec4 dot0, t_vec4 dot1, t_mlx mlx, t_img cimg);
void			img_drawlinesafe(t_vec4 dot0, t_vec4 dot1, t_mlx mlx, t_img cimg, t_vec2 map);
t_img			img_draw(t_map map, t_vec2 vec, t_mlx mlx);
int				border_check(t_vec4 dot0, t_vec4 dot1, t_vec2 map);
t_map			*ft_rotate_map(t_map *mp, t_vec3 vec);
void			ft_transform_point(t_vec4 *v, void *data);
void			ft_point_move(t_vec4 *v, void *data);
void			ft_point_scale(t_vec4 *v, void *data);
void			ft_point_rot(t_vec4 *v, void *data);
void			print_map(t_vec4 *v, void *data);
void			ft_fit_map(t_map *mp, t_trnsfrm *tr, t_vec2 res);
t_mtrx			*x_rot_mtrx(int x);
t_mtrx			*y_rot_mtrx(int y);
t_mtrx			*z_rot_mtrx(int z);
t_mtrx			*ft_scale_mtrx(t_vec3_f v);
t_mtrx			*ft_rotate_mtrx(t_vec3 v);
t_mtrx			*ft_move_mtrx(t_vec3 v);
t_mtrx			*ft_persp_mtrx(int z);
void			map_free(t_map **mp);
void			mlx_free(t_mlx **mlx);
int				img_to_win(void *param);
int				hook_keydwn(int key, void *param);
int				mouse_hook(int but, int x, int y, void *param);
#endif
