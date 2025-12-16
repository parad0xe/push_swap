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
		   push_swap.c\
		   bench.c\
		   algorithms/simple/simple.c\
		   algorithms/simple/target.c\
		   algorithms/medium/medium-helpers.c\
		   algorithms/medium/medium.c\
		   algorithms/complex.c\

BONUS_SRCS =\
		checker_bonus.c\
		parse_stdin_bonus.c\

CORE_SRCS =\
	   operations/push.c\
	   operations/reverse_rotate.c\
	   operations/rotate.c\
	   operations/swap.c\
	   utils/approximate_sqrt.c\
	   utils/ft_abs.c\
	   utils/ft_atol.c\
	   utils/ft_ceil.c\
	   utils/ft_dprintf.c\
	   utils/ft_isdigit.c\
	   utils/ft_issign.c\
	   utils/ft_isspace.c\
	   utils/ft_memset.c\
	   utils/ft_strcmp.c\
	   utils/get_next_line.c\
	   utils/max.c\
	   linked_list/list_clear.c\
	   linked_list/list_pop.c\
	   linked_list/list_push.c\
	   parse_input.c\

OBJS = $(MANDATORY_SRCS:%.c=$(BUILD)/%.o)
DEPS = $(OBJS:.o=.d)

VARS = INCLUDES="-I$(MANDATORY_DIR)/includes -I$(CORE_DIR)/includes"\
	   MANDATORY_SRCS="$(addprefix $(MANDATORY_DIR)/srcs/, $(MANDATORY_SRCS)) \
	   $(addprefix $(MANDATORY_DIR)/$(CORE_DIR)/srcs/, $(CORE_SRCS))"\
	   DEFINES="-DPARSE_STRATEGY=true -DPRINT_OPERATION=true"\
	   DIR="$(MANDATORY_DIR)"\
	   NAME="$(NAME)"\

BONUS_VARS = INCLUDES="-I$(BONUS_DIR)/includes -I$(CORE_DIR)/includes"\
		MANDATORY_SRCS="$(addprefix $(BONUS_DIR)/srcs/, $(BONUS_SRCS)) \
		$(addprefix $(CORE_DIR)/srcs/, $(CORE_SRCS))"\
		DEFINES="-DPARSE_STRATEGY=false -DPRINT_OPERATION=false"\
		DIR="$(BONUS_DIR)"\
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

$(BUILD)/$(DIR)/$(CORE_DIR)/%.o: $(CORE_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

endif

# miscellaneous
.PHONY: all bonus clean fclean re
-include $(DEPS)
