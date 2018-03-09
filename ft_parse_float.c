/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_floats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:45:28 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/09 10:47:04 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_infinity(long double f)
{
	if (!(f == f))
		return (ft_strdup("nan"));
	if (f == -1.0 / 0.0)
		return (ft_strdup("-inf"));
	if (f == 1.0 / 0.0)
		return (ft_strdup("inf"));
	return (NULL);
}

char	*ft_parse_float(long double f, t_argdata *data)
{
	int		exp;
	int		neg;
	char	*s;

	s = ft_strnew(1);
	neg = 0;
	if (f < 0.0)
	{
		neg = 1;
		f = -f;
	}
	exp = ft_find_exp_value(f);
	if (data->conversion == 'f' || data->conversion == 'F')
		s = ft_ftoa(f, s, data);
	else if (data->conversion == 'e' || data->conversion == 'E')
		s = ft_exponent(f, s, data, exp);
	else if (data->conversion == 'g' || data->conversion == 'G')
		s = g_cv_switcher(f, data, s, exp);
	if (neg == 1)
		s = ft_append("-", s, 2);
	return (s);
}

char	*ft_ftoa(long double f, char *s, t_argdata *data)
{
	int			i;
	long double x;

	i = 0;
	s = ft_get_whole_part(f, s, data);
	if (data->precision == 0)
		return (s);
	if (data->precision != 0 || data->hash == '#')
		s = ft_append(s, ".", 1);
	x = (f - (intmax_t)f) * 10;
	while (x != 0 || i < data->precision)
	{
		if (i + 1 == data->precision)
			return (ft_get_rounded_str(x, s));
		s = ft_append(s, ft_uitoa((intmax_t)x, 10), 3);
		x = x - (intmax_t)x;
		x *= 10;
		i++;
	}
	return (s);
}

char	*ft_exponent(long double f, char *s, t_argdata *data, int exp)
{
	long double x;

	x = ft_normalize_float(f, exp);
	if (ft_check_normalize(x, data->precision) || (intmax_t)x == 10)
	{
		x /= 10;
		exp++;
	}
	s = ft_ftoa(x, s, data);
	if (data->conversion == 'g' || data->conversion == 'G')
		s = ft_cut_zero(s, ft_strlen(s) - 1, data);
	s = ft_append(s, "e", 1);
	if (exp < 0)
	{
		s = ft_append(s, "-", 1);
		exp = -exp;
	}
	else
		s = ft_append(s, "+", 1);
	if (exp < 10)
		s = ft_append(s, "0", 1);
	s = ft_append(s, ft_uitoa(exp, 10), 2);
	return (s);
}

char	*g_cv_switcher(long double f, t_argdata *data, char *s, int exp)
{
	if (exp < -4 || exp >= data->precision)
	{
		data->precision--;
		s = ft_exponent(f, s, data, exp);
	}
	else
	{
		data->precision = data->precision - exp - 1;
		s = ft_ftoa(f, s, data);
	}
	return (s);
}
