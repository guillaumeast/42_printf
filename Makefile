NAME		:= libftprintf.a
CC			:= cc
CFLAGS		= -Wall -Wextra -Werror -g3

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

SRCS		:= $(wildcard srcs/*.c)
INCLUDES	:= -I. -Iincludes -I$(LIBFT_DIR)

OBJ_DIR		:= obj
OBJS		:= $(SRCS:%.c=$(OBJ_DIR)/%.o)

TEST_NAME	:= tests/tester
TEST_SRCS	:= $(wildcard tests/*.c)
TEST_CFLAGS	:= $(INCLUDES) -g3 -lfut

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)
	@mkdir -p $(OBJ_DIR)/libft
	cd $(OBJ_DIR)/libft && ar x ../../$(LIBFT)
	ar rcs $(NAME) $(OBJ_DIR)/libft/*.o

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: re
	$(CC) $(TEST_SRCS) $(NAME) $(TEST_CFLAGS) -o $(TEST_NAME)
	$(TEST_NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all test clean fclean re