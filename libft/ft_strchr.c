/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 17:06:12 by ekulyyev          #+#    #+#             */
/*   Updated: 2017/09/27 20:01:05 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *chr;

	chr = (char *)s;
	while (*chr)
	{
		if (*chr == (char)c)
			return (chr);
		chr++;
	}
	if (*chr == (char)c)
		return (chr);
	return (NULL);
}
