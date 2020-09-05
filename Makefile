# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/22 12:48:06 by ftothmur          #+#    #+#              #
#    Updated: 2020/08/30 16:20:13 by cmissy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==========================P̶O̶N̶Y̶ PHONY==========================================#
.PHONY: all clean fclean liba re debug delfile checkdir redebug d rd deljunk \
		makevisual
.SILENT:
#============================Folders & Files===================================#
#-------------------------------------ASM--------------------------------------#

ASM_INTERFACE_HEADER	:=

PRVT_ANALYZER_HEADER	:= asm_machine/analyser/prvt_analyser.h \
							asm_machine/analyser/prvt_analyser_xtor.h \
							asm_machine/analyser/prvt_text.h

ASM_NAME				:= asm
COREWAR_NAME			:= corewar
ASM_DIR					:= ./asm_machine/
VM_DIR					:= ./virtual_machine/
ASM_MAIN				:= main_asm.c
COREWAR_MAIN			:= virtual_machine/src/corwar/corwar.c
LABEL					:= CoreWar
WORKDIR					:= ./
LIBDIR					:= ./libft/
LIBPRINT				:= ./ft_printf/prntf
OPERATION_INTERFACE 	:= operation_interface
LIB						:=  $(LIBDIR)libft.a
LEX_SRC					:= 	lexer.c \
							lexer_get_term_arg_break.c \
							lexer_get_term_arg_dir.c \
							lexer_get_term_arg_ind.c \
							lexer_get_term_arg_reg.c \
							lexer_get_term_ch_comment.c \
							lexer_get_term_ch_name.c \
							lexer_get_term_com_cmd.c \
							lexer_get_term_comment.c \
							lexer_get_term_init.c \
							lexer_get_term_label_word_unit.c \
							lexer_get_term_line_feed.c \
							lexer_get_term_name_cmd.c \
							lexer_get_term_opx_multy.c \
							lexer_singleton_instance.c \
							lexer_utils_1.c \
							lexer_utils_2.c \
							prvt_lexer_xtor.c \
							token.c \
							token_getters.c \
							lexer_terms_is_op.c
LEX_OBJ					:=  $(patsubst %.c, %.o, $(LEX_SRC))
LEX_DIR_OBJ				:=  $(addprefix $(ASM_DIR)lexer/, $(LEX_OBJ))
PARS_SRC				:=	prvt_parser_change_state.c \
							prvt_find_parser_op0_state.c \
							prvt_parser_find_next_to_init_st.c \
							prvt_find_1_0_layer_op.c \
							prvt_find_1_1_layer_op.c \
							prvt_find_2_0_layer_op.c \
							prvt_find_2_1_layer_op.c \
							prvt_parser_find_next_to_op01_st.c \
							prvt_parser_find_next_to_op2_st.c \
							prvt_parser_get_token_eof.c \
							prvt_parser_get_token_init.c \
							prvt_parser_get_token_line_end.c \
							prvt_parser_get_token_op0_afct.c \
							prvt_parser_get_token_op0_arit.c \
							prvt_parser_get_token_op0_life.c \
							prvt_parser_get_token_op0_load.c \
							prvt_parser_get_token_op0_lodi.c \
							prvt_parser_get_token_op0_logc.c \
							prvt_parser_get_token_op0_stor.c \
							prvt_parser_get_token_op0_stri.c \
							prvt_parser_get_token_op1_arit.c \
							prvt_parser_get_token_op1_load.c \
							prvt_parser_get_token_op1_lodi.c \
							prvt_parser_get_token_op1_logc.c \
							prvt_parser_get_token_op1_stor.c \
							prvt_parser_get_token_op1_stri.c \
							prvt_parser_get_token_op2_arit.c \
							prvt_parser_get_token_op2_lodi.c \
							prvt_parser_get_token_op2_logc.c \
							prvt_parser_get_token_op2_stri.c \
							prvt_parser_xtor.c \
							expr.c \
							expr_xtor.c \
							expr_get_arg_x.c \
							arg_getters.c \
							expr_set_arg.c \
							expr_set_size.c \
							expr_set_type.c \
							parser.c \
							parser_singleton_instance.c
PARS_OBJ				:=  $(patsubst %.c, %.o, $(PARS_SRC))
PARS_DIR_OBJ			:=  $(addprefix $(ASM_DIR)parser/, $(PARS_OBJ))

CHK_SRC					:=	label_checker_inclusion_of_maps.c \
							label_checker_put_to_map.c
CHK_OBJ					:=  $(patsubst %.c, %.o, $(CHK_SRC))
CHK_DIR_OBJ				:=  $(addprefix $(ASM_DIR)checker/, $(CHK_OBJ))

ANALYSER_SRC			:= prvt_analyser_change_state.c \
							prvt_analyser_xtor.c \
							prvt_analyser_get_expr.c \
							analyser.c \
							analyser_singleton_instance.c
ANALYSER_OBJ			:=  $(patsubst %.c, %.o, $(ANALYSER_SRC))
ANALYSER_DIR_OBJ		:=  $(addprefix $(ASM_DIR)analyser/, $(ANALYSER_OBJ))


CODEGEN_SRC				:=	codegen_prototype.c \
							codegen_rotate_bytes.c \
							codegen_xtor.c \
							codegen_general.c \
							codegen_filling.c \
							codegen_add.c \
							codegen_bits.c \
							codegen_comment.c \
							codegen_header_init.c
CODEGEN_OBJ				:=  $(patsubst %.c, %.o, $(CODEGEN_SRC))
CODEGEN_DIR_OBJ			:=  $(addprefix $(ASM_DIR)codegen/, $(CODEGEN_OBJ))

ASM_DIR_COMMON			:= $(LEX_DIR_OBJ) $(PARS_DIR_OBJ) $(CHK_DIR_OBJ) \
							$(ANALYSER_DIR_OBJ) $(CODEGEN_DIR_OBJ) \
							$(ASM_DIR)$(ASM_MAIN)

ASM_HEADER_DIR_COMMON	:= $(ASM_INTERFACE_HEADER) \
							$(PRVT_ANALYZER_HEADER) \
							$(PRVT_CHECKER_HEADER) \
							$(PRVT_CODEGEN_HEADER) \
							$(PRVT_LEXER_HEADER) \
							$(PRVT_PARSER_HEADER)
ASM_IFLAG_COMMON		:= -I$(ASM_INTERFACE) \
							-I$(OPERATION_INTERFACE) \
							-I$(LIBDIR) \
							-I$(LIBPRINT)
#-------------------------------------VM---------------------------------------#
VM_SRC					:= prvt_vm_destroy.c \
							prvt_vm_new.c \
							vm_add_new_carriage_node.c \
							vm_carriage_list_destruct.c \
							vm_global_counter.c \
							vm_increase_num_of_live_ops.c \
							vm_num_of_carriages_and_increase.c \
							vm_play.c \
							vm_play_util.c \
							vm_singleton.c \
							vm_verbosity_lvl.c \
							vm_get_arena.c \
							vm_get_wins.c \
							vm_get_c_counter.c \
							vm_get_global_counter.c \
							vm_get_cycles_to_die.c \
							vm_get_speed.c \
							vm_set_key.c \
							vm_set_speed.c \
							vm_set_urgent_break.c
VM_OBJ					:= $(patsubst %.c, %.o, $(VM_SRC))
VM_DIR_OBJ				:= $(addprefix $(VM_DIR)src/, $(VM_OBJ))

VM_ARENA_SRC			:= arena_carriage_list_new.c \
							arena_destroy.c \
							arena_get_n_bytes_from.c \
							arena_nb_players.c \
							arena_new.c \
							arena_op_code.c \
							arena_players_introducing.c \
							arena_print_dump.c \
							arena_print_winner.c \
							arena_set_last_live_player.c \
							arena_set_named_player.c \
							arena_set_unnamed_player.c \
							arena_write_four_bytes_to_data.c \
							arena_get_player_index.c \
							arena_get_cell_index.c \
							arena_get_store_index.c \
							arena_get_data_by_address.c \
							arena_get_player.c \
							arena_get_nb_players.c \
							arena_set_player_index.c \
							arena_set_store_index.c \
							arena_set_carriage_num.c \
							arena_get_player_code_size.c \
							arena_set_cell_index.c \
							arena_set_color_is_set.c \
							arena_get_color_is_set.c \
							arena_get_last_live_player.c \
							arena_get_carriage_num.c \
							arena_change_carriage_num.c \
							prvt_arena_players_new.c \
							prvt_arena_set_smallest_unoccupied_name.c \
							arena_get_cell.c
VM_ARENA_OBJ			:= $(patsubst %.c, %.o, $(VM_ARENA_SRC))
VM_ARENA_DIR_OBJ		:= $(addprefix $(VM_DIR)src/arena/, $(VM_ARENA_OBJ))

VM_ARENA_PLAYER_SRC		:= player_code.c \
							player_code_size.c \
							player_destroy.c \
							player_introducing.c \
							player_live_verbosity.c \
							player_name.c \
							player_new.c \
							player_print_winner.c \
							player_set_name.c \
							player_get_name.c \
							player_get_text_name.c \
							player_get_text_comment.c
VM_ARENA_PLAYER_OBJ		:= $(patsubst %.c, %.o, $(VM_ARENA_PLAYER_SRC))
VM_ARENA_PLAYER_DIR_OBJ := $(addprefix $(VM_DIR)src/arena/player/, $(VM_ARENA_PLAYER_OBJ))

VM_CARRIAGE_SRC			:= 	carriage_destroy.c \
							carriage_is_alive.c \
							carriage_new.c \
							carriage_take_step.c \
							prvt_carriage_set_cycles_to_perform_op.c \
							prvt_carriage_set_is_correct_op_code.c \
							prvt_carriage_set_op_code.c \
							carriage_get_arena_position.c \
							carriage_get_player_name.c \
							carriage_get_stor_pos.c
VM_CARRIAGE_OBJ			:= $(patsubst %.c, %.o, $(VM_CARRIAGE_SRC))
VM_CARRIAGE_DIR_OBJ		:= $(addprefix $(VM_DIR)src/carriage/, \
							$(VM_CARRIAGE_OBJ))

VM_CARRIAGE_OP_SRC		:= 	operation_add.c \
							operation_aff.c \
							operation_and.c \
							operation_dispatched.c \
							operation_fork.c \
							operation_ld.c \
							operation_ldi.c \
							operation_lfork.c \
							operation_live.c \
							operation_lld.c \
							operation_lldi.c \
							operation_or.c \
							operation_precheck_args.c \
							operation_st.c \
							operation_sti.c \
							operation_sub.c \
							operation_xor.c \
							operation_zjmp.c
VM_CARRIAGE_OP_OBJ		:= $(patsubst %.c, %.o, $(VM_CARRIAGE_OP_SRC))
VM_CARRIAGE_OP_DIR_OBJ	:= $(addprefix $(VM_DIR)src/carriage/operation/, $(VM_CARRIAGE_OP_OBJ))


VM_COREWAR_SRC			:= corwar.c
VM_COREWAR_OBJ			:= $(patsubst %.c, %.o, $(VM_COREWAR_SRC))
VM_COREWAR_DIR_OBJ		:= $(addprefix $(VM_DIR)src/corwar/, $(VM_COREWAR_OBJ))

VM_ERRORS_SRC			:= errors.c
VM_ERRORS_OBJ			:= $(patsubst %.c, %.o, $(VM_ERRORS_SRC))
VM_ERRORS_DIR_OBJ		:= $(addprefix $(VM_DIR)src/errors/, $(VM_ERRORS_OBJ))

VM_PARAMS_SRC			:= 	ft_arg_is_num.c \
							prvt_vm_params_add_player_name_node.c \
							prvt_vm_params_add_player_node.c \
							prvt_vm_params_dump_cycles.c \
							prvt_vm_params_flag_cycles.c \
							prvt_vm_params_flag_name.c \
							prvt_vm_params_flag_verbose.c \
							prvt_vm_params_init.c \
							prvt_vm_params_parse.c \
							prvt_vm_params_set_file_name_with_id.c \
							prvt_vm_params_set_file_name_without_id.c \
							prvt_vm_params_set_player_name.c \
							vm_params_destroy.c \
							vm_params_destroy_players.c \
							vm_params_dump_cycles.c \
							vm_params_named_sorted_array_of_players.c \
							vm_params_nb_players.c \
							vm_params_new.c \
							vm_params_verbosity_lvl.c
