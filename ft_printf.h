/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 22:04:35 by ekulyyev          #+#    #+#             */
/*   Updated: 2018/03/09 11:07:28 by ekulyyev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft/libft.h"

# define RESERVED "# 0-+'*$hljtzLcCsSdDioOuUxXpfFaAeEgGn1234567890."
# define FLAGS "# 0-+'*$"
# define LENGTH "hljtzL"
# define CONVERT "cCsSdDioOuUxXpfFaAeEgGn"
# define ESC_SEQ "\n\t\r\v\b\f\a"
# define NRG {0,"\0",'\0','\0','\0','\0','\0','\0','\0','\0','c','\0',-1,-1,0}

typedef struct	s_argdata
{
	int		arg_num;
	char	*form_input;
	char	hash;
	char	space;
	char	zero;
	char	plus;
	char	minus;
	char	apostrophe;
	char	star;
	char	dollar;
	char	conversion;
	char	length;
	int		size;
	int		precision;
	int		argnums;
}				t_argdata;

/*
** supported function management
*/

int				ft_printf(const char *format, ...);
int				ft_vprintf(char const *format, va_list argval);
int				ft_dprintf(int fd, char const *format, ...);
int				ft_vdprintf(int fd, char const *format, va_list argval);
int				ft_sprintf(char *s, char const *format, ...);
int				ft_snprintf(char *s, size_t size, char const *format, ...);
int				ft_asprintf(char **ret, char const *format, ...);
int				ft_vsprintf(char *s, char const *format, va_list argval);
int				ft_vsnprintf(char *s, size_t size,
							char const *format, va_list argval);
int				ft_vasprintf(char **s, char const *format, va_list argval);

/*
** ft_formatparsing.c
*/

int				ft_create_func_arr(char *format, va_list argval, char **s);
int				ft_formatparser(char *format, va_list argval,
								char **s, void const *functions[]);
int				ft_get_prefix(char *format, char **s, int *argnums);
int				ft_argparser(t_argdata *data, va_list *ap,
							char **s, void const *functions[]);
void			ft_apply_func(va_list *argval, t_argdata *data,
							char *func(va_list *, t_argdata *), char **s);

/*
** ft_parse_colors.c
*/

void			ft_free_struct(t_argdata *data);
char			**ft_match_color(void);
char			**ft_get_color(void);
int				ft_check_color(char *format, char **s, int *argnums);

/*
** ft_formatparsing_additional.c
*/

t_argdata		*ft_get_argdata(t_argdata *data,
								char *format, int an, int argnums);
char			*ft_get_format(char *format, t_argdata *data);
void			ft_apply_star(va_list *argval, t_argdata *data);
int				ft_get_starval(va_list *argval, t_argdata *data);
void			ft_nullcharprint(char *str, t_argdata *data, char **s);

/*
** ft_modifyers_management.c
*/

char			*ft_apply_modifiers(char *s, t_argdata *data);
char			*ft_apply_precision(char *s, t_argdata *data);
char			*ft_apply_size(char *s, t_argdata *data, char *t);
char			*ft_apply_length_uox(t_argdata *data, uintmax_t t, int base);
char			*ft_apply_length_di(intmax_t t, int base, t_argdata *data);

/*
** ft_flag_management.c
*/

char			*ft_apply_flags(char *s, t_argdata *data, int neg);
void			ft_update_flag_values(t_argdata *data, int neg);
char			*ft_apply_zero(char *s, t_argdata *data, int neg);
char			*ft_apply_hash(char *s, t_argdata *data);
char			*ft_apply_apostrophe(char *str, t_argdata *data);

/*
** ft_fill_struct.c
*/

void			ft_fill_struct(t_argdata *data);
char			*ft_update_int(t_argdata *data, char *s, int i);
char			*ft_update_flag(char *s, t_argdata *data);
char			*ft_update_length(char *s, t_argdata *data);
int				ft_update_precision(char *s);

/*
** ft_support_functions.c
*/

char			*ft_append(char *s1, char *s2, int i);
char			*ft_uitoa(uintmax_t t, int b);
char			*ft_checkneg(intmax_t t, int b);
int				ft_nonum_after(char *s);
char			*ft_cut_zero(char *s, int len, t_argdata *data);

/*
** ft_parse_float.c
*/

char			*ft_check_infinity(long double f);
char			*ft_parse_float(long double f, t_argdata *data);
char			*ft_ftoa(long double f, char *s, t_argdata *data);
char			*ft_exponent(long double f, char *s, t_argdata *data, int exp);
char			*g_cv_switcher(long double f,
								t_argdata *data, char *s, int exp);

/*
** ft_parse_float2.c
*/

int				ft_check_normalize(long double x, int p);
long double		ft_normalize_float(long double x, int exp);
int				ft_find_exp_value(long double x);
int				ft_check_nine(long double x, int prec);
char			*ft_get_whole_part(long double f, char *s, t_argdata *data);

/*
** ft_round_float.c
*/

char			*ft_round_dec_string(char *s, int len);
char			*ft_get_rounded_str(long double x, char *s);
long double		ft_round_fraction(long double f);
long double		ft_round_down(long double f);
long double		ft_round_up(long double f);

/*
** ft_parse_a.c
*/

char			*ft_parse_a(long double d, t_argdata *data, char *s);
long double		ft_get_a_exp(long double x, int *exp, int base);
char			*ft_get_fract_a(long double f, char *s, t_argdata *data);
char			*ft_round_hexdec(char *s, int i, int e);
void			ft_iter_hexdec(char *s);

/*
** supported conversions
*/

char			*ft_cv_p(va_list *argval, t_argdata *data);
char			*ft_cv_o(va_list *argval, t_argdata *data);
char			*ft_cv_lo(va_list *argval, t_argdata *data);
char			*ft_cv_x(va_list *argval, t_argdata *data);
char			*ft_cv_lx(va_list *argval, t_argdata *data);
char			*ft_cv_d(va_list *argval, t_argdata *data);
char			*ft_cv_ld(va_list *argval, t_argdata *data);
char			*ft_cv_i(va_list *argval, t_argdata *data);
char			*ft_cv_u(va_list *argval, t_argdata *data);
char			*ft_cv_lu(va_list *argval, t_argdata *data);
char			*ft_cv_c(va_list *argval, t_argdata *data);
char			*ft_cv_wc(va_list *argval, t_argdata *data);
char			*ft_cv_s(va_list *argval, t_argdata *data);
char			*ft_cv_ws(va_list *argval, t_argdata *data);
char			*ft_cv_f(va_list *argval, t_argdata *data);
char			*ft_cv_bf(va_list *argval, t_argdata *data);
char			*ft_cv_e(va_list *argval, t_argdata *data);
char			*ft_cv_be(va_list *argval, t_argdata *data);
char			*ft_cv_n(va_list *argval, t_argdata *data);
char			*ft_cv_g(va_list *argval, t_argdata *data);
char			*ft_cv_bg(va_list *argval, t_argdata *data);
char			*ft_cv_a(va_list *argval, t_argdata *data);
char			*ft_cv_ba(va_list *argval, t_argdata *data);
char			*ft_convert_wchar(wchar_t v);

#endif
