/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:28:22 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/09 10:53:16 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		argval;
	int			argnums;

	va_start(argval, format);
	argnums = ft_vprintf(format, argval);
	va_end(argval);
	return (argnums);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list		argval;
	int			argnums;

	va_start(argval, format);
	argnums = ft_vdprintf(fd, format, argval);
	va_end(argval);
	return (argnums);
}

int		ft_vprintf(const char *format, va_list argval)
{
	return (ft_vdprintf(1, format, argval));
}

int		ft_vdprintf(int fd, const char *format, va_list argval)
{
	char	*s;
	int		argnums;

	argnums = ft_vasprintf(&s, format, argval);
	write(fd, s, argnums);
	free(s);
	return (argnums);
}

int		ft_vasprintf(char **s, char const *format, va_list argval)
{
	int	argnums;

	argnums = ft_create_func_arr(ft_strdup(format), argval, s);
	return (argnums);
}
