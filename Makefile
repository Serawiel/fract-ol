NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS_DIR = srcs/
LIBFT_DIR = libft/
PRINTF_DIR = printf/
MLX_DIR = minilibx-linux/
INCLUDES_DIR = includes/
COLORS_DIR = colors/

SRC_FILES = main.c init.c hooks.c draw.c utils.c calcul.c bonus.c
COLORS_FILES = colors.c utils_colors.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC_FILES)) \
       $(addprefix $(COLORS_DIR), $(COLORS_FILES))

OBJS = $(SRCS:.c=.o)

INCLUDES = -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR) -I$(COLORS_DIR)
LIBFT = $(LIBFT_DIR)libft.a
PRINTF = $(PRINTF_DIR)libftprintf.a
MLX = $(MLX_DIR)libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf $(MLX_FLAGS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus