/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:34:01 by ekulyyev          #+#    #+#             */
/*   Updated: 2017/09/22 20:13:44 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	if (!s)
		return (NULL);
	out = ft_strnew(len);
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = s[start];
		start++;
		i++;
	}
	out[i] = '\0';
	return (out);
}
