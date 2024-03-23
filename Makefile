NAME	= pipex

#LIBFT
LIBFT_DIRECTORY  = ./libft/
LIBFT	= $(LIBFT_DIRECTORY)libft.a

OBJ_DIR	= obj/
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

SRC = 	main.c \
		utils.c \
		utils_2.c \
		pipex.c	\

all: $(NAME)

OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))


$(LIBFT):
		make -C $(LIBFT_DIRECTORY)

$(NAME): $(OBJ) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
			@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

$(OBJ_DIR)%.o: %.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -I$(LIBFT_DIRECTORY) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)
		@make clean -C $(LIBFT_DIRECTORY)
		@echo "$(YELLOW)Object files deleted!$(DEFAULT)"

fclean: clean
		@rm -f ./$(NAME)
		@rm -f ./$(LIBFT)
		@echo "$(RED)All files deleted!$(DEFAULT)"

re: fclean all

norminette: 
		norminette $(SRC) pipex.h $(LIBFT_DIRECTORY)

.PHONY: all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m