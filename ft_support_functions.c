/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:10:12 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/09 11:15:03 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_append(char *s1, char *s2, int i)
{
	char	*res;

	if (s1 != NULL && s2 != NULL)
	{
		if (!(res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		res = ft_strcat(ft_strcpy(res, s1), s2);
		if (i == 1)
			ft_strdel(&s1);
		if (i == 2)
			ft_strdel(&s2);
		if (i == 3)
		{
			ft_strdel(&s1);
			ft_strdel(&s2);
		}
		return (res);
	}
	return (0);
}

char	*ft_uitoa(uintmax_t t, int b)
{
	int		i;
	char	*base;
	char	*res;

	i = ft_intlen(t / b, b);
	base = "0123456789abcdef";
	res = (char *)malloc(sizeof(char) * i + 1);
	res[i] = '\0';
	i--;
	while (t >= (uintmax_t)b)
	{
		res[i] = base[t % b];
		t /= b;
		i--;
	}
	res[i] = base[t];
	return (res);
}

char	*ft_checkneg(intmax_t t, int b)
{
	intmax_t	num;
	char		*s;

	if (t < 0)
	{
		num = -t;
		s = ft_append("-", ft_uitoa(num, b), 2);
	}
	else
		s = ft_uitoa(t, b);
	return (s);
}

int		ft_nonum_after(char *s)
{
	while (*s)
	{
		if (ft_isdigit(s[0]) == 1)
			return (0);
		else if (s[0] == '.')
		{
			s++;
			while (ft_isdigit(s[0]) && *s)
				s++;
		}
		s++;
	}
	return (1);
}

char	*ft_cut_zero(char *s, int len, t_argdata *data)
{
	if (data->precision == 0)
		return (s);
	while (s[len] == 48)
		s[len--] = '\0';
	if (s[len] == '.')
		s[len] = '\0';
	return (s);
}
