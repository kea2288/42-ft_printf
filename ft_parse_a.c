/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:34:09 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/09 10:41:48 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_parse_a(long double d, t_argdata *data, char *s)
{
	long double f;
	int			base;
	int			exp;

	exp = 0;
	if (data->length == 'Z')
		base = 16;
	else
		base = 2;
	s = ft_append(s, "0x", 1);
	f = ft_get_a_exp(d, &exp, base);
	s = ft_append(s, ft_uitoa((intmax_t)f, 16), 3);
	if (data->precision != 0 && (f - (intmax_t)f) != 0.0)
		s = ft_append(s, ".", 1);
	s = ft_get_fract_a(f, s, data);
	s = ft_append(s, "p", 1);
	if (exp < 0)
		s = ft_append(s, ft_checkneg(exp, 10), 1);
	else if (exp >= 0)
	{
		s = ft_append(s, "+", 1);
		s = ft_append(s, ft_uitoa(exp, 10), 3);
	}
	return (s);
}

long double	ft_get_a_exp(long double f, int *exp, int base)
{
	while (f >= base)
	{
		f /= 2;
		(*exp)++;
	}
	while ((f * 2) > 0 && (f * 2) < base)
	{
		f *= 2;
		(*exp)--;
	}
	return (f);
}

char		*ft_get_fract_a(long double f, char *s, t_argdata *data)
{
	int i;

	i = ft_strlen(s);
	while (f > 0)
	{
		f = (f - (intmax_t)f) * 16;
		if (f != 0)
			s = ft_append(s, ft_uitoa((intmax_t)f, 16), 3);
	}
	if (data->precision == -1)
		data->precision = ft_strlen(s) - i;
	else if (data->precision > ((int)ft_strlen(s) - i))
		while (data->precision > ((int)ft_strlen(s) - i))
			s = ft_append(s, "0", 1);
	else if (data->precision < (int)ft_strlen(s))
		s = ft_round_hexdec(s, data->precision + i, ft_strlen(s));
	return (s);
}

char		*ft_round_hexdec(char *s, int i, int e)
{
	if (e == i)
		return (s);
	while (e > i)
		if (s[e--] >= 56)
			ft_iter_hexdec(s + e);
	if (s[i] > 56)
		ft_iter_hexdec(s + i - 1);
	s[i] = '\0';
	i--;
	while (s[i] > 102 || s[i] == '.')
	{
		if (s[i] == '.')
			i--;
		else if (s[i] > 102)
		{
			s[i] = 48;
			if (s[i - 1] == '.')
				i--;
			ft_iter_hexdec(s + i - 1);
		}
		i--;
	}
	return (s);
}

void		ft_iter_hexdec(char *s)
{
	s[0]++;
	if (s[0] == 58)
		s[0] += 39;
}
