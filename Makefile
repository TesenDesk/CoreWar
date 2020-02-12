### TODO :Insert 42 header here

#======================P̶O̶N̶Y̶ PHONY==========================================#
.PHONY: all clean fclean liba re debug delfile checkdir redebug d rd deljunk \
		makevisual

#======================Folders & Files=========================================#
NAME =		corewar
LABEL =		CoreWar
WORKDIR =	./
LIBDIR =	$(WORKDIR)libft/
HEADERDIR =	$(WORKDIR)#includes/
LIB =		$(LIBDIR)libft.a
SRC =		lexer_get_term_ch_name.c lexer_get_term_name_cmd.c main.c \
			lexer_get_term_com_cmd.c lexer.c lexer_get_term_comment.c \
			lexer_utils_1.c token.c lexer_get_term_init.c lexer_utils_2.c\
			lexer_get_term_opx.c lexer_get_term_arg_ind.c lexer_get_term_arg_break.c\

CFLAGS =	-Wall -Wextra -Werror
LIBFLAGS =	-L$(LIBDIR) -lft
HEADER =	$(HEADERDIR)ms.h

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
	FLAGS		:= $(CFLAGS) -g
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

$(NAME): $(SRC) #$(HEADER)
		@printf "$(PREFIX)📦  Building $(NAME)...\n"
#		@gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFLAGS) -I$(HEADERDIR)
		# @cc $(FLAGS) -o $(NAME) $(SRC) $(MLX_FLAGS) -I$(HEADERDIR) ##todo: add '$(LIBFLAGS)'
		@cc $(FLAGS) -o $(NAME) $(SRC) -I$(HEADERDIR) $(LIBFLAGS)

liba:
		@printf "$(PREFIX)$(BOLD)🔎  Checkig \
for libft updates...$(RST)\n"
		#@make -C $(LIBDIR) DEBUGMODE=$(DEBUGMODE)

clean: deljunk
		#@make -C $(LIBDIR) clean

delfile:
		@echo "$(PREFIX)♻️  $(RED)Removing executable file...$(RST)"
		@rm -f $(NAME)

fclean: clean delfile
		#@make -C $(LIBDIR) dellib

re: fclean
		@make all
