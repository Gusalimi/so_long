NAME	= so_long
SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
LIB		= libft/libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
MLX		= MLX42/libmlx42.a -lglfw -lm -L "/Users/$$USER/.brew/opt/glfw/lib/"
INC		= MLX42/include
RM		= rm -rf

.c.o:
	$(CC) -c $< $(CFLAGS) -I $(INC) -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB) MLX42/libmlx42.a
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX) -o $(NAME)

MLX42/libmlx42.a:
	$(MAKE) -C MLX42

$(LIB):
	$(MAKE) -C libft

bonus: $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C libft
	$(MAKE) clean -C MLX42

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C MLX42

re:	fclean all

.PHONY: all debug clean fclean
