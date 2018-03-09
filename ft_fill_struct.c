/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:48:51 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/05 15:22:02 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_struct(t_argdata *data)
{
	char *s;

	s = data->form_input;
	while (*s != '\0')
	{
		if ((ft_isdigit(s[0]) == 1) && (s[0] != '0'))
			s = ft_update_int(data, s, 0);
		if (s[0] == '.')
			s = ft_update_int(data, s, 1);
		if (ft_strchr(LENGTH, s[0]))
			s = ft_update_length(s, data);
		if (ft_strchr(CONVERT, s[0]))
			data->conversion = *s;
		if (ft_strchr(FLAGS, s[0]))
			s = ft_update_flag(s, data);
		s++;
	}
}

char	*ft_update_int(t_argdata *data, char *s, int i)
{
	if (i == 0)
		data->size = ft_atoi(s);
	if (i == 1)
	{
		data->precision = ft_update_precision(s);
		while (s[0] == '.')
			s++;
	}
	while (ft_isdigit(s[0]) == 1)
		s++;
	return (s);
}

char	*ft_update_flag(char *s, t_argdata *data)
{
	if (*s == '#')
		data->hash = '#';
	if (*s == ' ')
		data->space = '!';
	if (*s == '-')
		data->minus = '-';
	if (*s == '+')
		data->plus = '+';
	if (*s == '\'')
		data->apostrophe = '\'';
	if (*s == '*')
		data->star = '*';
	if (*s == '0')
		data->zero = '0';
	if (*s == '$')
		data->dollar = '$';
	return (s);
}

char	*ft_update_length(char *s, t_argdata *data)
{
	if ((ft_strchr(LENGTH, s[1])) && ((ft_strchr(CONVERT, s[2]) ||
					(ft_strchr(FLAGS, s[2])))))
	{
		if (s[0] == s[1])
			data->length = ft_toupper(s[0]);
		else
			data->length = s[0];
		return (s + 2);
	}
	if ((ft_strchr(LENGTH, s[0])) && (ft_strchr(CONVERT, s[1])))
	{
		if (s[0] == 'L')
			data->length = 'Z';
		else
			data->length = s[0];
	}
	return (s + 1);
}

int		ft_update_precision(char *s)
{
	while (ft_strchr(s, '.'))
	{
		s = ft_strchr(s, '.');
		s++;
	}
	if (ft_isdigit(s[0]) == 1)
	{
		return (ft_atoi(s));
	}
	else
		return (0);
}
