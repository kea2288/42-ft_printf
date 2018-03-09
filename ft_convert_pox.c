/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:49:35 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/05 15:20:46 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cv_p(va_list *argval, t_argdata *data)
{
	void *ptr;
	char *s;

	ptr = va_arg(*argval, void *);
	s = ft_uitoa((uintmax_t)ptr, 16);
	data->hash = '#';
	return (s);
}

char	*ft_cv_o(va_list *argval, t_argdata *data)
{
	uintmax_t	uimax;
	char		*s;

	uimax = va_arg(*argval, uintmax_t);
	s = ft_apply_length_uox(data, uimax, 8);
	if ((uimax == 0) && (data->hash == '#') && (data->precision == 0))
		data->precision++;
	return (s);
}

char	*ft_cv_lo(va_list *argval, t_argdata *data)
{
	uintmax_t	uimax;
	char		*s;

	uimax = va_arg(*argval, uintmax_t);
	data->length = 'l';
	s = ft_apply_length_uox(data, uimax, 8);
	if ((uimax == 0) && (data->hash == '#') && (data->precision == 0))
		data->precision++;
	return (s);
}

char	*ft_cv_x(va_list *argval, t_argdata *data)
{
	uintmax_t	uimax;
	char		*s;

	uimax = va_arg(*argval, uintmax_t);
	s = ft_apply_length_uox(data, uimax, 16);
	return (s);
}

char	*ft_cv_lx(va_list *argval, t_argdata *data)
{
	uintmax_t	uimax;
	char		*s;

	uimax = va_arg(*argval, uintmax_t);
	s = ft_apply_length_uox(data, uimax, 16);
	return (s);
}
