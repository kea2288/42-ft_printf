/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_diu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:28:52 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/05 14:52:05 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cv_d(va_list *argval, t_argdata *data)
{
	intmax_t	imax;
	char		*s;

	imax = va_arg(*argval, intmax_t);
	s = ft_apply_length_di(imax, 10, data);
	return (s);
}

char	*ft_cv_ld(va_list *argval, t_argdata *data)
{
	intmax_t	imax;
	char		*s;

	imax = va_arg(*argval, intmax_t);
	data->length = 'l';
	s = ft_apply_length_di(imax, 10, data);
	return (s);
}

char	*ft_cv_i(va_list *argval, t_argdata *data)
{
	intmax_t	imax;
	char		*s;

	imax = va_arg(*argval, intmax_t);
	s = ft_apply_length_di(imax, 10, data);
	return (s);
}

char	*ft_cv_u(va_list *argval, t_argdata *data)
{
	uintmax_t	uimax;
	char		*s;

	uimax = va_arg(*argval, uintmax_t);
	s = ft_apply_length_uox(data, uimax, 10);
	return (s);
}

char	*ft_cv_lu(va_list *argval, t_argdata *data)
{
	uintmax_t	uimax;
	char		*s;

	uimax = va_arg(*argval, uintmax_t);
	data->length = 'l';
	s = ft_apply_length_uox(data, uimax, 10);
	return (s);
}
