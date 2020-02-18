### TODO :Insert 42 header here

#======================P̶O̶N̶Y̶ PHONY==========================================#
.PHONY: all clean fclean liba re debug delfile checkdir redebug d rd deljunk \
		makevisual

#======================Folders & Files=========================================#
NAME        :=  corewar
MAIN        :=  main.c
LABEL       :=	CoreWar
WORKDIR     :=  ./
LIBDIR      :=	$(WORKDIR)libf/
HEADERDIR   :=	$(WORKDIR)#includes/
LIB         :=  $(LIBDIR)libft.a
LEX_SRC     :=	lexer_get_term_ch_name.c lexer_get_term_name_cmd.c \
				lexer_get_term_com_cmd.c lexer.c lexer_get_term_comment.c \
				lexer_utils_1.c lexer_get_term_init.c lexer_utils_2.c lexer_singleton_instance.c \
				lexer_get_term_opx_multy.c lexer_get_term_arg_ind.c lexer_get_term_arg_break.c \
				lexer_get_term_ch_comment.c lexer_get_term_arg_reg.c lexer_get_term_line_feed.c \
				lexer_get_term_arg_dir.c token.c
LEX_OBJ     :=  $(patsubst %.c, %.o, $(LEX_SRC))
LEX_DIR_OBJ :=  $(addprefix ./lexer/, $(LEX_OBJ))
CFLAGS      :=  -Wall -Wextra -Werror -g
LIBFLAGS    :=  -L$(LIBDIR) -lft
HEADER      :=  $(HEADERDIR)ms.h

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

$(NAME): $(LEX_DIR_OBJ) $(MAIN) $(LIB)
		@printf "$(PREFIX)📦  Building $(NAME)...\n"
		@printf "Building $(LEX_DIR_OBJ).$(LEX_OBJ).\n"


#		@gcc $(FLAGS) -o $(NAME) $(LEX_DIR_SRC) $(LIBFLAGS) -I$(HEADERDIR)
		# @cc $(FLAGS) -o $(NAME) $(LEX_DIR_SRC) $(MLX_FLAGS) -I$(HEADERDIR) ##todo: add '$(LIBFLAGS)'
		@cc $(CFLAGS)  -o $@ $^ -I$(HEADERDIR) $(LIBFLAGS)

$(LEX_DIR_OBJ): %.o:  %.c
		@cc -c $(FLAGS)  $< -o $@

$(LIB):
		make -C libf/

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
