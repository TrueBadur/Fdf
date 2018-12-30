/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 04:00:04 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/30 04:24:00 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_error(int er)
{
	if (er == CONTENT_ERROR)
		ft_putstr_fd(CONTENT_ERROR_MSG, 2);
	else if (er == FILE_ERROR)
		ft_putstr_fd(FILE_ERROR_MSG, 2);
	return (er);
}
