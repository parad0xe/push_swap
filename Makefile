# structure
NAME = push_swap
BNAME = checker
BUILD = build

# flags
CC = cc
CFLAGS = -MMD -MP -Wall -Wextra -Werror -I $(INCDIR) -g3
MAKEFLAGS += -j $$(nproc)

# files
SRCS =\
   srcs/main.c\
   srcs/operations/push.c\
   srcs/operations/reverse_rotate.c\
   srcs/operations/rotate.c\
   srcs/operations/swap.c\
   srcs/parser/parser.c\
   srcs/utils/libft/ft_atol.c\
   srcs/utils/libft/ft_dprintf.c\
   srcs/utils/libft/ft_isdigit.c\
   srcs/utils/libft/ft_isspace.c\
   srcs/utils/libft/ft_memset.c\
   srcs/utils/libft/ft_strcmp.c\
   srcs/utils/linked_list/list_clear.c\
   srcs/utils/linked_list/list_pop.c\
   srcs/utils/linked_list/list_push.c\
   srcs/utils/linked_list/list_push_new.c\
   srcs/utils/linked_list/node_new.c\
   srcs/debug.c

BSRCS = main.c\

OBJS = $(SRCS:%.c=$(BUILD)/%.o)
DEPS = $(OBJS:.o=.d)

VARS = INCDIR="mandatory/includes" SRCS="$(addprefix mandatory/, $(SRCS))" NAME="$(NAME)"
BVARS = INCDIR="bonus/includes" SRCS="$(addprefix bonus/, $(BSRCS))" NAME="$(BNAME)"

# rules
all $(NAME):
	@mkdir -p $(BUILD)/$(NAME)
	@$(MAKE) $(VARS) build --no-print-directory

bonus $(BNAME):
	@mkdir -p $(BUILD)/$(BNAME)
	@$(MAKE) $(BVARS) build --no-print-directory

build: $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

$(BUILD)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean
	@$(MAKE) all --no-print-directory

# miscellaneous
.PHONY: all bonus build clean fclean re
-include $(DEPS)
