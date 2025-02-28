CC := clang
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf

NAME := push_swap

SRC_DIR := src
OBJ_DIR := build

INCLUDE_DIR := include
LIBFT_DIR := lib/libft

INCLUDES := -I$(INCLUDE_DIR) -I$(LIBFT_DIR)
LIBS := -L$(LIBFT_DIR) -lft
HEADERS := $(INCLUDE_DIR)/push_swap.h

SRCS := \
	main.c \
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

OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

VALGRIND := valgrind
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes

GDB := gdb
GDB_FLAGS := -tui -args

all: libft $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

libft:
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

vg: all
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(NAME) $(ARGS)

gdb: all
	$(GDB) $(GDB_FLAGS) ./$(NAME) $(ARGS)

norm:
	norminette -R CheckForbiddenSourceHeader

.PHONY: all libft clean fclean re