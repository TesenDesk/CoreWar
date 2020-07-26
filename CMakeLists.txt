cmake_minimum_required(VERSION 3.15)
project(core C)

set(CMAKE_C_STANDARD 11)

include_directories(analyser)
include_directories(checker)
include_directories(interfaces)
include_directories(lexer)
include_directories(libft)
include_directories(parser)
include_directories(virtual_machine/interfaces)
include_directories(virtual_machine/src)
include_directories(virtual_machine/src/arena)
include_directories(virtual_machine/src/arena/player)
include_directories(virtual_machine/src/arena/player/code)
include_directories(virtual_machine/src/carriage)
include_directories(virtual_machine/src/carriage/arguments)
include_directories(virtual_machine/src/carriage/operation)
include_directories(virtual_machine/src/corwar)
include_directories(virtual_machine/src/errors)
include_directories(virtual_machine/src/vm_params)
include_directories(virtual_machine/src/vm_params/vmp_player)
include_directories(virtual_machine/src/vm_params/vmp_player/file)

add_executable(asm_machine
        analyser/prvt_analyser_change_state.c
        analyser/prvt_analyser_get_expr.c
        analyser/prvt_analyser_xtor.c
        analyser/analyser.c
        analyser/prvt_analyser.h
        analyser/analyser_singleton_instance.c
        analyser/prvt_analyser_xtor.h
        analyser/prvt_text.h
        checker/checker_main.c
        checker/label_checker_inclusion_of_maps.c
        checker/label_checker_private.h
        checker/label_checker_put_to_map.c
        interfaces/analyser.h
        interfaces/expr.h
        interfaces/expr_defines.h
        interfaces/label_checker.h
        interfaces/lexer.h
        interfaces/parser.h
        interfaces/text.h
        interfaces/token.h
        interfaces/token_defines.h
        lexer/lexer.c
        lexer/lexer_get_term_arg_break.c
        lexer/lexer_get_term_arg_dir.c
        lexer/lexer_get_term_arg_ind.c
        lexer/lexer_get_term_arg_reg.c
        lexer/lexer_get_term_ch_comment.c
        lexer/lexer_get_term_ch_name.c
        lexer/lexer_get_term_com_cmd.c
        lexer/lexer_get_term_comment.c
        lexer/lexer_get_term_init.c
        lexer/lexer_get_term_label_word_unit.c
        lexer/lexer_get_term_line_feed.c
        lexer/lexer_get_term_name_cmd.c
        lexer/lexer_get_term_opx_multy.c
        lexer/prvt_lexer.h
        lexer/lexer_singleton_instance.c
        lexer/lexer_utils_1.c
        lexer/lexer_utils_2.c
        lexer/prvt_lexer_utils.h
        lexer/prvt_lexer_xtor.c
        lexer/prvt_lexer_xtor.h
        lexer/token.c
#        lexer/token_name_init.c
        lexer/prvt_token.h
        libft/ft_abs.c
        libft/ft_atoi.c
        libft/ft_atol.c
        libft/ft_bzero.c
#        libft/ft_check_endiannes.c
        libft/ft_ddeq_new_a.c
        libft/ft_ddeqdel.c
        libft/ft_ddeqextract_b.c
        libft/ft_ddeqnew.c
        libft/ft_ddeqpush_b.c
        libft/ft_ddeqpush_b_all.c
        libft/ft_ddeqreset_a.c
        libft/ft_delfunc_dummy.c
        libft/ft_delim.c
        libft/ft_div_mod.c
        libft/ft_dlstadd.c
        libft/ft_dlstaddtip.c
        libft/ft_dlstcmp.c
        libft/ft_dlstcontentdel.c
        libft/ft_dlstdel.c
        libft/ft_dlstextract.c
        libft/ft_dlstfind.c
        libft/ft_dlstfind_i.c
        libft/ft_dlstfind_ir.c
        libft/ft_dlstfind_r.c
        libft/ft_dlstforeach.c
        libft/ft_dlstforeach_if.c
        libft/ft_dlstiter.c
        libft/ft_dlstmerge.c
        libft/ft_dlstnew.c
        libft/ft_dlstnew_ptr.c
        libft/ft_dlstpop.c
        libft/ft_dlstpop_rear.c
        libft/ft_dlstpush.c
        libft/ft_dlstpush_back.c
        libft/ft_dlstsize.c
        libft/ft_dlstsort_bubble.c
        libft/ft_dlstswap.c
        libft/ft_error.c
        libft/ft_error_ptr.c
        libft/ft_fit_size.c
        libft/ft_free_ptr_ar.c
        libft/ft_ft_wcsnew.c
        libft/ft_get_next_line.c
        libft/ft_getline.c
        libft/ft_hash_map_ctor.c
        libft/ft_hash_map_dtor.c
        libft/ft_hash_map_get.c
        libft/ft_hash_map_hashcode.c
        libft/ft_hash_map_put_to_map.c
        libft/ft_hash_map_set.c
        libft/ft_hash_map_set_content.c
        libft/ft_imax.c
        libft/ft_imaxabs.c
        libft/ft_imaxdiv.c
        libft/ft_imaxtostr.c
        libft/ft_imin.c
        libft/ft_intrcmp.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isbinary.c
        libft/ft_isdigit.c
        libft/ft_isdigitnstr.c
        libft/ft_isdigitstr.c
        libft/ft_isinf.c
        libft/ft_islower.c
        libft/ft_isnan.c
        libft/ft_ispowerof2.c
        libft/ft_isprint.c
        libft/ft_isspace.c
        libft/ft_isupper.c
        libft/ft_itoa.c
        libft/ft_itostr.c
        libft/ft_keystr_avl_tree_traversal.c
        libft/ft_linedelone.c
        libft/ft_lldiv_mod.c
        libft/ft_lstadd.c
        libft/ft_lstpushback.c
        libft/ft_lstaddtip.c
        libft/ft_lstat.c
        libft/ft_lstcmp_next.c
        libft/ft_lstcontentdel.c
        libft/ft_lstdel.c
        libft/ft_lstdelone.c
        libft/ft_lstfind.c
        libft/ft_lstfind_prev.c
        libft/ft_lstforeach.c
        libft/ft_lstforeach_if.c
        libft/ft_lstiter.c
        libft/ft_lstlast.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_lstremove.c
        libft/ft_lstrev.c
        libft/ft_lstsize.c
        libft/ft_lstswap.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memjoin.c
        libft/ft_memmove.c
        libft/ft_memrcmp.c
        libft/ft_memset.c
        libft/ft_power.c
        libft/ft_powerof2rounddown.c
        libft/ft_powerof2roundup.c
        libft/ft_print_bits.c
#        libft/ft_print_bytes_by_bit.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_fd.c
        libft/ft_putnstr.c
        libft/ft_putnstr_fd.c
        libft/ft_putnwcs.c
        libft/ft_putnwcs_fd.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_putwchar.c
        libft/ft_putwchar_fd.c
        libft/ft_putwcs.c
        libft/ft_putwcs_fd.c
        libft/ft_quicksort.c
        libft/ft_read_file.c
        libft/ft_realloc.c
        libft/ft_realloc_safe.c
        libft/ft_remove_sign_bit.c
        libft/ft_reverse.c
#        libft/ft_set_nth_bit.c
        libft/ft_spskip.c
        libft/ft_str_avl_balance.c
        libft/ft_str_avl_bfactor.c
        libft/ft_str_avl_create.c
        libft/ft_str_avl_del.c
        libft/ft_str_avl_findmin.c
        libft/ft_str_avl_fix_height.c
        libft/ft_str_avl_height.c
        libft/ft_str_avl_insert.c
        libft/ft_str_avl_remove.c
        libft/ft_str_avl_rot_left.c
        libft/ft_str_avl_rot_right.c
        libft/ft_str_avl_search.c
        libft/ft_str_to_intmax.c
        libft/ft_str_to_uintmax.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strchr_no.c
        libft/ft_strclen.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_strint_ou_flow.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strnchr.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnlen.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strrejoin.c
        libft/ft_strrev.c
        libft/ft_strsearch.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtolower.c
#        libft/ft_strtoupper.a
        libft/ft_strtrim.c
        libft/ft_swap.c
        libft/ft_toggle_nth_bit.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/ft_udiv_struc.c
        libft/ft_uimaxdiv.c
        libft/ft_uintmaxtostr.c
        libft/ft_unset_nth_bit.c
        libft/ft_vector_add.c
        libft/ft_vector_delete.c
        libft/ft_vector_free.c
        libft/ft_vector_free_data.c
        libft/ft_vector_get.c
        libft/ft_vector_get_curr.c
        libft/ft_vector_init.c
        libft/ft_vector_resize.c
        libft/ft_vector_set.c
        libft/ft_vector_total.c
        libft/ft_vector_traversal.c
        libft/ft_void_arithm.c
        libft/ft_wclen.c
        libft/ft_wcscpy.c
        libft/ft_wcsdup.c
        libft/ft_wcslen.c
        libft/ft_wcsncpy.c
#        libft/ft_wcsnew.c
        libft/ft_wcsnlen.c
        libft/get_next_line.c
        libft/get_next_line.h
        libft/libft.h
        parser/useless_files/_parser_get_token_code_comment.c
        parser/useless_files/_parser_get_token_precode.c
        parser/prvt_parser_change_state.c
        parser/prvt_parser_get_token_eof.c
        parser/prvt_parser_get_token_init.c
        parser/prvt_parser_get_token_line_end.c
        parser/prvt_parser_get_token_op0_afct.c
        parser/prvt_parser_get_token_op0_arit.c
        parser/prvt_parser_get_token_op0_life.c
        parser/prvt_parser_get_token_op0_load.c
        parser/prvt_parser_get_token_op0_lodi.c
        parser/prvt_parser_get_token_op0_logc.c
        parser/prvt_parser_get_token_op0_stor.c
        parser/prvt_parser_get_token_op0_stri.c
        parser/prvt_parser_get_token_op1_arit.c
        parser/prvt_parser_get_token_op1_load.c
        parser/prvt_parser_get_token_op1_lodi.c
        parser/prvt_parser_get_token_op1_logc.c
        parser/prvt_parser_get_token_op1_stor.c
        parser/prvt_parser_get_token_op1_stri.c
        parser/prvt_parser_get_token_op2_arit.c
        parser/prvt_parser_get_token_op2_lodi.c
        parser/prvt_parser_get_token_op2_logc.c
        parser/prvt_parser_get_token_op2_stri.c
        parser/prvt_parser_xtor.c
        parser/expr.c
        parser/prvt_expr.h
        parser/expr_set_arg.c
        parser/parser.c
        parser/parser_private.h
        parser/parser_singleton_instance.c
        parser/parser_xtor_private.h
        virtual_machine/interfaces/arena.h
#        virtual_machine/interfaces/arguments.h
        virtual_machine/interfaces/carriage.h
#        virtual_machine/interfaces/code.h
        virtual_machine/interfaces/corwar.h
        virtual_machine/interfaces/errors.h
        virtual_machine/interfaces/file.h
        virtual_machine/interfaces/op.h
        virtual_machine/interfaces/operation.h
        virtual_machine/interfaces/player.h
        virtual_machine/interfaces/vm.h
        virtual_machine/interfaces/vm_params.h
        virtual_machine/interfaces/vmp_player.h
#        virtual_machine/interfaces/vmp_state.h
#        virtual_machine/interfaces/type_cut.h
#        virtual_machine/src/arena/player/code/_code.h
#        virtual_machine/src/arena/player/code/code_destroy.c
#        virtual_machine/src/arena/player/code/code_new.c
        virtual_machine/src/arena/player/prvt_player.h
#        virtual_machine/src/arena/player/_player_text_name_from_vmp_player.c
        virtual_machine/src/arena/player/player_destroy.c
        virtual_machine/src/arena/player/player_name.c
        virtual_machine/src/arena/player/player_code.c
        virtual_machine/src/arena/player/player_code_size.c
        virtual_machine/src/arena/player/player_new.c
        virtual_machine/src/arena/player/player_set_name.c
        virtual_machine/src/arena/player/player_introducing.c
        virtual_machine/src/arena/player/player_print_winner.c
        virtual_machine/src/arena/player/player_live_verbosity.c
        virtual_machine/src/arena/arena_get_n_bytes_from.c
        virtual_machine/src/arena/prvt_arena.h
        virtual_machine/src/arena/prvt_arena_players_new.c
        virtual_machine/src/arena/prvt_arena_set_smallest_unoccupied_name.c
#        virtual_machine/src/arena/arena_players.c
        virtual_machine/src/arena/arena_set_last_live_player.c
        virtual_machine/src/arena/arena_nb_players.c
        virtual_machine/src/arena/arena_destroy.c
        virtual_machine/src/arena/arena_new.c
        virtual_machine/src/arena/arena_op_code.c
        virtual_machine/src/arena/arena_print_dump.c
        virtual_machine/src/arena/arena_print_winner.c
        virtual_machine/src/arena/arena_set_unnamed_player.c
        virtual_machine/src/arena/arena_set_named_player.c
        virtual_machine/src/arena/arena_players_introducing.c
        virtual_machine/src/arena/arena_carriage_list_new.c
        virtual_machine/src/arena/arena_write_four_bytes_to_data.c
#        virtual_machine/src/carriage/arguments/_arguments.h
#        virtual_machine/src/carriage/arguments/_arguments_destroy.c
#        virtual_machine/src/carriage/arguments/_arguments_new.c
#        virtual_machine/src/carriage/arguments/arguments_set.c
#        virtual_machine/src/carriage/arguments/arguments_singletone.c
#        virtual_machine/src/carriage/operation/prvt_operation.h
        virtual_machine/src/carriage/operation/operation_dispatched.c
        virtual_machine/src/carriage/operation/operation_precheck_args.c
        virtual_machine/src/carriage/operation/operation_live.c
        virtual_machine/src/carriage/operation/operation_ld.c
        virtual_machine/src/carriage/operation/operation_st.c
        virtual_machine/src/carriage/operation/operation_add.c
        virtual_machine/src/carriage/operation/operation_sub.c
        virtual_machine/src/carriage/operation/operation_and.c
        virtual_machine/src/carriage/operation/operation_or.c
        virtual_machine/src/carriage/operation/operation_xor.c
        virtual_machine/src/carriage/operation/operation_zjmp.c
        virtual_machine/src/carriage/operation/operation_ldi.c
        virtual_machine/src/carriage/operation/operation_sti.c
        virtual_machine/src/carriage/operation/operation_fork.c
        virtual_machine/src/carriage/operation/operation_lld.c
        virtual_machine/src/carriage/operation/operation_lldi.c
        virtual_machine/src/carriage/operation/operation_lfork.c
        virtual_machine/src/carriage/operation/operation_aff.c
#        virtual_machine/src/carriage/operation/op_num_of_args.c
#        virtual_machine/src/carriage/operation/operation_destroy.c
#        virtual_machine/src/carriage/operation/operation_new.c
#        virtual_machine/src/carriage/type_cut/_type_cut.h
#        virtual_machine/src/carriage/type_cut/_type_cut_char.c
#        virtual_machine/src/carriage/type_cut/_type_cut_int.c
#        virtual_machine/src/carriage/type_cut/_type_cut_long_int.c
#        virtual_machine/src/carriage/type_cut/_type_cut_short.c
#        virtual_machine/src/carriage/type_cut/type_cut_dispatched.c
        virtual_machine/src/carriage/prvt_carriage.h
        virtual_machine/src/carriage/prvt_carriage_set_is_correct_op_code.c
        virtual_machine/src/carriage/prvt_carriage_set_op_code.c
        virtual_machine/src/carriage/prvt_carriage_set_cycles_to_perform_op.c
        virtual_machine/src/carriage/carriage_destroy.c
        virtual_machine/src/carriage/carriage_take_step.c
#        virtual_machine/src/carriage/carriage_list_new.c
#        virtual_machine/src/carriage/carriages_check_wins.c
        virtual_machine/src/carriage/carriage_new.c
        virtual_machine/src/carriage/carriage_is_alive.c
        virtual_machine/src/corwar/prvt_corwar.h
#        virtual_machine/src/corwar/corwar.c
        virtual_machine/src/errors/prvt_errors.h
        virtual_machine/src/errors/errors.c
        virtual_machine/src/vm_params/vmp_player/file/prvt_file.h
        virtual_machine/src/vm_params/ft_arg_is_num.c
        virtual_machine/src/vm_params/vmp_player/file/prvt_file_allocate_initial_value.c
        virtual_machine/src/vm_params/vmp_player/file/prvt_file_close.c
#        virtual_machine/src/vm_params/vmp_player/file/_file_get_chunk.c
        virtual_machine/src/vm_params/vmp_player/file/prvt_file_open.c
        virtual_machine/src/vm_params/vmp_player/file/prvt_file_open.c
        virtual_machine/src/vm_params/vmp_player/file/prvt_file_read.c
        virtual_machine/src/vm_params/vmp_player/file/prvt_file_reallocate_value.c
        virtual_machine/src/vm_params/vmp_player/file/file_data_check_valid.c
        virtual_machine/src/vm_params/vmp_player/file/file_data_code.c
        virtual_machine/src/vm_params/vmp_player/file/file_data_comment.c
        virtual_machine/src/vm_params/vmp_player/file/file_code_size.c
#        virtual_machine/src/vm_params/vmp_player/file/file_data_exec_code_size.c
#        virtual_machine/src/vm_params/vmp_player/file/file_data_magic_header.c
        virtual_machine/src/vm_params/vmp_player/file/file_data_name.c
        virtual_machine/src/vm_params/vmp_player/file/file_destroy.c
        virtual_machine/src/vm_params/vmp_player/file/file_new.c
#        virtual_machine/src/vm_params/vmp_player/file/file_total.c
        virtual_machine/src/vm_params/vmp_player/prvt_vmp_player.h
        virtual_machine/src/vm_params/vmp_player/vmp_player_destroy.c
        virtual_machine/src/vm_params/vmp_player/vmp_player_new.c
        virtual_machine/src/vm_params/vmp_player/vmp_player_set_file.c
        virtual_machine/src/vm_params/vmp_player/vmp_player_file.c
        virtual_machine/src/vm_params/vmp_player/vmp_player_name.c
#        virtual_machine/src/vm_params/vmp_state/prvt_vmp_state.h
#        virtual_machine/src/vm_params/vmp_state/_vmp_state_due_to_param.c
#        virtual_machine/src/vm_params/vmp_state/_vmp_state_due_to_state.c
#        virtual_machine/src/vm_params/vmp_state/vmp_state.c
        virtual_machine/src/vm_params/prvt_vm_params.h
        virtual_machine/src/vm_params/prvt_vm_params_add_player_node.c
        virtual_machine/src/vm_params/prvt_vm_params_parse.c
        virtual_machine/src/vm_params/prvt_vm_params_set_file_name_with_id.c
        virtual_machine/src/vm_params/prvt_vm_params_set_file_name_without_id.c
#        virtual_machine/src/vm_params/_vm_params_set_is_dump.c
#        virtual_machine/src/vm_params/_vm_params_set_mock.c
#        virtual_machine/src/vm_params/.c
        virtual_machine/src/vm_params/prvt_vm_params_init.c
        virtual_machine/src/vm_params/prvt_vm_params_flag_name.c
        virtual_machine/src/vm_params/prvt_vm_params_flag_cycles.c
        virtual_machine/src/vm_params/prvt_vm_params_dump_cycles.c
        virtual_machine/src/vm_params/prvt_vm_params_flag_verbose.c
        virtual_machine/src/vm_params/prvt_vm_params_set_player_name.c
        virtual_machine/src/vm_params/prvt_vm_params_add_player_name_node.c
        virtual_machine/src/vm_params/vm_params_destroy_players.c
        virtual_machine/src/vm_params/vm_params_destroy.c
        virtual_machine/src/vm_params/vm_params_named_sorted_array_of_players.c
        virtual_machine/src/vm_params/vm_params_nb_players.c
        virtual_machine/src/vm_params/vm_params_dump_cycles.c
        virtual_machine/src/vm_params/vm_params_verbosity_lvl.c
        virtual_machine/src/vm_params/vm_params_new.c
        virtual_machine/src/prvt_vm.h
        virtual_machine/src/prvt_vm_destroy.c
        virtual_machine/src/prvt_vm_new.c
        virtual_machine/src/vm_play.c
        virtual_machine/src/vm_global_counter.c
        virtual_machine/src/vm_singleton.c
        virtual_machine/src/vm_add_new_carriage_node.c
        virtual_machine/src/vm_increase_num_of_live_ops.c
        virtual_machine/src/vm_num_of_carriages_and_increase.c
        virtual_machine/src/vm_verbosity_lvl.c
        virtual_machine/src/vm_carriage_list_destruct.c
#        virtual_machine/test/main_test.c
#        main_vm.c
        )
