NAME_MAC	= cube3d_mac

NAME_LINUX 	= cube3d_linux

CC		= gcc

CFLAGS	= 

SRCS	= $(wildcard srcs/*.c)


OBJS	= $(SRCS:%.c=%.o)

$(NAME_MAC):$(OBJS)
		make -C ./libs/mlx
		mv ./libs/mlx/libmlx.a ./libmlx.a

		make -C ./libs/Libft
		mv ./libs/Libft/libft.a ./libft.a

		$(CC) $(CFLAGS) $(SRCS) framework OpenGL -framework AppKit libmlx.a libft.a -o $(NAME_MAC)

$(NAME_LINUX):$(OBJS)
		make -C ./libs/mlx
		mv ./libs/mlx/libmlx.a ./libmlx_Linux.a

		make -C ./libs/Libft
		mv ./libs/Libft/libft.a ./libft.a

		$(CC) $(CFLAGS) $(SRCS) libmlx_Linux.a libft.a -L/usr/lib -lXext -lX11 -lm -o $(NAME_LINUX)
all: 	$(NAME_LINUX)

clean:
		make -C ./libs/mlx clean
		rm -rf */*.o libmlx_Linux.a cube3d_linux.o

		make -C ./libs/Libft fclean
		rm -rf */*.o libft.a

		
fclean: clean
		rm -rf cube3d_linux

re: 	fclean all

.PHONY: all clean fclean re
