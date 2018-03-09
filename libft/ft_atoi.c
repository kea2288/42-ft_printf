/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 11:23:23 by ekulyyev          #+#    #+#             */
/*   Updated: 2017/09/27 20:29:00 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					i;
	int					is_neg;
	unsigned long long	number;

	i = 0;
	is_neg = 1;
	number = 0;
	while (FT_WS(*str) || FT_BL(*str))
		str++;
	is_neg = (str[i] == '\x2d') ? -1 : 1;
	if ((str[i] == '\x2d') || (str[i] == '\x2b'))
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			return (number * is_neg);
		number = number * 10 + str[i] - 48;
		i++;
	}
	if (i > 19 || number > 9223372036854775807ULL)
		return (is_neg == 1 ? -1 : 0);
	return (number * is_neg);
}
