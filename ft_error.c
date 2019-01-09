/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 04:00:04 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/09 11:30:17 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_error(int er)
{
	if (er / 10 == CONT_ERR)
	{
		ft_putstr_fd(CONT_ERR_MSG, 2);
		if (er == CONT_ERR_CS)
			ft_putstr_fd(CONT_ERR_CS_MSG, 2);
		else if (er == CONT_ERR_CE)
			ft_putstr_fd(CONT_ERR_CE_MSG, 2);
		else if (er == CONT_ERR_NE)
			ft_putstr_fd(CONT_ERR_NE_MSG, 2);
		else if (er == CONT_ERR_NO)
			ft_putstr_fd(CONT_ERR_NO_MSG, 2);
	}
	else if (er == FILE_ERROR)
		ft_putstr_fd(FILE_ERROR_MSG, 2);
	else if (er == ARG_ERROR)
	{
		ft_putstr_fd(ARG_ERROR_MSG, 2);
		ft_putstr_fd(USAGE_MSG, 2);
	}
	return (er);
}
