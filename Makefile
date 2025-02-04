NAME = so_long

SRCS = so_long.c \
	   init_map.c \
	   check_map.c \
	   check_map2.c \
	   so_long_error.c \
	   dfs.c \
	   get_next_line.c \
	   get_next_line_utils.c \
	   display_map.c \
	   ft_printf.c \
	   ft_write.c \
	   ft_write2.c \
	   game_exit.c \
	   move_player.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)
	@echo "Make!"

$(NAME): $(OBJS)
	@make -C libft
	@make -C minilibx-linux
	@cc $(CFLAGS) $(OBJS) -o $(NAME) -Llibft -lft -Lminilibx-linux -lmlx -lXext -lX11

clean:
	@make clean -C libft
	@make clean -C minilibx-linux
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME)

re: fclean all

.PHONY:	all	clean	fclean	re
