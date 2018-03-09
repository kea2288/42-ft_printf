/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:53:16 by ekulyyev          #+#    #+#             */
/*   Updated: 2017/09/25 15:43:07 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t size;
	size_t i;

	if (!s || !(*f))
		return ;
	size = (size_t)ft_strlen(s);
	i = -1;
	while (++i < size)
		(*f)(i, s + i);
}
