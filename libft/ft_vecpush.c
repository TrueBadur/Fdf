/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecshrink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:58:28 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/29 23:17:47 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vecpush(t_vector *vec, void *data, size_t s)
{
	void *tmp;
	int		it;

	if (!vec)
		return (t_vector*)(NULL);
	if (!data || !s)
		return (vec);
	it = vec->cap;
	while (s > vec->cap - vec->len)
		it *= 2;
	if (it > vec->cap)
		vec = ft_vecgrow(vec, it);
	ft_memcpy(vec->data + vec->len, data, s);
	vec->len += s;
	vec->cap = it;
	return (vec);
}