VM_PARAMS_OBJ			:= $(patsubst %.c, %.o, $(VM_PARAMS_SRC))
VM_PARAMS_DIR_OBJ		:= $(addprefix $(VM_DIR)src/vm_params/, $(VM_PARAMS_OBJ))

VM_PARAMS_VMP_PLAYER_SRC:= vmp_player_destroy.c \
							vmp_player_file.c \
							vmp_player_name.c \
							vmp_player_new.c \
							vmp_player_set_file.c
VM_PARAMS_VMP_PLAYER_OBJ	:= $(patsubst %.c, %.o, $(VM_PARAMS_VMP_PLAYER_SRC))
VM_PARAMS_VMP_PLAYER_DIR_OBJ	:= $(addprefix $(VM_DIR)src/vm_params/vmp_player/, \
									$(VM_PARAMS_VMP_PLAYER_OBJ))

VM_PARAMS_VMP_PLAYER_FILE_SRC	:= file_code_size.c \
							file_data_check_valid.c \
							file_data_code.c \
							file_data_comment.c \
							file_data_name.c \
							file_destroy.c \
							file_new.c \
							prvt_file_allocate_initial_value.c \
							prvt_file_close.c \
							prvt_file_open.c \
							prvt_file_read.c \
							prvt_file_reallocate_value.c
VM_PARAMS_VMP_PLAYER_FILE_OBJ	:= $(patsubst %.c, %.o, \
									$(VM_PARAMS_VMP_PLAYER_FILE_SRC))
VM_PARAMS_VMP_PLAYER_FILE_DIR_OBJ	:= $(addprefix \
									$(VM_DIR)src/vm_params/vmp_player/file/, \
									$(VM_PARAMS_VMP_PLAYER_FILE_OBJ))


VISUAL_SRC				:=		chose_color.c \
							create_newwin.c \
							draw_arena.c \
							draw_basic_info.c \
							draw_champ_info.c \
							erase_windows.c \
							init_colormap.c \
							init_colors.c \
							init_curses.c \
							init_wins.c \
							print_windows.c \
							print_winner_visual.c \
							process_keys.c \
							rebuild_color_map.c
VISUAL_OBJ				:= $(patsubst %.c, %.o, $(VISUAL_SRC))
VISUAL_DIR_OBJ			:= $(addprefix $(VM_DIR)src/visual/, $(VISUAL_OBJ))

CFLAGS					:= -Wall -Wextra -Werror
LIBFLAGS				:= -L$(LIBDIR) -lft
LIBPRINTFLAGS			:= -Lft_printf/ -lftprintf
ASM_INTERFACE			:=	$(ASM_DIR)interfaces/
COREWAR_INTERFACE 		:=	$(WORKDIR)virtual_machine/interfaces/

#======================HEADERS_DEPENDENCIES====================================#
ASM_INTERFACE_HEADER	:= $(ASM_INTERFACE)analyser.h \
							$(ASM_INTERFACE)codegen.h \
							$(ASM_INTERFACE)expr.h \
							$(ASM_INTERFACE)expr_defines.h \
							$(ASM_INTERFACE)label_checker.h \
							$(ASM_INTERFACE)lexer.h \
							$(ASM_INTERFACE)main_asm.h \
							$(ASM_INTERFACE)parser.h \
							$(ASM_INTERFACE)text.h \
							$(ASM_INTERFACE)token.h \
							$(ASM_INTERFACE)token_defines.h

PRVT_ANALYZER_HEADER	:= $(ASM_DIR)analyser/prvt_analyser.h \
							$(ASM_DIR)analyser/prvt_analyser_xtor.h \
							$(ASM_DIR)analyser/prvt_text.h

PRVT_CHECKER_HEADER		:= $(ASM_DIR)checker/label_checker_private.h

PRVT_CODEGEN_HEADER		:= $(ASM_DIR)codegen/codegen_prototype.h \
							$(ASM_DIR)codegen/prvt_codegen.h

PRVT_LEXER_HEADER		:= $(ASM_DIR)lexer/prvt_lexer.h \
							$(ASM_DIR)lexer/prvt_lexer_utils.h \
							$(ASM_DIR)lexer/prvt_lexer_xtor.h \
							$(ASM_DIR)lexer/prvt_token.h

