/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatparsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 12:39:33 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/09 16:34:54 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_create_func_arr(char *format, va_list argval, char **s)
{
	int			argnums;
	const void	*functions[] = {&ft_cv_c, &ft_cv_wc, &ft_cv_s, &ft_cv_ws,
								&ft_cv_d, &ft_cv_ld, &ft_cv_i, &ft_cv_o,
								&ft_cv_lo, &ft_cv_u, &ft_cv_lu, &ft_cv_x,
								&ft_cv_lx, &ft_cv_p, &ft_cv_f, &ft_cv_bf,
								&ft_cv_a, &ft_cv_ba, &ft_cv_e, &ft_cv_be,
								&ft_cv_g, &ft_cv_bg, &ft_cv_n};

	argnums = ft_formatparser(format, argval, s, functions);
	ft_strdel(&format);
	return (argnums);
}

int		ft_formatparser(char *format, va_list argval, char **s,
		const void *functions[])
{
	int					i;
	int					argnums;
	static t_argdata	*data;

	i = 0;
	argnums = 0;
	*s = ft_strnew(1000);
	while (*format != '\0')
	{
		if (*format != '%' && *format != '\0')
			format += ft_get_prefix(format, s, &argnums);
		else if (*format == '%' && format[1] != '\0')
		{
			data = ft_get_argdata(data, format, i++, argnums);
			format += ft_argparser(data, (va_list *)(argval), s, functions);
			argnums = data->argnums;
			ft_free_struct(data);
		}
		else if (*format == '%' && format[1] == '\0')
			format++;
	}
	return (argnums);
}

int		ft_get_prefix(char *format, char **s, int *argnums)
{
	int	i;

	i = 0;
	while (format[i] != '%' && format[i] != '\0')
	{
		if (format[i] == '{')
		{
			i += ft_check_color(format + i, s, argnums);
			if (format[i] == '\0')
				break ;
		}
		(*s)[(*argnums)++] = format[i];
		i++;
	}
	return (i);
}

int		ft_argparser(t_argdata *data, va_list *argval, char **s,
		const void *functions[])
{
	int			i;
	const char	*conv = "cCsSdDioOuUxXpfFaAeEgGn";

	i = ft_strchr(conv, data->conversion) - conv;
	if (data->star)
		ft_apply_star(argval, data);
	if (data->form_input[ft_strlen(data->form_input) - 1] == 32)
		data->conversion = '\0';
	if (data->conversion)
		ft_apply_func(argval, data, functions[i], s);
	return (ft_strlen(data->form_input) + 1);
}

void	ft_apply_func(va_list *argval, t_argdata *data,
		char *func(va_list *, t_argdata *),
		char **s)
{
	int		i;
	char	*str;

	i = 0;
	str = (*func)(argval, data);
	if (str)
	{
		str = ft_apply_modifiers(str, data);
		while (str[i])
			(*s)[(data->argnums)++] = str[i++];
		ft_bzero(str, ft_strlen(str));
		ft_strdel(&str);
	}
	else
		ft_nullcharprint(str, data, s);
}
