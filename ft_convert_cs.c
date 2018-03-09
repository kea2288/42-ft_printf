/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:48:57 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/05 12:54:51 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cv_c(va_list *argval, t_argdata *data)
{
	int		i;
	char	*s;

	i = ft_strlen(data->form_input);
	s = ft_strnew(1);
	if (ft_strcmp(s, data->form_input) == 0)
		return (s);
	if (data->length == 'l')
	{
		data->conversion = 'C';
		return (ft_cv_wc(argval, data));
	}
	if (ft_strchr("c", (data->form_input[i - 1])) != 0)
	{
		*s = (char)va_arg(*argval, int);
		if (*s == 0 || !(*s))
			return (NULL);
	}
	else
		*s = data->form_input[i - 1];
	return (s);
}

char	*ft_cv_wc(va_list *argval, t_argdata *data)
{
	wchar_t v;
	char	*s;

	if (data->conversion == 'C')
	{
		s = ft_strnew(1);
		s[0] = (char)va_arg(*argval, int);
		return (s);
	}
	v = va_arg(*argval, wchar_t);
	if (v == 0)
		return (NULL);
	s = ft_convert_wchar(v);
	return (s);
}

char	*ft_cv_s(va_list *argval, t_argdata *data)
{
	char *s;

	s = NULL;
	if (data->length == 'l')
		return (ft_cv_ws(argval, data));
	s = va_arg(*argval, char *);
	if (s == NULL)
		s = "(null)";
	return (ft_strdup(s));
}

char	*ft_cv_ws(va_list *argval, t_argdata *data)
{
	int			i;
	int			e;
	wchar_t		*t;
	char		*r;

	i = 0;
	r = ft_strnew(0);
	t = va_arg(*argval, wchar_t *);
	if (t == NULL)
		return (ft_strdup("(null)"));
	while (t[i])
	{
		r = ft_append(r, ft_convert_wchar(t[i]), 3);
		if (((int)ft_strlen(r) > data->precision) && (data->precision >= 1))
		{
			data->precision -= (data->precision - e);
			return (r);
		}
		e = ft_strlen(r);
		i++;
	}
	return (r);
}

char	*ft_convert_wchar(wchar_t v)
{
	unsigned char *u;

	u = (unsigned char *)ft_strnew(4);
	if (v <= 127)
		u[0] = v;
	else if (v <= 2047)
	{
		u[0] = ((v & 1984) >> 6 | 192);
		u[0] = ((v & 63) | 128);
	}
	else if (v <= 65535)
	{
		u[0] = ((v >> 12) | 224);
		u[1] = ((v & 4032) >> 6 | 128);
		u[2] = ((v & 63) | 128);
	}
	else if (v <= 2097151)
	{
		u[0] = ((v >> 18) | 240);
		u[1] = ((v & 258048) >> 12 | 128);
		u[2] = ((v & 4032) >> 6 | 128);
		u[3] = ((v & 63) | 128);
	}
	return ((char *)u);
}