PRVT_PARSER_HEADER		:= $(ASM_DIR)parser/parser_private.h \
							$(ASM_DIR)parser/parser_xtor_private.h \
							$(ASM_DIR)parser/prvt_expr.h
#							$(ASM_DIR)parser/
#							$(ASM_DIR)parser/
#							$(ASM_DIR)parser/
#======================COLORS & Co=============================================#
GREEN					= \033[1;32m
RED						= \033[1;31m
RST						= \033[0m
BOLD					= \033[1m
CYAN					= \033[1;36m
PREFIX					= [$(CYAN)$(LABEL)$(RST)]:\t

#======================Debug & Flags===========================================#
# -- WARN! Delete this message from rules if you using library from another prj#
ifeq ($(DEBUGMODE), 1)
	FLAGS				:= $(CFLAGS)
	DEBUGMSG			:= $(PREFIX)⚠️  \033[1;33m \
							Debug mode $(GREEN)enabled.$(RST)\n
else
	FLAGS				:= -g $(CFLAGS)
	DEBUGMSG			:= $(PREFIX)⚠️  \033[1;33m \
							Debug mode $(RED)disabled.$(RST)\n
endif

#=================================Rules========================================#
all: debmsg liba $(ASM_NAME) $(COREWAR_NAME)
		@echo "$(PREFIX)✅  $(GREEN)All files up-to-date or \
rebuilt.$(RST)"

debmsg:
		@printf "$(DEBUGMSG)"

$(ASM_NAME): $(ASM_DIR_COMMON)
		gcc $(FLAGS) -I$(ASM_INTERFACE) -I$(OPERATION_INTERFACE)  -I$(LIBDIR) \
			-I$(LIBPRINT) $(ASM_DIR_COMMON) -o $@ $(LIBFLAGS) $(LIBPRINTFLAGS)
		printf "%-95c\r$(PREFIX)📦  Assembler file created.\n" ' '

LEXER_DEPSRC := $(addprefix $(ASM_DIR)lexer/, $(LEX_SRC))
LEXER_DEPFILES := $(LEXER_DEPSRC:.c=.d)
-include $(LEXER_DEPFILES)
$(LEX_DIR_OBJ): %.o:  %.c
		printf "%-105c\r$(PREFIX)" ' '
		printf "🕐  %s Compiling Lexer... (%s)\r" "[00%]" "$@"
		gcc $(FLAGS) -I$(ASM_INTERFACE) -I$(LIBDIR)  -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -MM -MT $@ -MF $(patsubst %.o, %.d, $@) $<
		gcc $(FLAGS) -I$(ASM_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -c $< -o $@

PARSER_DEPSRC := $(addprefix $(ASM_DIR)parser/, $(PARS_SRC))
PARSER_DEPFILES := $(PARSER_DEPSRC:.c=.d)
-include $(PARS_DEPFILES)
$(PARS_DIR_OBJ): %.o: %.c
		printf "%-105c\r$(PREFIX)" ' '
		printf "🕐  %s Compiling Parser... (%s)\r" "[06%]" "$@"
		gcc $(FLAGS) -I$(ASM_INTERFACE) -I$(LIBDIR)  -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -MM -MT $@ -MF $(patsubst %.o, %.d, $@) $<
		gcc $(FLAGS) -I$(ASM_INTERFACE) -I$(LIBDIR)  -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -c  $<  -o $@

CHECKER_DEPSRC := $(addprefix $(ASM_DIR)checker/, $(CHK_SRC))
CHECKER_DEPFILES := $(CHECKER_DEPSRC:.c=.d)
-include $(CHECKER_DEPFILES)
$(CHK_DIR_OBJ): %.o: %.c
		printf "%-105c\r$(PREFIX)" ' '
		printf "🕐  %s Compiling Checker... (%s)\r" "[12%]" "$@"
		gcc $(FLAGS) -I$(ASM_INTERFACE) -I$(LIBDIR)  -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -MM -MT $@ -MF $(patsubst %.o, %.d, $@) $<
		gcc $(FLAGS) -I$(ASM_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -c $<  -o $@

ANALYSER_DEPSRC := $(addprefix $(ASM_DIR)analyser/, $(ANALYSER_SRC))
ANALYSER_DEPFILES := $(ANALYSER_DEPSRC:.c=.d)
-include $(ANALYSER_DEPFILES)
$(ANALYSER_DIR_OBJ): %.o: %.c #$(ANALYSER_DEPFILES)
		printf "%-105c\r$(PREFIX)" ' '
		printf "🕐  %s Compiling Analyser... (%s)\r" "[18%]" "$@"
		gcc $(FLAGS) -I$(ASM_INTERFACE) -I$(LIBDIR)  -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -MM -MT $@ -MF $(patsubst %.o, %.d, $@) $<
		gcc $(FLAGS) -I$(ASM_INTERFACE) -I$(LIBDIR)  -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -c $< -o $@

CODEGEN_DEPSRC := $(addprefix $(ASM_DIR)codegen/, $(CODEGEN_SRC))
CODEGEN_DEPFILES := $(CODEGEN_DEPSRC:.c=.d)
-include $(CODEGEN_DEPFILES)
$(CODEGEN_DIR_OBJ): %.o: %.c
		printf "%-105c\r$(PREFIX)" ' '
		printf "🕐  %s Compiling Codegen... (%s)\r" "[25%]" "$@"
		gcc -I$(ASM_INTERFACE) -I$(LIBDIR)  -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -MM -MT $@ -MF $(patsubst %.o, %.d, $@) $<
		gcc $(FLAGS) -I$(ASM_INTERFACE) -I$(LIBDIR)  -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE)  -c $<  -o $@

$(COREWAR_NAME): $(VM_DIR_OBJ) $(VM_ARENA_DIR_OBJ) $(VM_ARENA_PLAYER_DIR_OBJ) \
		$(VM_CARRIAGE_DIR_OBJ) $(VM_CARRIAGE_OP_DIR_OBJ) \
		$(VM_COREWAR_DIR_OBJ) $(VM_ERRORS_DIR_OBJ) $(VM_PARAMS_DIR_OBJ) \
		$(VM_PARAMS_VMP_PLAYER_DIR_OBJ) $(VM_PARAMS_VMP_PLAYER_FILE_DIR_OBJ) \
		$(VISUAL_DIR_OBJ)
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE)  $^ -lncurses -o $@ $(LIBFLAGS) \
			$(LIBPRINTFLAGS)
		printf "%-95c\r$(PREFIX)📦  Corewar file created.\n" ' '


VM_DEPSRC := $(addprefix $(VM_DIR)src/, $(VM_SRC))
VM_DEPFILES := $(VM_DEPSRC:.c=.d)
-include $(VM_DEPFILES)
$(VM_DIR_OBJ): %.o: %.c
		printf "%-105c\r$(PREFIX)" ' '
		printf "🕐  %s Compiling VM_OBJ... (%s)\r" "[31%]" "$@"
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -MM -MT $@ -MF $(patsubst %.o, %.d, $@) $<
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE)  -c $< -o $@


VM_ARENA_DEPSRC := $(addprefix $(VM_DIR)src/arena/, $(VM_ARENA_SRC))
VM_ARENA_DEPFILES := $(VM_ARENA_DEPSRC:.c=.d)
-include $(VM_ARENA_DEPFILES)
$(VM_ARENA_DIR_OBJ): %.o: %.c
		printf "%-125c\r$(PREFIX)" ' '
		printf "🕐  %s Compiling VM_ARENA... (%s)\r" "[37%]" "$@"
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -MM -MT $@ -MF $(patsubst %.o, %.d, $@) $<
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR)  -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE)  -c $< -o $@

VM_ARENA_PLAYER_DEPSRC := $(addprefix $(VM_DIR)src/arena/player/, $(VM_ARENA_PLAYER_SRC))
VM_ARENA_PLAYER_DEPFILES := $(VM_ARENA_PLAYER_DEPSRC:.c=.d)
-include $(VM_ARENA_PLAYER_DEPFILES)
$(VM_ARENA_PLAYER_DIR_OBJ): %.o: %.c
		printf "%-115c\r$(PREFIX)" ' '
		printf "🕐  %s Compiling VM_A_PLAYER... (%s)\r" "[43%]" "$@"
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -MM -MT $@ -MF $(patsubst %.o, %.d, $@) $<
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE)  -c $< -o $@


VM_CARRIAGE_DEPSRC := $(addprefix $(VM_DIR)src/carriage/, $(VM_CARRIAGE_SRC))
VM_CARRIAGE_DEPFILES := $(VM_CARRIAGE_DEPSRC:.c=.d)
-include $(VM_CARRIAGE_DEPFILES)
$(VM_CARRIAGE_DIR_OBJ): %.o: %.c
		printf "%-125c\r$(PREFIX)" ' '
		printf "🕐  %s Compiling VM_CARRIAGE... (%s)\r" "[50%]" "$@"
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -MM -MT $@ -MF $(patsubst %.o, %.d, $@) $<
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE)  -c $< -o $@


VM_CARRIAGE_OP_DEPSRC := $(addprefix $(VM_DIR)src/carriage/operation/, $(VM_CARRIAGE_OP_SRC))
VM_CARRIAGE_OP_DEPFILES := $(VM_CARRIAGE_OP_DEPSRC:.c=.d)
-include $(VM_CARRIAGE_OP_DEPFILES)
$(VM_CARRIAGE_OP_DIR_OBJ): %.o: %.c
		printf "%-125c\r$(PREFIX)" ' '
		printf "🕐  %s Compiling VM_OP... (%s)\r" "[56%]" "$@"
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -MM -MT $@ -MF $(patsubst %.o, %.d, $@) $<
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE)  -c $< -o $@


VM_COREWAR_DEPSRC := $(addprefix $(VM_DIR)src/corwar/, $(VM_COREWAR_SRC))
VM_COREWAR_DEPFILES := $(VM_COREWAR_DEPSRC:.c=.d)
-include $(VM_COREWAR_DEPFILES)
$(VM_COREWAR_DIR_OBJ): %.o: %.c
		printf "%-125c\r$(PREFIX)" ' '
		printf "🕐  %s Compiling VM_OBJ... (%s)\r" "[62%]" "$@"
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -MM -MT $@ -MF $(patsubst %.o, %.d, $@) $<
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE)  -c $< -o $@


