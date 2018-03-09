/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:49:24 by ekulyyev          #+#    #+#             */
/*   Updated: 2017/09/25 15:41:51 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t size;
	size_t i;

	if (!s || !(*f))
		return ;
	size = (size_t)ft_strlen(s);
	i = -1;
	while (++i < size)
		(*f)(s + i);
}
