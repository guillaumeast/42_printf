NAME		:= libftprintf.a
CC			:= cc
CFLAGS		= -Wall -Wextra -Werror -g3

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

SRCS		:= $(wildcard srcs/*.c)
INCLUDES	:= -I. -Iincludes -I$(LIBFT_DIR)

OBJ_DIR		:= obj
OBJS		:= $(SRCS:%.c=$(OBJ_DIR)/%.o)

TESTS_DIR	:= tests

DEBUG_DIR	:= $(TESTS_DIR)/debug
DEBUG_NAME	:= $(DEBUG_DIR)/debugger
DEBUG_SRCS	:= $(wildcard $(DEBUG_DIR)/*.c)
DEBUG_FLAGS	:= -g3

FUT_DIR		:= $(TESTS_DIR)/fut
FUT_NAME	:= $(FUT_DIR)/tester
FUT_SRCS	:= $(wildcard $(FUT_DIR)/*.c)
FUT_CFLAGS	:= -g3 -lfut

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

bonus: all

debug: re
	$(CC) $(DEBUG_SRCS) $(NAME) $(INCLUDES) $(DEBUG_FLAGS) -o $(DEBUG_NAME)

test: re
	$(CC) $(FUT_SRCS) $(NAME) $(INCLUDES) $(FUT_CFLAGS) -o $(FUT_NAME)
	$(FUT_NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f $(FUT_NAME)
	rm -f $(DEBUG_NAME)
	find . -name "*.dSYM" -type d -exec rm -rf {} +

re: fclean all

.PHONY: all bonus debug test clean fclean re