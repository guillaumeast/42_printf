#################################
#			LIB CONFIG			#
#################################

NAME		:= libftprintf.a
CC			:= cc
CFLAGS		= -Wall -Wextra -Werror $(addprefix -I, $(INC_DIRS))

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

SRCS		:= $(wildcard srcs/*.c)
INC_DIRS	:= includes $(LIBFT_DIR)

OBJ_DIR		:= obj
OBJ			:= $(SRCS:%.c=$(OBJ_DIR)/%.o)

#################################
#		UNIT TESTS CONFIG		#
#################################

# Criterion flags (portable: use pkg-config if available)
CRIT_CFLAGS	:= $(shell pkg-config --cflags criterion 2>/dev/null)
CRIT_LIBS	:= $(shell pkg-config --libs   criterion 2>/dev/null)
ifeq ($(CRIT_LIBS),)
CRIT_LIBS	:= -lcriterion
endif

# Additional flags to improve debugger traces
TEST_CFLAGS	:= $(CFLAGS) -g3

TEST_DIR	:= tests
TEST_SRCS	:= $(wildcard $(TEST_DIR)/*.c)
TEST_OBJDIR	:= $(TEST_DIR)/obj
TEST_OBJS	:= $(TEST_SRCS:%.c=$(TEST_OBJDIR)/%.o)
TEST_BIN 	:= $(TEST_DIR)/run_tests

#################################
#			RULES - LIB			#
#################################

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

#################################
#		RULES - UNIT TESTS		#
#################################

$(TEST_OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(TEST_CFLAGS) $(CRIT_CFLAGS) -I$(TEST_DIR) -c $< -o $@

$(TEST_BIN): $(NAME) $(TEST_OBJS)
	$(CC) $(TEST_CFLAGS) $(CRIT_CFLAGS) -I$(TEST_DIR) \
		-o $(TEST_BIN) $(TEST_OBJS) $(NAME) $(LIBFT) $(CRIT_LIBS)

test: $(TEST_BIN)
	./$(TEST_BIN) --jobs 1

#################################
#		  RULES - CLEAN			#
#################################

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR) $(TEST_OBJDIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(TEST_BIN)
	rm -rf $(TEST_BIN).dSYM

re: fclean all

.PHONY: all test clean fclean re