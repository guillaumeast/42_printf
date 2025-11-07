NAME		:= libftprintf.a
CC			:= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR)

SRCS		:= srcs/ft_printf.c $(wildcard srcs/utils/*.c)
INC_DIR		:= includes

OBJ_DIR		:= obj
OBJS		:= $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all test clean fclean re