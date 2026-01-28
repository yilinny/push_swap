CC = cc
CFLAGS = -Wall -Wextra -Werror

S_NAME = server
S_SRC = server.c
S_OBJ = $(S_SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

HDR = push_swap.h

.PHONY: all bonus clean fclean re

all: $(S_NAME) 

$(S_NAME): $(S_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(S_OBJ) $(LIBFT) -o $@

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(S_OBJ) $(C_OBJ) $(S_BONUS_OBJ) $(C_BONUS_OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(S_NAME) $(C_NAME) $(S_BONUS_NAME) $(C_BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
