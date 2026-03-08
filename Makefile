CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft

S_NAME = push_swap

S_SRC = alter_summary.c convert_to_rank.c init_summary.c \
		move_small_to_b.c push_swap.c sort_stacks.c stack_utils.c pos_to_top.c final_sort.c

S_OBJ = $(S_SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

HDR = push_swap.h

.PHONY: all clean fclean re

all: $(S_NAME)

$(S_NAME): $(S_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(S_OBJ) $(LIBFT) -o $(S_NAME)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(S_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(S_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all