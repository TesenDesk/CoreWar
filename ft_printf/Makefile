
SRC_PATH := prntf/
NAME := libftprintf.a
HEADER := prntf/ft_printf.h
CFLAGS := -Wall -Wextra -Werror
SRC := adjust_prec_analize_cell.c adjust_prec_norm_form.c adjust_prec_rebuild_func.c  adjust_prec_sci_form.c adjust_prec_utility_func.c  char_manager.c chose_content.c chose_content2.c content_decision_maker.c  distinct_types.c fill_spec_func1.c fill_spec_func2.c ldouble_manager1.c ldouble_manager2.c ldouble_utilities.c ldouble_inf_nan.c ft_itoa_base.c ft_printf.c libft_func_1.c libft_func_2.c long_arythmetic1.c long_arythmetic2.c long_arythmetic3.c long_arythmetic4.c long_arythmetic5.c manage_str.c num_manager.c num_manager_utilities.c print_func.c put_into_buf_func1.c put_into_buf_ldouble.c put_into_buf_ldouble_utilities.c put_buf_ld_sci_form.c put_into_buf_utf.c str_manager.c
SEARCH := $(addprefix $(SRC_PATH), $(SRC))
OBJ := $(patsubst %.c,%.o,$(SEARCH))

GREEN					= \033[1;32m
RED						= \033[1;31m
RST						= \033[0m
BOLD					= \033[1m
CYAN					= \033[1;36m
LABEL					= printf
PREFIX					= [$(CYAN)$(LABEL)$(RST)]:\t

ifeq ($(DEBUGMODE), 1)
	FLAGS				:= $(CFLAGS)
else
	FLAGS				:= $(CFLAGS) -g
endif

all: $(NAME)
	@printf "%-95c\r$(PREFIX)✅  $(GREEN)Done.$(RST)\n" ' '

$(NAME): $(OBJ)
	ar rc  $@ $^
	ranlib $@

%.o : %.c $(HEADER)
	@printf "%-95c\r$(PREFIX)" ' '
	@printf "🕐  Compiling file:\t%-30s\r" "$@"
	gcc -c $< -I ./prntf $(CFLAGS)  -o $@ -g

clean:
	rm -rf $(OBJ) 

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
