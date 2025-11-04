NAME		:= libftprintf.a
CC			:= cc
CFLAGS		= -Wall -Wextra -Werror $(addprefix -I, $(INC_DIRS))

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

SRCS		:= $(wildcard srcs/*.c)
INC_DIRS	:= includes $(LIBFT_DIR)

OBJ_DIR		:= obj
OBJ			:= $(SRCS:%.c=$(OBJ_DIR)/%.o)

TEST_NAME	:= ft_printf
TEST_SRC	:= main.c

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

test: $(NAME)
	$(CC) $(CFLAGS) $(TEST_SRC) $(NAME) $(LIBFT) -o $(TEST_NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all test clean fclean re