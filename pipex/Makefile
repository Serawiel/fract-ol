NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = libft/
PRINTF_DIR = printf/

LIBFT = $(LIBFT_DIR)libft.a
PRINTF = $(PRINTF_DIR)libftprintf.a

SRCS = main.c pipex.c utils.c init_pipex.c
OBJS = $(SRCS:.c=.o)

INCLUDES = -I$(LIBFT_DIR) -I$(PRINTF_DIR)

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re