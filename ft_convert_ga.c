/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ga.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:09:54 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/05 15:18:30 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cv_g(va_list *argval, t_argdata *data)
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
	if (data->precision == 0)
		data->precision = 1;
	s = ft_parse_float(f, data);
	s = ft_cut_zero(s, ft_strlen(s) - 1, data);
	return (s);
}

char	*ft_cv_bg(va_list *argval, t_argdata *data)
{
	return (ft_cv_g(argval, data));
}

char	*ft_cv_a(va_list *argval, t_argdata *data)
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
	s = ft_strnew(1);
	if (f < 0)
	{
		s[0] = '-';
		f = -f;
	}
	s = ft_parse_a(f, data, s);
	return (s);
}

char	*ft_cv_ba(va_list *argval, t_argdata *data)
{
	return (ft_cv_a(argval, data));
}
