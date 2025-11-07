NAME 		:= ft_printf_tester

LIBFT		:= ../libftprintf.a
CC			:= cc
CFLAGS		= -Wall -Wextra -Werror $(INCLUDES)

SRCS		:= srcs/main.c $(wildcard srcs/framework/*.c) $(wildcard srcs/units/*.c)
INCLUDES	:= -Iincludes -I../includes
OBJ_DIR		:= obj
OBJS		:= $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(LIBFT):
	make -C ..

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(NAME).dSYM

re: fclean all

.PHONY: all clean fclean re