VM_ERRORS_DEPSRC := $(addprefix $(VM_DIR)src/errors/, $(VM_ERRORS_SRC))
VM_ERRORS_DEPFILES := $(VM_ERRORS_DEPSRC:.c=.d)
-include $(VM_ERRORS_DEPFILES)
$(VM_ERRORS_DIR_OBJ): %.o: %.c
		printf "%-125c\r$(PREFIX)" ' '
		printf "🕐  %s Compiling VM_ERRORS... (%s)\r" "[68%]" "$@"
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -MM -MT $@ -MF $(patsubst %.o, %.d, $@) $<
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE)  -c $< -o $@


VM_PARAMS_DEPSRC := $(addprefix $(VM_DIR)src/vm_params/, $(VM_PARAMS_SRC))
VM_PARAMS_DEPFILES := $(VM_PARAMS_DEPSRC:.c=.d)
-include $(VM_PARAMS_DEPFILES)
$(VM_PARAMS_DIR_OBJ): %.o: %.c
		printf "%-125c\r$(PREFIX)" ' '
		printf "🕐  %s Compiling VM_PARAMS... (%s)\r" "[75%]" "$@"
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -MM -MT $@ -MF $(patsubst %.o, %.d, $@) $<
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE)  -c $< -o $@


VM_PARAMS_VMP_PLAYER_DEPSRC := $(addprefix $(VM_DIR)src/vm_params/vmp_player/, $(VM_PARAMS_VMP_PLAYER_SRC))
VM_PARAMS_VMP_PLAYER_DEPFILES := $(VM_PARAMS_VMP_PLAYER_DEPSRC:.c=.d)
-include $(VM_PARAMS_VMP_PLAYER_DEPFILES)
$(VM_PARAMS_VMP_PLAYER_DIR_OBJ): %.o: %.c
		printf "%-125c\r$(PREFIX)" ' '
		printf "🕐  %s Compiling VM_P_PLAYER... (%s)\r" "[81%]" "$@"
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -MM -MT $@ -MF $(patsubst %.o, %.d, $@) $<
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE)  -c $< -o $@


