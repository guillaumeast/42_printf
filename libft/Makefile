#################################
#			LIB CONFIG			#
#################################

NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Mandatory part
SRC			= $(filter-out ft_lst%.c, $(wildcard *.c))
OBJ_DIR		= obj
OBJ			= $(SRC:%.c=$(OBJ_DIR)/%.o)

# Bonus part
BONUS_SRC   = $(wildcard ft_lst*.c)
BONUS_OBJ   = $(BONUS_SRC:%.c=$(OBJ_DIR)/%.o)

#################################
#		UNIT TESTS CONFIG		#
#################################

# Criterion flags (portable: use pkg-config if available)
CRIT_CFLAGS := $(shell pkg-config --cflags criterion 2>/dev/null)
CRIT_LIBS   := $(shell pkg-config --libs   criterion 2>/dev/null)
ifeq ($(CRIT_LIBS),)
CRIT_LIBS := -lcriterion
endif

# Additional flags to improve debugger traces
TEST_CFLAGS	= $(CFLAGS) -g3

TEST_DIR	= tests
TEST_SRCS	= $(wildcard $(TEST_DIR)/mandatory_unit_tests/*.c)
TEST_BONUS	= $(wildcard $(TEST_DIR)/bonus_unit_tests/*.c)
TEST_BIN 	= $(TEST_DIR)/run_tests

#################################
#		  MEMCHECK CONFIG		#
#################################

# OS detection for choosing memcheck command
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
LEAKS_CMD = leaks --atExit -- ./$(MEM_BIN)
else
LEAKS_CMD = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(MEM_BIN) --verbose
endif

# Additional flags to improve memleak traces
MEM_CFLAGS	= $(CFLAGS) -g3

MEM_SRCS	= $(TEST_DIR)/mandatory_memcheck.c
MEM_BONUS	= $(TEST_DIR)/bonus_memcheck.c
MEM_BIN		= $(TEST_DIR)/run_memcheck

#################################
#			RULES - LIB			#
#################################

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME) $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

#################################
#		RULES - UNIT TESTS		#
#################################

test_bin: $(NAME) $(TEST_SRCS)
	$(CC) $(TEST_CFLAGS) $(CRIT_CFLAGS) -I. -I$(TEST_DIR) -o $(TEST_BIN) $(TEST_SRCS) $(NAME) $(CRIT_LIBS)

test_bin_bonus: bonus $(TEST_SRCS) $(TEST_BONUS)
	$(CC) $(TEST_CFLAGS) $(CRIT_CFLAGS) -I. -I$(TEST_DIR) -o $(TEST_BIN) $(TEST_SRCS) $(TEST_BONUS) $(NAME) $(CRIT_LIBS)

test: test_bin
	./$(TEST_BIN)

test_bonus: test_bin_bonus
	./$(TEST_BIN)

#################################
#		 RULES - MEMCHECK		#
#################################

leaks_bin: $(NAME) $(MEM_SRCS)
	$(CC) $(MEM_CFLAGS) -I. -o $(MEM_BIN) $(MEM_SRCS) $(NAME)

leaks_bin_bonus: bonus $(MEM_BONUS)
	$(CC) $(MEM_CFLAGS) -I. -o $(MEM_BIN) $(MEM_BONUS) $(NAME)

leaks: leaks_bin
	$(LEAKS_CMD)

leaks_bonus: leaks_bin_bonus
	$(LEAKS_CMD)

#################################
#		  RULES - CLEAN			#
#################################

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(TEST_BIN) $(MEM_BIN)
	rm -rf $(TEST_BIN).dSYM
	rm -rf $(MEM_BIN).dSYM

re: fclean all

help:
	@echo "Detected OS: $(UNAME_S)"
	@echo "Criterion libs: $(CRIT_LIBS)"
	@echo "Criterion flags: $(CRIT_CFLAGS)"
	@echo
	@echo "Usage: make <target>"
	@echo
	@printf "  %-18s %s\n" "all"           "Build libft.a (mandatory only)"
	@printf "  %-18s %s\n" "bonus"         "Add bonus objects (ft_lst*) to libft.a"
	@printf "  %-18s %s\n" "test"          "Build & run Criterion tests (mandatory)"
	@printf "  %-18s %s\n" "test_bonus"    "Build & run Criterion tests (mandatory + bonus)"
	@printf "  %-18s %s\n" "leaks"         "Build memcheck binary (mandatory) and run leaks (macOS) / valgrind (Linux)"
	@printf "  %-18s %s\n" "leaks_bonus"   "Build memcheck binary (mandatory + bonus) and run leaks (macOS) / valgrind (Linux)"
	@printf "  %-18s %s\n" "clean"         "Remove object files"
	@printf "  %-18s %s\n" "fclean"        "Remove objects and binaries (libft.a, test & memcheck)"
	@printf "  %-18s %s\n" "re"            "fclean + all"

.PHONY: all bonus test_bin test_bin_bonus test test_bonus leaks_bin leaks_bin_bonus leaks leaks_bonus clean fclean re help