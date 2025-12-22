NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c \
       push_swap_parsing.c \
       push_swap_parsing2.c \
       push_swap_utilities.c \
       push_swap_utilities2.c \
       push_swap_actions.c \
       push_swap_swap.c \
       push_swap_push.c \
       push_swap_rotate.c \
       push_swap_reverse.c\
       push_swap_index.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re