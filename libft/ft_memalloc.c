/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 12:53:31 by ekulyyev          #+#    #+#             */
/*   Updated: 2017/09/27 12:56:59 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*addr;
	char	*p;

	addr = (char *)ft_malloc(size);
	if (addr == NULL)
		return (NULL);
	p = addr;
	while (size--)
		*p++ = 0;
	return (addr);
}
