/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 11:55:15 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/09 11:12:13 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sprintf(char *s, const char *format, ...)
{
	va_list	argval;
	int		argnum;

	va_start(argval, format);
	argnum = ft_vsprintf(s, format, argval);
	va_end(argval);
	return (argnum);
}

int		ft_vsprintf(char *s, const char *format, va_list argval)
{
	int		argnum;
	char	*str;

	argnum = ft_vasprintf(&str, format, argval);
	ft_strcpy(s, str);
	free(str);
	return (argnum);
}

int		ft_snprintf(char *s, size_t size, const char *format, ...)
{
	int		argnum;
	va_list	argval;

	va_start(argval, format);
	argnum = ft_vsnprintf(s, size, format, argval);
	va_end(argval);
	return (argnum);
}

int		ft_vsnprintf(char *s, size_t size, const char *format, va_list argval)
{
	int		argnum;
	char	*str;

	argnum = ft_vasprintf(&str, format, argval);
	ft_strncpy(s, str, size);
	free(str);
	return (argnum);
}

int		ft_asprintf(char **ret, const char *format, ...)
{
	int		argnum;
	va_list	argval;

	va_start(argval, format);
	argnum = ft_vasprintf(ret, format, argval);
	va_end(argval);
	return (argnum);
}
