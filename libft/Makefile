# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Make                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/01 10:04:16 by ftothmur          #+#    #+#              #
#    Updated: 2020/03/04 17:01:46 by ftothmur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		all clean fclean re force
#=================================COLORS & co==================================#
GREEN =		\033[1;32m
RED =		\033[1;31m
RST =		\033[0m
BOLD =		\033[1m
CYAN =		\033[1;36m
PREFIX =	[$(CYAN)libft$(RST)]:\t
#===================================PROJECT====================================#
#---------------------------------directories----------------------------------#
LIB_DIR =	./
HDR_DIR =	./
SRC_DIR =	./
PRNTF_DIR =	./ft_printf
#------------------------------------s-------------------------------------#
NAME =		libft.a
PRNTF =		./ft_printf/libftprintf.a
HEADER =	libft.h get_next_line.h
OBJ = 		$(SRC:.c=.o)
SRC =		$(PART_1) \
			$(PART_2) \
			$(BONUS) \
	 		$(EXPANSION)
PART_1 =	ft_strcat.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strncmp.c \
			ft_memcpy.c \
			ft_strcpy.c \
			ft_memcmp.c \
			ft_memccpy.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_strnstr.c \
			ft_bzero.c \
			ft_strncat.c \
			ft_strlen.c \
			ft_strncpy.c \
			ft_strchr.c \
			ft_isascii.c \
			ft_strcmp.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_strdup.c \
			ft_isalpha.c \
			ft_isprint.c \
			ft_tolower.c \
			ft_memchr.c \
			ft_atoi.c \
			ft_memmove.c \
			ft_memset.c
PART_2 =    ft_memalloc.c \
			ft_putchar_fd.c \
			ft_strmapi.c \
			ft_memdel.c \
			ft_putstr_fd.c \
			ft_strtrim.c \
			ft_putnbr_fd.c \
			ft_putendl_fd.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_strsub.c \
			ft_strequ.c \
			ft_strdel.c \
			ft_itoa.c \
			ft_strjoin.c \
			ft_strmap.c \
			ft_strnequ.c \
			ft_putchar.c \
			ft_putendl.c \
			ft_striteri.c \
			ft_striter.c \
			ft_strsplit.c \
			ft_strnew.c\
			ft_strclr.c
BONUS =		ft_lstdel.c    \
			ft_lstiter.c \
			ft_lstnew.c \
			ft_lstadd.c \
			ft_lstdelone.c \
			ft_lstmap.c

EXPANSION =	ft_isspace.c \
			ft_isupper.c \
			ft_islower.c \
			ft_strnlen.c \
			ft_power.c \
			ft_itostr.c \
			ft_strchr_no.c \
			ft_strnchr.c \
			ft_spskip.c \
			ft_strtoupper.c \
			ft_strtolower.c \
			ft_realloc.c \
			ft_realloc_safe.c \
			ft_memjoin.c \
			ft_imax.c \
			ft_imin.c \
			ft_isbinary.c \
			ft_lstaddtip.c \
			ft_lstat.c \
			ft_lstlast.c \
			ft_lstsize.c \
			ft_lstremove.c \
			ft_lstcmp_next.c \
			ft_lstforeach_if.c \
			ft_lstforeach.c \
			ft_lstcontentdel.c \
			ft_lstrev.c \
			ft_lstfind.c \
			ft_lstfind_prev.c \
			ft_lstpushback.c \
			ft_reverse.c \
			ft_strrev.c \
			ft_swap.c \
			ft_set_nth_bit.c \
			ft_unset_nth_bit.c \
			ft_set_nth_bit.c \
			ft_ispowerof2.c \
			ft_powerof2roundup.c \
			ft_powerof2rounddown.c \
			ft_abs.c \
			ft_imaxabs.c \
			ft_delim.c \
			ft_fit_size.c \
			ft_error.c \
			ft_error_ptr.c \
			ft_div_mod.c \
			ft_lldiv_mod.c \
			ft_imaxdiv.c \
			ft_uimaxdiv.c \
			ft_udiv_struc.c \
			ft_imaxtostr.c \
			ft_uintmaxtostr.c \
			ft_isnan.c \
			ft_isinf.c \
			ft_print_bits.c \
			ft_wcslen.c \
			ft_wcsnlen.c \
			ft_wcslen.c \
			ft_wclen.c \
			ft_wcscpy.c \
			ft_wcsncpy.c \
			ft_wcsdup.c \
			ft_wcsnew.c \
			ft_putwchar_fd.c \
			ft_putwchar.c \
			ft_putwcs_fd.c \
			ft_putwcs.c \
			ft_putnstr_fd.c \
			ft_putnstr.c \
			ft_putnwcs_fd.c \
			ft_putnwcs.c \
			ft_remove_sign_bit.c \
			ft_quicksort.c \
			ft_dlstsize.c \
			ft_dlstsort_bubble.c \
			ft_dlstiter.c \
			ft_dlstnew.c \
			ft_dlstnew_ptr.c \
			ft_dlstadd.c \
			ft_dlstaddtip.c \
			ft_dlstdel.c \
			ft_dlstcontentdel.c \
			ft_dlstforeach.c \
			ft_dlstswap.c \
			ft_dlstpop.c \
			ft_dlstpush.c \
			ft_dlstpush_back.c \
			ft_dlstextract.c \
			ft_dlstpop_rear.c \
			ft_dlstfind.c \
			ft_dlstfind_i.c \
			ft_dlstfind_r.c \
			ft_dlstfind_ir.c \
			ft_dlstcmp.c \
			ft_dlstmerge.c \
			ft_memrcmp.c \
			ft_intrcmp.c \
			ft_free_ptr_ar.c \
			ft_isdigitstr.c \
			ft_strint_ou_flow.c \
			ft_isdigitnstr.c \
			ft_ddeqnew.c \
			ft_ddeq_new_a.c \
			ft_ddeqdel.c \
			ft_ddeqpush_b_all.c \
			ft_ddeqpush_b.c \
			ft_ddeqextract_b.c \
			ft_ddeqreset_a.c \
			ft_delfunc_dummy.c \
			ft_str_avl_balance.c \
			ft_str_avl_bfactor.c \
			ft_str_avl_create.c \
			ft_str_avl_del.c \
			ft_str_avl_findmin.c \
			ft_str_avl_fix_height.c \
			ft_str_avl_height.c \
			ft_str_avl_insert.c \
			ft_str_avl_remove.c \
			ft_str_avl_rot_left.c \
			ft_str_avl_rot_right.c \
			ft_str_avl_search.c \
			ft_vector_add.c \
			ft_vector_delete.c \
			ft_vector_free.c \
			ft_vector_free_data.c \
			ft_vector_get.c \
			ft_vector_init.c \
			ft_vector_resize.c \
			ft_vector_set.c \
			ft_vector_total.c \
			ft_void_arithm.c \
			ft_vector_get_curr.c \
			ft_vector_traversal.c \
			ft_strsearch.c \
			ft_strclen.c \
			ft_strrejoin.c \
			ft_str_to_uintmax.c \
			ft_str_to_intmax.c \
			ft_keystr_avl_tree_traversal.c \
			ft_hash_map_ctor.c \
			ft_hash_map_dtor.c \
			ft_hash_map_get.c \
			ft_hash_map_hashcode.c \
			ft_hash_map_set.c \
			ft_hash_map_set_content.c \
			ft_hash_map_put_to_map.c \
			ft_atol.c
#--------------------COMPILER_OPTIONS--------------------#
ifeq ($(DEBUG), 1)
	CC_FLAGS =	-Wall -Wextra -Werror -g
	DEBUGMSG	:= $(PREFIX)⚠️  \033[1;33mWarn! Debug mode enabled.$(RST)\n
else
	DEBUGMSG	:= $(PREFIX)⚠️  \033[1;33mDebug mode disabled.$(RST)\n
	CC_FLAGS =	-Wall -Wextra -Werror
endif
LIB_FLAGS =	-L$(LIB_DIR) -lft
#--------------------------RULES-------------------------#
all:		$(NAME)
		@echo "$(PREFIX)✅  $(GREEN)Done.$(RST)"

$(NAME):	 $(OBJ) $(HEADER)
		@printf "%-95c\r$(PREFIX)✅  $(GREEN)All files accepted.$(RST)\n" ' '
		@echo "$(PREFIX)📦  Packaging files into library file..."
		#cp $(PRNTF) $(NAME)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

#$(PRNTF): force
		#make -C $(PRNTF_DIR)
#--REMOVE this rule from $(NAME) if you compile lib into another project.--#

deb_msg:
		@printf "$(DEBUGMSG)"

%.o : 		%.c
		@printf "%-95c\r$(PREFIX)" ' '
		@printf "🕐  Compiling file:\t%-30s\r" "$@"
		@gcc -c $(CC_FLAGS) $< -I$(HDR_DIR)

clean:
		@echo "$(PREFIX)♻️  $(RED)Removing obj-files...$(RST)"
		@rm -rf $(OBJ)

fclean: 	clean
		@echo "$(PREFIX)♻️  $(RED)Removing library...$(RST)"
		@rm -rf $(NAME)

re:			fclean all

d:
		@make DEBUG=1
dre:		fclean d