/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 22:05:00 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/09 10:50:36 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_struct(t_argdata *data)
{
	ft_strdel(&(data->form_input));
	ft_memdel((void **)&data);
}

char	**ft_match_color(void)
{
	char **colors;

	colors = (char **)malloc(sizeof(char *) * 17);
	colors[0] = ft_strdup("{red}");
	colors[1] = ft_strdup("{green}");
	colors[2] = ft_strdup("{yellow}");
	colors[3] = ft_strdup("{blue}");
	colors[4] = ft_strdup("{magenta}");
	colors[5] = ft_strdup("{cyan}");
	colors[6] = ft_strdup("{white}");
	colors[7] = ft_strdup("{black}");
	colors[8] = ft_strdup("{red|b}");
	colors[9] = ft_strdup("{green|b}");
	colors[10] = ft_strdup("{yellow|b}");
	colors[11] = ft_strdup("{blue|b}");
	colors[12] = ft_strdup("{magenta|b}");
	colors[13] = ft_strdup("{cyan|b}");
	colors[14] = ft_strdup("{white|b}");
	colors[15] = ft_strdup("{black|b}");
	colors[16] = ft_strdup("{eoc}");
	colors[17] = NULL;
	return (colors);
}

char	**ft_get_color(void)
{
	char **colval;

	colval = (char **)malloc(sizeof(char *) * 17);
	colval[0] = ft_strdup("\x1b[31m");
	colval[1] = ft_strdup("\x1b[32m");
	colval[2] = ft_strdup("\x1b[33m");
	colval[3] = ft_strdup("\x1b[34m");
	colval[4] = ft_strdup("\x1b[35m");
	colval[5] = ft_strdup("\x1b[36m");
	colval[6] = ft_strdup("\x1b[37m");
	colval[7] = ft_strdup("\x1b[30m");
	colval[8] = ft_strdup("\x1b[41m");
	colval[9] = ft_strdup("\x1b[42m");
	colval[10] = ft_strdup("\x1b[43m");
	colval[11] = ft_strdup("\x1b[44m");
	colval[12] = ft_strdup("\x1b[45m");
	colval[13] = ft_strdup("\x1b[46m");
	colval[14] = ft_strdup("\x1b[47m");
	colval[15] = ft_strdup("\x1b[40m");
	colval[16] = ft_strdup("\x1b[0m");
	colval[17] = NULL;
	return (colval);
}

int		ft_check_color(char *format, char **s, int *argnums)
{
	int		i;
	int		e;
	char	**colors;
	char	**colval;

	i = 0;
	e = 0;
	colors = ft_match_color();
	while (colors[i])
	{
		if (ft_str_isin(format, colors[i]))
		{
			colval = ft_get_color();
			while (colval[i][e])
				(*s)[(*argnums)++] = colval[i][e++];
			ft_free_2d(colval);
			free(colval);
			return (ft_strlen(colors[i]));
		}
		i++;
	}
	ft_free_2d(colors);
	free(colors);
	return (0);
}
