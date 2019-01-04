/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 20:09:16 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/04 18:05:20 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_color(char *pt)
{
	int ret;

	if (!pt)
		return (0);
	if (*(++pt) != '0' || *(++pt) != 'x')
		exit(ft_error(CONTENT_ERROR));
	ret = 0;
	while (*(++pt) && ((*pt >= '0' && *pt <= '9') || (*pt >= 'A' && *pt <= 'F')))
	{
		if (*pt >= '0' && *pt <= '9')
			ret = ret * 16 + *pt - '0';
		else
			ret = ret * 16 + *pt - 'A' + 10;
	}
	if (*pt)
		exit(ft_error(CONTENT_ERROR));
	return (ret);
}

static int ft_fill_row(t_map *fdf, char *line, int row)
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
			exit(ft_error(CONTENT_ERROR));
		point.z = ft_atoi(tmp[i]);
		if (point.z > fdf->d)
			fdf->d = point.z;
		point.color = ft_get_color(ft_strchr(tmp[i], ','));
		fdf->vec = ft_vecpush(fdf->vec, &point, sizeof(t_vec4));
	}
	//for (int j = fdf->vec->len
	return (i);
}

t_map *ft_get_map(char *fname)
{
	int fd;
	char *line;
	t_map	*fdf;
	int		row;

	if ((fd = open(fname, O_RDONLY)) < 0)
		exit(ft_error(FILE_ERROR));
	if (!(fdf = malloc(sizeof(t_map))))
		return (NULL);
	fdf->w = 0;
	fdf->h = 0;
	fdf->d = 0;
	if (!(fdf->vec = ft_vecinit(2)))
		return (NULL);
	row = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (fdf->w == 0) 
			fdf->w = ft_fill_row(fdf, line, row); 
		else if (fdf->w != ft_fill_row(fdf, line, row))
			exit(ft_error(CONTENT_ERROR));
		row++;
	}
	fdf->h = row;
	return (fdf);
}
