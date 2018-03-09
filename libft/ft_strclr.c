/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:31:59 by ekulyyev          #+#    #+#             */
/*   Updated: 2017/09/22 19:59:04 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t size;
	size_t i;

	if (!s)
		return ;
	size = ft_strlen(s);
	i = -1;
	while (++i < size)
		s[i] = '\0';
}
