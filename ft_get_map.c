/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 20:09:16 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/15 03:42:57 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

static int	ft_get_color(char *pt, int alt)
{
	int		ret;
	char	t;

	if (!pt)
	{
		if (alt >= 0 && alt < 10)
			return (0x00FF00);
		if (alt < 0)
			return (0x0000FF);
		if (alt >= 10 && alt < 20)
			return (0xD2691E);
		if (alt >= 10 && alt < 20)
			return (0xFFFFFF);
	}
	if (*(++pt) != '0' || *(++pt) != 'x')
		exit(ft_error(CONT_ERR_CS));
	ret = 0;
	while ((t = ft_tolower(*(++pt))) && ((t >= '0' && t <= '9') ||
				(t >= 'a' && t <= 'f')))
	{
		if (t >= '0' && t <= '9')
			ret = ret * 16 + t - '0';
		else
			ret = ret * 16 + t - 'a' + 10;
	}
	if (*pt)
		exit(ft_error(CONT_ERR_CE));
	return (ret);
}

static int	ft_fill_row(t_map *fdf, char *line, int row)
{
	char	**tmp;
	int		i;
	t_vec4	point;

	tmp = ft_strsplit(line, ' ');
	i = -1;
	while (tmp[++i])
	{
		point.x = i;
		point.y = row;
		if ((tmp[i][0] < '0' || tmp[i][0] > '9') && tmp[i][0] != '-')
			exit(ft_error(CONT_ERR_NE));
		point.z = ft_atoi(tmp[i]);
		if (point.z > fdf->d)
			fdf->d = point.z;
		point.color = ft_get_color(ft_strchr(tmp[i], ','), point.z);
		fdf->vec = ft_vecpush(fdf->vec, &point, sizeof(t_vec4));
	}
	return (i);
}

void		ft_center_map(t_map *fdf)
{
	t_vec3 v;

	v.x = -(fdf->w / 2);
	v.y = -(fdf->h / 2);
	v.z = 0;
	ft_mapiter(fdf, &ft_point_move, &v);
}

t_map		*ft_map_init(void)
{
	t_map *fdf;

	if (!(fdf = malloc(sizeof(t_map))))
		return (NULL);
	fdf->w = 0;
	fdf->h = 0;
	fdf->d = 0;
	if (!(fdf->vec = ft_vecinit(2)))
		return (NULL);
	return (fdf);
}

t_map		*ft_get_map(char *fname)
{
	int		fd;
	char	*line;
	t_map	*fdf;
	int		row;

	if ((fd = open(fname, O_RDONLY)) < 0)
		exit(ft_error(FILE_ERROR));
	if (!(fdf = ft_map_init()))
		return (NULL);
	row = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (fdf->w == 0)
			fdf->w = ft_fill_row(fdf, line, row);
		else if (fdf->w != ft_fill_row(fdf, line, row))
			exit(ft_error(CONT_ERR_NO));
		row++;
	}
	fdf->x_m = 0;
	fdf->x = fdf->w;
	fdf->h = row;
	fdf->y = row;
	fdf->y_m = 0;
	ft_center_map(fdf);
	return (fdf);
}
