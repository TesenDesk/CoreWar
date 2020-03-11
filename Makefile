# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/15 15:17:26 by jjerde            #+#    #+#              #
#    Updated: 2020/03/11 14:00:20 by cmissy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =====================P̶O̶N̶Y̶ PHONY========================================= #
.PHONY: all clean fclean liba re debug delfile checkdir redebug d rd deljunk \
# ===================== Preferences & Directories ============================ #
NAME =		asm
LABEL =		CoreWar
WORKDIR =	./
LXR_FLDR =	$(WORKDIR)lexer/
PRS_FLDR =	$(WORKDIR)parser/
CHK_FLDR =	$(WORKDIR)checker/
LIBDIR =	$(WORKDIR)libft/
H_DIR_CHK =	$(WORKDIR)checker/
H_DIR_LXR =	$(WORKDIR)lexer/
H_DIR_PRS =	$(WORKDIR)parser/
H_DIR_LIB = $(LIBDIR)
INTERFACE =	$(WORKDIR)interfaces/ 
#H_DIR =		$(H_DIR_CHK) $(H_DIR_LXR) $(H_DIR_PRS) $(H_DIR_LIB)

# ===================== LIBs & Source Files ================================== #
LIB =		$(LIBDIR)libft.a
HEADERS =	## TODO: ADD HEADERS
LXR_FILES =	lexer.c \
			lexer_get_term_ch_name.c \
			lexer_get_term_opx_multy.c \
			lexer_get_term_com_cmd.c \
			token.c \
			lexer_get_term_arg_break.c \
			lexer_get_term_comment.c \
			lexer_singleton_instance.c \
			lexer_get_term_arg_dir.c \
			lexer_get_term_init.c \
			lexer_utils_1.c \
			lexer_get_term_arg_ind.c \
			lexer_get_term_label_word_unit.c \
			lexer_utils_2.c \
			lexer_get_term_arg_reg.c \
			lexer_get_term_line_feed.c \
			lexer_get_term_ch_comment.c \
			lexer_get_term_name_cmd.c \
			lexer_xtor_private.c \
			token_name_init.c
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
CHK_FILES =	label_checker_inclusion_of_maps.c \
			label_checker_put_to_map.c
SRC_LXR =	$(addprefix $(LXR_FLDR), $(LXR_FILES)) #-I$(H_DIR_LXR)
SRC_PRS =	$(addprefix $(PRS_FLDR), $(PRS_FILES)) #-I$(H_DIR_PRS)
SRC_CHK =	$(addprefix $(CHK_FLDR), $(CHK_FILES)) #-I$(H_DIR_CHK)
SRC =		$(SRC_CHK) $(SRC_LXR) $(SRC_PRS)

# ===================== Object files & Comlpiler preferences ================= #
OBJ_LXR =	$(SRC_LXR:.c=.o)
OBJ_PRS =	$(SRC_PRS:.c=.o)
OBJ_CHK =	$(SRC_CHK:.c=.o)
OBJ =		$(OBJ_CHK) $(OBJ_LXR) $(OBJ_PRS)
LIBFLAGS =	-L$(LIBDIR) -lft
CFLAGS =	-Wall -Wextra -Werror

