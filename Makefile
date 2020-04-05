### TODO :Insert 42 header here

#======================P̶O̶N̶Y̶ PHONY==========================================#
.PHONY: all clean fclean liba re debug delfile checkdir redebug d rd deljunk \
		makevisual

#======================Folders & Files=========================================#
NAME        :=  corewar
MAIN        :=  main.c
LABEL       :=	CoreWar
WORKDIR     :=  ./
LIBDIR      :=	$(WORKDIR)libft/
HEADERDIR   :=	$(WORKDIR)#includes/
LIB         :=  $(LIBDIR)libft.a
LEX_SRC     :=	lexer_get_term_name_cmd.c \
				lexer_get_term_ch_name.c \
				lexer_get_term_com_cmd.c \
				lexer_get_term_comment.c \
				lexer.c \
				lexer_utils_1.c \
				lexer_utils_2.c \
				lexer_get_term_init.c \
				lexer_singleton_instance.c \
				lexer_get_term_opx_multy.c \
				lexer_get_term_arg_dir.c \
				lexer_get_term_arg_ind.c \
				lexer_get_term_arg_break.c \
				lexer_get_term_ch_comment.c \
				lexer_get_term_line_feed.c \
				lexer_get_term_arg_reg.c \
				token.c \
				lexer_xtor_private.c
LEX_OBJ     :=  $(patsubst %.c, %.o, $(LEX_SRC))
LEX_DIR_OBJ :=  $(addprefix ./lexer/, $(LEX_OBJ))
PRS_FILES =	_parser_change_state.c \
			_parser_get_token_op0_load.c \
			_parser_get_token_op1_lodi.c \
			_parser_get_token_op2_stri.c \
			_parser_get_token_eof.c \
			_parser_get_token_op0_lodi.c \
			_parser_get_token_op1_logc.c \
			expr.c \
			_parser_get_token_init.c \
			_parser_get_token_op0_logc.c \
			_parser_get_token_op1_stor.c \
			_parser_xtor.c \
			_parser_get_token_line_end.c \
			_parser_get_token_op0_stor.c \
			_parser_get_token_op1_stri.c \
			_parser_get_token_op0_afct.c \
			_parser_get_token_op0_stri.c \
			_parser_get_token_op2_arit.c \
			_parser_get_token_op0_arit.c \
			_parser_get_token_op1_arit.c \
			_parser_get_token_op2_lodi.c \
			expr_set_arg.c \
			_parser_get_token_op0_life.c \
			_parser_get_token_op1_load.c \
			_parser_get_token_op2_logc.c \
			parser.c \
			parser_singleton_instance.c
PARS_OBJ     :=  $(patsubst %.c, %.o, $(PARS_SRC))
PARS_DIR_OBJ :=  $(addprefix ./parser/, $(PARS_OBJ))
CFLAGS      :=  -Wall -Wextra -Werror -g
LIBFLAGS    :=  -L$(LIBDIR) -lft
HEADER      :=  $(HEADERDIR)ms.h
INTERFACE =	$(WORKDIR)interfaces/

#======================COLORS & Co=============================================#
GREEN =		\033[1;32m
RED =		\033[1;31m
RST =		\033[0m
BOLD =		\033[1m
CYAN =		\033[1;36m
PREFIX =	[$(CYAN)$(LABEL)$(RST)]:\t

#======================Debug & Flags===========================================#
# -- WARN! Delete this message from rules if you using library from another prj#
ifeq ($(DEBUGMODE), 1)
	FLAGS		:= $(CFLAGS)
	DEBUGMSG	:= $(PREFIX)⚠️  \033[1;33mDebug mode $(GREEN)enabled.$(RST)\n
else
	FLAGS		:= #$(CFLAGS)
	DEBUGMSG	:= $(PREFIX)⚠️  \033[1;33mDebug mode $(RED)disabled.$(RST)\n
endif
MLX_FLAGS		:= -L./minilibx -lmlx  -framework OpenGL -framework AppKit

#======================Rules===================================================#

all: debmsg $(NAME) ##Todo: Add 'liba' rule BEFORE '$(NAME)'
		@echo "$(PREFIX)✅  $(GREEN)All files up-to-date or \
rebuilded.$(RST)"

debmsg:
		@printf "$(DEBUGMSG)"

# $(NAME): $(LEX_DIR_OBJ) $(PARS_DIR_OBJ) $(MAIN) $(LIB)
# 		@printf "$(PREFIX)📦  Building $(NAME)...\n"
# 		@printf "Building $(LEX_DIR_OBJ).$(LEX_OBJ).\n"
#
#
# #		@gcc $(FLAGS) -o $(NAME) $(LEX_DIR_SRC) $(LIBFLAGS) -I$(HEADERDIR)
# 		# @cc $(FLAGS) -o $(NAME) $(LEX_DIR_SRC) $(MLX_FLAGS) -I$(HEADERDIR) ##todo: add '$(LIBFLAGS)'
# 		@cc $(CFLAGS)  -o $@ $^ -I$(HEADERDIR) $(LIBFLAGS)
#
# $(LEX_DIR_OBJ): %.o:  %.c
# 		@cc -c $(FLAGS)  $< -o $@
#
# $(PARS_DIR_OBJ): %.o: %.c
# 		@cc -c $(FLAGS)  $< -o $@

$(NAME): $(LEX_DIR_OBJ) $(PARS_DIR_OBJ) $(MAIN) $(LIB)
		@printf "$(PREFIX)📦  Building $(NAME)...\n"
		@printf "Building $(LEX_DIR_OBJ).$(LEX_OBJ).\n"


#		@gcc $(FLAGS) -o $(NAME) $(LEX_DIR_SRC) $(LIBFLAGS) -I$(HEADERDIR)
		# @cc $(FLAGS) -o $(NAME) $(LEX_DIR_SRC) $(MLX_FLAGS) -I$(HEADERDIR) ##todo: add '$(LIBFLAGS)'
		gcc $(CFLAGS)  -o $@ $^ -I$(HEADERDIR) $(LIBFLAGS) -I$(INTERFACE)

$(LEX_DIR_OBJ): %.o:  %.c
		gcc -c $(FLAGS)  -I$(INTERFACE) $(LIBFLAGS) $<  -o $@

$(PARS_DIR_OBJ): %.o: %.c
		gcc -c $(FLAGS) -I$(INTERFACE) $(LIBFLAGS)  $<  -o $@

# $(PARS_DIR_OBJ): %.o:  %.c
# 		@cc -c $(FLAGS)  $< -o $@

$(LIB):
		make -C libft/

# libfliba:
# 	libfliba	@printf "$(PREFIX)$(BOLD)🔎  Checkig \
# for libf up-to-dateates...$(RST)\n"
# 		@make -C $(LIBDIR) DEBUGMODE=$(DEBUGMODE)

clean: deljunk
		rm -rf lexer/*.o
		@make -C $(LIBDIR) clean

delfile:
		@echo "$(PREFIX)♻️  $(RED)Removing executable file...$(RST)"
		@rm -f $(NAME)

fclean: clean delfile
		#@make -C $(LIBDIR) dellib

re: fclean
		@make all
