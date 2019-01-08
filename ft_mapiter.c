/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 14:28:57 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/08 17:01:23 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mapiter(t_map *mp, void (*f)(t_vec4 *vec4, void *data), void *data)
{
	int		i;
	t_vec4	*t;

	if (!mp || !f)
		return ;
	i = mp->w * mp->h;
	t = (t_vec4*)(mp->vec->data);
	while (i--)
		f(&t[i], data);
}

t_map	*ft_mapiter_c(t_map *mp, void (*f)(t_vec4 *, void *), void *data)
{
	t_map *map_r;

	if (!mp || !(map_r = malloc(sizeof(t_map))))
		return (NULL);
	ft_memcpy(map_r, mp, sizeof(t_map));
	if (!(map_r->vec = malloc(sizeof(t_vector))))
	{
		free(map_r);
		return (NULL);
	}
	ft_memcpy(map_r->vec, mp->vec, sizeof(t_vector));
	if (!(map_r->vec->data = malloc(map_r->vec->cap)))
	{
		free(map_r);
		free(map_r->vec);
		return (NULL);
	}
	ft_memcpy(map_r->vec->data, mp->vec->data, mp->vec->len);
	ft_mapiter(map_r, f, data);
	return (map_r);
}
