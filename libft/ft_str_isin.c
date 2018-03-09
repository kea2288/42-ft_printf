/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:31:22 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/09 11:26:22 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isin(char *big, char *small)
{
	if (big && small)
	{
		while (*big != *small)
			big++;
		while (*big == *small)
		{
			big++;
			small++;
			if (*small == '\0')
				return (1);
		}
	}
	return (0);
}
