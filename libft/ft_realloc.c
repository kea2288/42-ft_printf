/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:06:38 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/09 11:27:56 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*nptr;
	size_t	psize;

	psize = 0;
	while (((char *)ptr)[psize])
		psize++;
	if (ptr != NULL)
	{
		nptr = malloc(size);
		if (size < psize)
			psize = size;
		nptr = ft_memcpy(nptr, ptr, psize);
		free(ptr);
		return (nptr);
	}
	nptr = malloc(size);
	return (nptr);
}
