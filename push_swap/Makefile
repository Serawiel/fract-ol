NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS_DIR = srcs/
OPS_DIR = operations/
LIBFT_DIR = libft/
PRINTF_DIR = printf/
INCLUDES_DIR = includes/

SRC_FILES = main.c utils.c check_args.c create_stack.c sort.c update_in_b.c median.c optimize.c
OPS_FILES = push.c rotation.c rrotation.c swap.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC_FILES)) \
       $(addprefix $(SRCS_DIR)$(OPS_DIR), $(OPS_FILES))

OBJS = $(SRCS:.c=.o)

INCLUDES = -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

LIBFT = $(LIBFT_DIR)libft.a
PRINTF = $(PRINTF_DIR)libftprintf.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re