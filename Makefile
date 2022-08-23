NAME	= cube3d

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

SRCS	= $(wildcard srcs/*.c)

OBJS	= $(SRCS:%.c=%.o)

$(NAME):$(OBJS)
		make -C ./libs/mlx
		mv ./libs/mlx/libmlx.a ./libmlx.a

		make -C ./libs/Libft
		mv ./libs/Libft/libft.a ./libft.a

		$(CC) $(CFLAGS) $(SRCS) -framework OpenGL -framework AppKit libmlx.a libft.a -o $(NAME)
all: 	$(NAME)

clean:
		make -C ./libs/mlx clean
		rm -rf */*.o libmlx.a cube3d.o

		make -C ./libs/Libft fclean
		rm -rf */*.o libft.a

		
fclean: clean
		rm -rf cube3d

re: 	fclean all

.PHONY: all clean fclean re