# ===================== COLORS & Co ========================================== #
GREEN =		\033[1;32m
RED =		\033[1;31m
RST =		\033[0m
BOLD =		\033[1m
CYAN =		\033[1;36m
PREFIX =	[$(CYAN)$(LABEL)$(RST)]:\t

# ===================== Debug ================================================ #
# -- WARN! Delete this message from rules if you using library from another prj#
ifeq ($(DEBUGMODE), 1)
	FLAGS		:= $(CFLAGS) -g
	DEBUGMSG	:= $(PREFIX)⚠️ \033[1;33mDebug mode $(GREEN)enabled.$(RST)\n
else
	FLAGS		:= $(CFLAGS)
	DEBUGMSG	:= $(PREFIX)⚠️ \033[1;33mDebug mode $(RED)disabled.$(RST)\n
endif

# ==================== Rules ================================================= #
# --------- Main Rule -------------------------------------------------------- #
all: $(NAME)
	@echo "$(PREFIX)✅ $(GREEN)All files up-to-date or \
rebuilded.$(RST)"

# --------- Object files rules ----------------------------------------------- #
$(CHK_FLDR)%.o: $(CHK_FLDR)%.c
	@printf "%-95c\r$(PREFIX)🕐 Compiling file:\t\t%-25s\r" ' ' "$@"
	@gcc -c -I$(INTERFACE) -I$(H_DIR_CHK) -I$(H_DIR_LIB) -o $@ $< \
#TODO: ADD $(FLAGS)

$(LXR_FLDR)%.o: $(LXR_FLDR)%.c
	@printf "%-95c\r$(PREFIX)🕐 Compiling file:\t\t%-25s\r" ' ' "$@"
	@gcc -c -I$(INTERFACE) -I$(H_DIR_LXR) -I$(H_DIR_LIB) -o $@ $< \
#TODO: ADD $(FLAGS)

$(PRS_FLDR)%.o: $(PRS_FLDR)%.c
	@printf "%-95c\r$(PREFIX)🕐 Compiling file:\t\t%-25s\r" ' ' "$@"
	@gcc -c -I$(INTERFACE) -I$(H_DIR_PRS) -I$(H_DIR_LIB) -o $@ $< \
#TODO: ADD $(FLAGS)

main.o: main.c
	gcc -c -I$(INTERFACE) -I$(H_DIR_CHK) -I$(H_DIR_LXR) -I$(H_DIR_PRS) \
-I$(H_DIR_LIB) -o $@ $< #TODO: ADD $(FLAGS)

lexer: $(OBJ_LXR) l_msg

parser: $(OBJ_PRS) p_msg

checker: $(OBJ_CHK) c_msg

builder: debmsg lexer parser checker

# --------- Exec files rules ------------------------------------------------- #
$(NAME): builder main.o
	@gcc $(FLAGS) $(LIBFLAGS) -o $(NAME) $(OBJ) main.o
	@printf "$(PREFIX)📦  Building $(NAME)...\n"

# --------- Additional messages rules ---------------------------------------- #
l_msg:
	@printf "$(PREFIX)$(BOLD)🔎 Checkig lexer... ✅  $(GREEN)Done!$(RST)%45c\n" ' '

p_msg:
	@printf "$(PREFIX)$(BOLD)🔎 Checkig parser... ✅  $(GREEN)Done!$(RST)%45c\n" ' '

c_msg:
	@printf "$(PREFIX)$(BOLD)🔎 Checkig checker... ✅  $(GREEN)Done!$(RST)%45c\n" ' '

debmsg:
		@printf "$(DEBUGMSG)"

# --------- Libs rules ------------------------------------------------------- #
liba:
		@printf "$(PREFIX)$(BOLD)🔎 Checkig \
for libft updates...$(RST)\n"
		@make -C $(LIBDIR) DEBUGMODE=$(DEBUGMODE)

# --------- Mandatory rules -------------------------------------------------- #
clean: deljunk
		@make -C $(LIBDIR) clean

fclean: clean delfile
		#@make -C $(LIBDIR) dellib

re: fclean
		@make all

# --------- Other rules ------------------------------------------------------ #
delfile:
		@echo "$(PREFIX)♻️ $(RED)Removing executable file...$(RST)"
		@rm -f $(NAME)

deljunk:
		@echo "$(PREFIX)♻️ $(RED)Removing obj-files...$(RST)"
		@rm -f $(OBJ)

debnolib:
		@make nolib DEBUGMODE=1

debug:
		@make all DEBUGMODE=1

d: debug

relib:
		@make -C $(LIBDIR) re DEBUGMODE=1

redebug: fclean debug

rd: redebug

# ===================== End! Thanks for reading! Have a nice day! :) ========= #
