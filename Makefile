#################################
#			LIB CONFIG			#
#################################

NAME		:= libftprintf.a
CC			:= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR)

SRCS		:= srcs/ft_printf.c $(wildcard srcs/utils/*.c)
INC_DIR		:= includes

OBJ_DIR		:= obj
OBJ			:= $(SRCS:%.c=$(OBJ_DIR)/%.o)

#################################
#		UNIT TESTS CONFIG		#
#################################

TEST_DIR	:= tests
TEST_SRCS	:= $(wildcard $(TEST_DIR)/srcs/*.c) $(wildcard $(TEST_DIR)/srcs/units/*.c)
TEST_INC_DIR := $(TEST_DIR)/includes
TEST_OBJDIR	:= $(TEST_DIR)/obj
TEST_OBJS	:= $(TEST_SRCS:%.c=$(TEST_OBJDIR)/%.o)
TEST_BIN 	:= $(TEST_DIR)/run_tests

TEST_CFLAGS	:= $(CFLAGS) -I$(TEST_INC_DIR)

#################################
#			RULES - LIB			#
#################################

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

#################################
#		RULES - UNIT TESTS		#
#################################

$(TEST_OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(TEST_CFLAGS) -c $< -o $@

$(TEST_BIN): $(NAME) $(TEST_OBJS)
	$(CC) $(TEST_CFLAGS) -I$(TEST_DIR) \
		-o $(TEST_BIN) $(TEST_OBJS) $(NAME)

test: $(TEST_BIN)
	./$(TEST_BIN) --jobs 1

#################################
#		  RULES - CLEAN			#
#################################

clean:
	rm -rf $(OBJ_DIR) $(TEST_OBJDIR)

fclean: clean
	rm -f $(NAME) $(TEST_BIN)
	rm -rf $(TEST_BIN).dSYM

re: fclean all

.PHONY: all test clean fclean re