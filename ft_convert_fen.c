/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_fen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:24:13 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/05 14:54:05 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cv_f(va_list *argval, t_argdata *data)
{
	long double f;
	char		*s;

	if (data->length == 'Z')
		f = va_arg(*argval, long double);
	else
		f = va_arg(*argval, double);
	s = ft_check_infinity(f);
	if (s)
		return (s);
	if (data->precision == -1)
		data->precision = 6;
	s = ft_parse_float(f, data);
	return (s);
}

char	*ft_cv_bf(va_list *argval, t_argdata *data)
{
	return (ft_cv_f(argval, data));
}

char	*ft_cv_e(va_list *argval, t_argdata *data)
{
	long double f;
	char		*s;

	if (data->length == 'Z')
		f = va_arg(*argval, long double);
	else
		f = va_arg(*argval, double);
	s = ft_check_infinity(f);
	if (s)
		return (s);
	if (data->precision == -1)
		data->precision = 6;
	s = ft_parse_float(f, data);
	return (s);
}

char	*ft_cv_be(va_list *argval, t_argdata *data)
{
	return (ft_cv_e(argval, data));
}

char	*ft_cv_n(va_list *argval, t_argdata *data)
{
	int *f;

	f = va_arg(*argval, int *);
	if (data->length == 'H')
		*(char *)f = (char)data->argnums;
	else if (data->length == 'h')
		*(short *)f = (short)data->argnums;
	else if (data->length == 'l' || data->length == 'z')
		*(long *)f = (long)data->argnums;
	else if (data->length == 'L')
		*(long long *)f = (long long)data->argnums;
	else if (data->length == 'j')
		*(intmax_t *)f = (intmax_t)data->argnums;
	else
		*(int *)f = (int)data->argnums;
	return (ft_strdup(""));
}