VM_PARAMS_VMP_PLAYER_FILE_DEPSRC := $(addprefix $(VM_DIR)src/vm_params/vmp_player/file/, $(VM_PARAMS_VMP_PLAYER_FILE_SRC))
VM_PARAMS_VMP_PLAYER_FILE_DEPFILES := $(VM_PARAMS_VMP_PLAYER_FILE_DEPSRC:.c=.d)
-include $(VM_PARAMS_VMP_PLAYER_FILE_DEPFILES)
$(VM_PARAMS_VMP_PLAYER_FILE_DIR_OBJ): %.o: %.c
		printf "%-125c\r$(PREFIX)" ' '
		printf "🕐  %s Compiling VM_FILES... (%s)\r" "[87%]" "$@"
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -MM -MT $@ -MF $(patsubst %.o, %.d, $@) $<
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE)  -c $< -o $@


VM_VISUAL_DEPSRC := $(addprefix $(VM_DIR)src/visual/, $(VISUAL_SRC))
VM_VISUAL_DEPFILES:= $(VM_VISUAL_DEPSRC:.c=.d)
-include $(VM_VISUAL_DEPFILES)
$(VISUAL_DIR_OBJ): %.o: %.c
		printf "%-130c\r$(PREFIX)" ' '
		printf "🕐  %s Compiling VISUAL... (%s)\r" "[98%]" "$@"
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE) -MM -MT $@ -MF $(patsubst %.o, %.d, $@) $<
		gcc $(FLAGS) -I$(COREWAR_INTERFACE) -I$(LIBDIR) -I$(LIBPRINT) \
			-I$(OPERATION_INTERFACE)  -c $<  -o $@

