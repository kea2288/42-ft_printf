/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatparsing_additional.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 21:06:39 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/05 15:36:43 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_argdata	*ft_get_argdata(t_argdata *data, char *format, int an, int argnums)
{
	data = (t_argdata *)malloc(sizeof(t_argdata));
	*data = (t_argdata)NRG;
	data->arg_num = an;
	data->argnums = argnums;
	ft_get_format(format + 1, data);
	return (data);
}

char		*ft_get_format(char *format, t_argdata *data)
{
	int i;

	i = 0;
	while (format[i] != '\0' && format[i] != '%')
	{
		if (ft_isascii(format[i]) && !(ft_strchr(RESERVED, format[i])))
			break ;
		if ((ft_isalpha(format[i]) == 1) && (ft_strchr(CONVERT, format[i])))
			break ;
		i++;
	}
	if (format[i] != '\0')
		data->form_input = ft_strsub(format, 0, i + 1);
	else if (format[i] == '\0')
		data->form_input = ft_strsub(format, 0, i);
	ft_fill_struct(data);
	if (format[i] == '\0')
		return (format + i);
	return (format + i + 1);
}

void		ft_apply_star(va_list *argval, t_argdata *data)
{
	int		i;
	char	*s;

	s = data->form_input;
	while (*s)
	{
		if (s[0] == '.' && s[1] == '*')
		{
			i = ft_get_starval(argval, data);
			if (i > data->size && data->minus)
				i = data->size;
			s += 2;
			if (data->precision == -1 || data->precision == 0)
				data->precision = i;
		}
		if (s[0] == '*')
		{
			i = ft_get_starval(argval, data);
			if (data->size == -1 || ft_nonum_after(s) == 1)
				data->size = i;
		}
		s++;
	}
}

int			ft_get_starval(va_list *argval, t_argdata *data)
{
	int i;

	i = va_arg(*argval, int);
	if (i < 0)
	{
		i = -i;
		data->minus = '-';
	}
	return (i);
}

void		ft_nullcharprint(char *str, t_argdata *data, char **s)
{
	int i;

	i = 0;
	str = ft_strnew(1);
	if (data->minus)
		(*s)[(data->argnums)++] = str[i];
	str = ft_apply_modifiers(str, data);
	if (ft_strlen(str) != 0)
		str[ft_strlen(str) - 1] = '\0';
	while (str[i])
		(*s)[(data->argnums)++] = str[i++];
	if (!data->minus)
		(*s)[(data->argnums)++] = str[i];
}
