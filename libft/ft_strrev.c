/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:17:18 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/09 11:18:42 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	s = ft_strdup(str);
	len = ft_strlen(str) - 1;
	while (len >= 0)
		str[i++] = s[len--];
	ft_strdel(&s);
	return (str);
}
