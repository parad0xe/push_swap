# structure
NAME = push_swap
BNAME = checker
BUILD = build

# flags
CC = cc
CFLAGS = -MMD -MP -Wall -Wextra -Werror -I $(INCDIR)
MAKEFLAGS += -j $$(nproc)

# files
SRCS = main.c\
BSRCS = main.c\

OBJS = $(SRCS:%.c=$(BUILD)/%.o)
DEPS = $(OBJS:.o=.d)

VARS = INCDIR="$(NAME)/includes" SRCS="$(NAME)/$(SRCS)" NAME="$(NAME)"
BVARS = INCDIR="$(BNAME)/includes" SRCS="$(BNAME)/$(BSRCS)" NAME="$(BNAME)"

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