liba:
		@printf "$(PREFIX)$(BOLD)🔎  Checkig \
for libft and printf updates...$(RST)\n"
		@make -C $(LIBDIR) DEBUG=$(DEBUGMODE)
		make -C ./ft_printf/

deljunk:
	echo "$(PREFIX)♻️  $(RED)Removing obj-files...$(RST)"
	rm -rf $(ASM_DIR)lexer/*.o
	rm -rf $(ASM_DIR)lexer/*.d
	rm -rf $(ASM_DIR)parser/*.o
	rm -rf $(ASM_DIR)parser/*.d
	rm -rf $(ASM_DIR)checker/*.o
	rm -rf $(ASM_DIR)checker/*.d
	rm -rf $(ASM_DIR)analyser/*.o
	rm -rf $(ASM_DIR)analyser/*.d
	rm -rf $(ASM_DIR)codegen/*.o
	rm -rf $(ASM_DIR)codegen/*.d
	rm -rf virtual_machine/src/*.o
	rm -rf virtual_machine/src/*.d
	rm -rf virtual_machine/src/arena/*.o
	rm -rf virtual_machine/src/arena/*.d
	rm -rf virtual_machine/src/arena/player/*.o
	rm -rf virtual_machine/src/arena/player/*.d
	rm -rf virtual_machine/src/carriage/*.o
	rm -rf virtual_machine/src/carriage/*.D
	rm -rf virtual_machine/src/carriage/operation/*.o
	rm -rf virtual_machine/src/carriage/operation/*.d
	rm -rf virtual_machine/src/corwar/*.o
	rm -rf virtual_machine/src/corwar/*.d
	rm -rf virtual_machine/src/errors/*.o
	rm -rf virtual_machine/src/errors/*.d
	rm -rf virtual_machine/src/vm_params/*.o
	rm -rf virtual_machine/src/vm_params/*.d
	rm -rf virtual_machine/src/vm_params/vmp_player/*.o
	rm -rf virtual_machine/src/vm_params/vmp_player/*.d
	rm -rf virtual_machine/src/vm_params/vmp_player/file/*.o
	rm -rf virtual_machine/src/vm_params/vmp_player/file/*.d
	rm -rf virtual_machine/src/visual/*.o
	rm -rf virtual_machine/src/visual/*.d

clean: deljunk
		make -C $(LIBDIR) clean

delfile:
		@echo "$(PREFIX)♻️  $(RED)Removing executable files...$(RST)"
		@rm -f $(ASM_NAME)
		@rm -f $(COREWAR_NAME)

fclean: deljunk delfile
		@make -C $(LIBDIR) fclean
		make -C ft_printf/ fclean

re: fclean
		@make all

debug:
	make DEBUGMODE=1

d:
	make DEBUGMODE=1

rd:
	make re DEBUGMODE=1

red:
	make re DEBUGMODE=1

redebug:
	make re DEBUGMODE=1