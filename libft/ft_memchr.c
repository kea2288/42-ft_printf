/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:39:44 by ekulyyev          #+#    #+#             */
/*   Updated: 2017/09/19 16:50:43 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*a;
	size_t	i;

	i = -1;
	a = (unsigned char *)s;
	while (++i < n)
	{
		if (*(unsigned char *)a == (unsigned char)c)
			return (a);
		a++;
	}
	return (NULL);
}
