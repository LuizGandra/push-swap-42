CC := clang
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf

NAME := push_swap
CHECKER := checker

BONUS_DIR := bonus

SRC_DIR := src
OBJ_DIR := build

SRC_DIR_BONUS := $(BONUS_DIR)/src
OBJ_DIR_BONUS := $(BONUS_DIR)/build

LIBFT_DIR := lib/libft
INCLUDE_DIR := include
INCLUDE_DIR_BONUS := $(BONUS_DIR)/include

LIBS := -L$(LIBFT_DIR) -lft

INCLUDES := -I$(INCLUDE_DIR) -I$(LIBFT_DIR)
INCLUDES_BONUS := -I$(INCLUDE_DIR_BONUS) -I$(LIBFT_DIR)

HEADERS := $(INCLUDE_DIR)/push_swap.h
HEADERS_BONUS := $(INCLUDE_DIR_BONUS)/checker_bonus.h

SRCS := \
	main.c \
	error.c \
	load_stack.c \
	push.c \
	reverse_rotate.c \
	rotate.c \
	sort_steps_utils.c \
	sort_steps.c \
	sort.c \
	stack_utils.c \
	stack.c \
	statics.c \
	swap.c \
	utils.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
SRCS_BONUS := \
	main_bonus.c \
	error_bonus.c \
	instructions.c \
	load_stack_bonus.c \
	push_bonus.c \
	reverse_rotate_bonus.c \
	rotate_bonus.c \
	stack_bonus.c \
	stack_utils_bonus.c \
	statics_bonus.c \
	swap_bonus.c \
	utils_bonus.c
SRCS_BONUS := $(addprefix $(SRC_DIR_BONUS)/, $(SRCS_BONUS))

OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
OBJS_BONUS := $(addprefix $(OBJ_DIR_BONUS)/, $(notdir $(SRCS_BONUS:.c=.o)))

VALGRIND := valgrind
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes

GDB := gdb
GDB_FLAGS := -tui -args

all: libft $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

bonus: libft $(OBJ_DIR_BONUS) $(CHECKER)

$(CHECKER): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c $(HEADERS_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES_BONUS)

libft:
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR_BONUS):
	mkdir -p $@

clean:
	$(RM) $(OBJ_DIR) $(OBJ_DIR_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(CHECKER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

vg: all
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(NAME) $(ARGS)

gdb: all
	$(GDB) $(GDB_FLAGS) ./$(NAME) $(ARGS)

norm:
	norminette -R CheckForbiddenSourceHeader

.PHONY: all bonus libft clean fclean re