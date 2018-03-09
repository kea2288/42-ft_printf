#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2018/03/02 13:37:10 by ekulyyev          #+#    #+#             *#
#*   Updated: 2018/03/02 17:55:18 by ekulyyev         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME:= libftprintf.a
FILES:= ft_printf ft_sprintf ft_convert_diu ft_convert_pox ft_convert_cs ft_formatparsing \
    ft_support_functions ft_fill_struct ft_flag_managment ft_formatparsing_additional \
    ft_convert_fen ft_convert_ga ft_parse_float ft_parse_float2 ft_round_floats \
	ft_modifiers_managment ft_parse_colors ft_parse_a

# ----- Libft ------
LFTDIR:= libft/
LFTFILES:= ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_itoa ft_memalloc \
    ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel ft_memmove ft_memset ft_putchar ft_putchar_fd \
    ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_strcat ft_strchr ft_strclr \
    ft_strcmp ft_strcpy ft_strdel ft_strdup ft_strequ ft_striter ft_striteri ft_strjoin ft_strlcat \
    ft_strlen ft_strmap ft_strmapi ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strnew ft_strnstr \
    ft_strrchr ft_strsplit ft_strstr ft_strsub ft_strtrim ft_tolower ft_toupper ft_lstnew ft_lstadd \
    ft_lstiter ft_lstdelone ft_lstdel ft_lstmap ft_realloc ft_free_2d ft_strrev ft_str_isin \
    ft_str_capital ft_intlen

# ==================

# ------------------
COMPILER:= gcc
CFLAGS:= -Wall -Werror -Wextra
LINKER:= ar rc
CCHPATH:= cache/
# ==================

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

# ------ Auto ------
SRC:=$(addsuffix .c,$(FILES)) $(addprefix $(LFTDIR),$(addsuffix .c,$(LFTFILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES))) $(addprefix $(LFTDIR),$(addsuffix .o,$(LFTFILES)))
# ==================
CCHF:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CYAN) "\tCompiling $@" $(RED)
	@$(LINKER) $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN)"OK"$(EOC)

$(CCHPATH)%.o: %.c $(CCHF)
	@echo $(PURPLE) "\tCompiling $< into $@" $(EOC)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED)"Missing file : $@" $(EOC)

$(CCHF):
	@mkdir -p $(CCHPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)
	@make clean -C $(LFTDIR)

fclean: clean
	@make fclean -C $(LFTDIR)
	@rm -f $(NAME)

re:
	@$(MAKE) all

norm:
	@echo $(RED)
	@norminette $(SRC) | grep -v Norme -B1 || true
	@echo $(END)

.PHONY: all clean fclean re test norme
