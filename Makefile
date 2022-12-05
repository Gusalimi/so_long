NAME	= so_long
SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
LIB		= libft/libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
MLX		= /Users/gsaile/Cursus/MLX42/libmlx42.a -lglfw -lm -L "/Users/$$USER/.brew/opt/glfw/lib/"
INC		= /Users/gsaile/Cursus/MLX42/include
RM		= rm -rf

.c.o:
	$(CC) -c $< $(CFLAGS) -I $(INC) -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX) -o $(NAME)

$(LIB):
	$(MAKE) -C libft

bonus: $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C libft

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft

re:	fclean all

.PHONY: all debug clean fclean
