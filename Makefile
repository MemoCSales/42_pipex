NAME	= pipex

#LIBFT
LIBFT_DIRECTORY  = ./libft/
LIBFT	= $(LIBFT_DIRECTORY)libft.a

#SUPPORT_FILES
SUPPORT_DIR = ./support/
SUPPORT = $(SUPPORT_DIR)/support.a

OBJ_DIR	= obj/
OBJ_DIR_BONUS = obj_bonus/
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

SRC = 	main.c \
		utils.c \
		utils_2.c \
		pipex.c	\

SRC_BONUS = main_bonus.c \
			utils_bonus.c \
			utils_bonus_2.c \

all: $(NAME)

OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))

OBJ_BONUS = $(patsubst %.c, $(OBJ_DIR_BONUS)%.o, $(SRC_BONUS))


$(LIBFT):
		make -C $(LIBFT_DIRECTORY)

$(SUPPORT):
		make -C $(SUPPORT_DIR)

$(NAME): $(OBJ) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
			@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

$(OBJ_DIR)%.o: %.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -I$(LIBFT_DIRECTORY) -c $< -o $@

$(OBJ_DIR_BONUS)%.o: %.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -I$(LIBFT_DIRECTORY) -I$(SUPPORT_DIR) -c $< -o $@

bonus:		$(OBJ_BONUS) $(LIBFT) $(SUPPORT)
			$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(SUPPORT) -o $(NAME)
			@echo "$(GREEN)$(NAME) bonus created!$(DEFAULT)"

clean:
		rm -rf $(OBJ_DIR)
		rm -rf $(OBJ_DIR_BONUS)
		@make clean -C $(LIBFT_DIRECTORY)
		@make clean -C $(SUPPORT_DIR)
		@echo "$(YELLOW)Object files deleted!$(DEFAULT)"

fclean: clean
		@rm -f ./$(NAME)
		@rm -f ./$(LIBFT)
		@rm -f ./$(SUPPORT)
		@echo "$(RED)All files deleted!$(DEFAULT)"

re: fclean all

norminette: 
		norminette $(SRC) $(SUPPORT_DIR) pipex.h $(LIBFT_DIRECTORY)

.PHONY: all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m