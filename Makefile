# structure
NAME = push_swap
BONUS_NAME = checker

MANDATORY_DIR = mandatory
BONUS_DIR = bonus
CORE_DIR = core

BUILD = build

# flags
CC = cc
CFLAGS = -MMD -MP -Wall -Wextra -Werror $(INCLUDES) $(DEFINES)
MAKEFLAGS += -j $$(nproc)

# files
MANDATORY_SRCS =\
		   main.c\
		   bench.c\
		   debug.c\
		   algorithms/simple.c\
		   algorithms/medium.c\
		   algorithms/complex.c\

BONUS_SRCS =\
		main.c\
		parse_stdin.c\

CORE_SRCS =\
	   operations/push.c\
	   operations/reverse_rotate.c\
	   operations/rotate.c\
	   operations/swap.c\
	   utils/libft/ft_atol.c\
	   utils/libft/ft_dprintf.c\
	   utils/libft/ft_isdigit.c\
	   utils/libft/ft_issign.c\
	   utils/libft/ft_isspace.c\
	   utils/libft/ft_memset.c\
	   utils/libft/ft_strcmp.c\
	   utils/linked_list/list_clear.c\
	   utils/linked_list/list_pop.c\
	   utils/linked_list/list_push.c\
	   parse_input.c\

OBJS = $(MANDATORY_SRCS:%.c=$(BUILD)/%.o)
DEPS = $(OBJS:.o=.d)

VARS = INCLUDES="-I$(MANDATORY_DIR)/includes -I$(CORE_DIR)/includes"\
	   MANDATORY_SRCS="$(addprefix $(MANDATORY_DIR)/srcs/, $(MANDATORY_SRCS)) \
	   $(addprefix $(CORE_DIR)/srcs/, $(CORE_SRCS))"\
	   DEFINES="-DPARSE_STRATEGY=true -DPRINT_OPERATION=true"\
	   NAME="$(NAME)"\

BONUS_VARS = INCLUDES="-I$(BONUS_DIR)/includes -I$(CORE_DIR)/includes"\
		MANDATORY_SRCS="$(addprefix $(BONUS_DIR)/srcs/, $(BONUS_SRCS)) \
		$(addprefix $(CORE_DIR)/srcs/, $(CORE_SRCS))"\
		DEFINES="-DPARSE_STRATEGY=false -DPRINT_OPERATION=false"\
		NAME="$(BONUS_NAME)"\

# rules
ifeq ($(MAKELEVEL),0)

all $(NAME) &:
	@$(MAKE) $(VARS) $(NAME) --no-print-directory

bonus $(BONUS_NAME) &:
	@$(MAKE) $(BONUS_VARS) $(BONUS_NAME) --no-print-directory

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

else

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

$(BUILD)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

endif

# miscellaneous
.PHONY: all bonus clean fclean re
-include $(DEPS)
