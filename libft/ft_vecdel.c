/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:32:17 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/30 01:11:38 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vecdel(t_vector **vect, void (*f)(void *))
{
	if (!vect || !*vect)
		return ;
	if (!f)
		free((*vect)->data);
	else
		f((*vect)->data);
	free(*vect);
	*vect = NULL;
}
