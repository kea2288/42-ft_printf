/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_floats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:26:00 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/09 11:09:39 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_round_dec_string(char *s, int len)
{
	if (s[len] != '.' && len >= 0)
	{
		s[len]++;
		if (s[len] > 57)
		{
			s[len] = 48;
			s = ft_round_dec_string(s, len - 1);
		}
	}
	if (len < 0)
		s = ft_append("1", s, 0);
	return (s);
}

char		*ft_get_rounded_str(long double x, char *s)
{
	x = ft_round_fraction(x);
	if (x >= 10)
		s = ft_append(ft_round_dec_string(s, ft_strlen(s) - 1), "0", 0);
	else
		s = ft_append(s, ft_uitoa((intmax_t)x, 10), 3);
	return (s);
}

long double	ft_round_fraction(long double f)
{
	long double up;
	long double down;

	up = ft_round_up(f);
	down = ft_round_down(f);
	if (f - down == 0.5 && !((uintmax_t)down ^ 1))
		return (down);
	else if (up - f == 0.5)
		return (up);
	if (f - down >= 0.5)
		return (up);
	else
		return (down);
}

long double	ft_round_down(long double f)
{
	long double x;

	x = (uintmax_t)f;
	if (f >= x)
		return (x);
	return (x - 1);
}

long double	ft_round_up(long double f)
{
	long double x;

	x = (uintmax_t)f;
	if (f <= x)
		return (x);
	return (x + 1);
}
