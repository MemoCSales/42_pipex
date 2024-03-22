NAME	= pipex

#LIBFT
LIBFT_DIRECTORY  = ./libft/
LIBFT	= $(LIBFT_DIRECTORY)libft.a

OBJ_DIR	= obj/
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

SRC = 	main.c \
		utils.c \
		pipex.c

all: $(NAME)

OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))


$(LIBFT):
		make -C $(LIBFT_DIRECTORY)

$(NAME): $(OBJ) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: %.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -I$(LIBFT_DIRECTORY) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)
		@make clean -C $(LIBFT_DIRECTORY)

fclean: clean
		@rm -f ./$(NAME)
		@rm -f ./$(LIBFT)

re: fclean all

norminette: 
		norminette $(SRC) pipex.h $(LIBFT_DIRECTORY)

.PHONY: all clean fclean re