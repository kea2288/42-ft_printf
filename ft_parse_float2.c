/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_floats2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:02:41 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/09 10:47:58 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_check_normalize(long double x, int p)
{
	if ((intmax_t)x < 9)
		return (0);
	x = (x - (intmax_t)x) * 10;
	p--;
	while ((intmax_t)x == 9)
	{
		x = (x - (intmax_t)x) * 10;
		p--;
	}
	if ((intmax_t)x < 8)
		p++;
	if (p <= -1)
		return (1);
	else
		return (0);
}

long double	ft_normalize_float(long double x, int exp)
{
	if (exp < 0)
		while (exp++ < 0)
			x *= 10;
	else if (exp > 0)
		while (exp-- > 0)
			x /= 10;
	return (x);
}

int			ft_find_exp_value(long double x)
{
	int exp;

	exp = 0;
	while (x > 0 && x < 1)
	{
		x *= 10;
		exp--;
	}
	while (x > 10)
	{
		x = x / 10;
		exp++;
	}
	return (exp);
}

int			ft_check_nine(long double x, int p)
{
	while (p >= 0 && (intmax_t)x >= 9)
	{
		x = (x - (intmax_t)x) * 10;
		p--;
	}
	if (p <= 0)
		return (1);
	return (0);
}

char		*ft_get_whole_part(long double f, char *s, t_argdata *data)
{
	int i;

	i = 0;
	while (f > 10)
	{
		f /= 10;
		i--;
	}
	while (i <= 0)
	{
		s = ft_append(s, ft_uitoa((intmax_t)f, 10), 3);
		f = (f - (intmax_t)f) * 10;
		i++;
	}
	if ((int)(f / 10) < (int)ft_round_fraction(f / 10) && data->precision == 0)
		return (ft_round_dec_string(s, ft_strlen(s) - 1));
	if (ft_round_fraction(f) >= 9 && ft_check_nine(f, data->precision))
		return (ft_round_dec_string(s, ft_strlen(s) - 1));
	return (s);
}
