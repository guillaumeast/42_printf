#################################
#			LIB CONFIG			#
#################################

NAME		:= libftprintf.a
CC			:= cc
CFLAGS		= -Wall -Wextra -Werror $(addprefix -I, $(INC_DIRS))

SRCS		:= $(wildcard srcs/*.c)
INC_DIRS	:= includes

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
	$(CC) $(TEST_CFLAGS) $(CRIT_CFLAGS) -I$(TEST_DIR) -c $< -o $@

$(TEST_BIN): $(NAME) $(TEST_OBJS)
	$(CC) $(TEST_CFLAGS) $(CRIT_CFLAGS) -I$(TEST_DIR) \
		-o $(TEST_BIN) $(TEST_OBJS) $(NAME) $(CRIT_LIBS)

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