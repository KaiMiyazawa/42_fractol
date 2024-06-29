NAME		= fractol
#CC			= clang
CC			= cc
CFLAGS		= -O3 -Wall -Wextra -Werror -I.
#CFLAGS		= -O3 -I.#os update...
#CFLAGS += -g
#CFLAGS += -fsanitize=address
MLX			= libmlx.dylib
MLXFLAG		= -framework OpenGL -framework AppKit
MINILIB     = minilibx_mms_20200219
#CFLAGS		= -Wall -Wextra -Werror -I./minilib_mms_20200219

INCDIR = include/


SRCS = fractol.c ft_atof.c hook.c main.c fractol_utils.c utils.c

OBJS 	= $(SRCS:%.c=%.o)

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -o $@ -c $< -I ${INCDIR} -I $(MINILIB)

$(MLX) :
	cd 	"$(PWD)/$(MINILIB)" && make
	cd 	"$(PWD)/$(MINILIB)" && cp $(MLX) ../$(MLX)

$(NAME) : $(OBJS) $(MLX)
	$(CC) $(OBJS) $(MLX) $(MLXFLAG) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(MINILIB) clean
	rm -rf $(NAME)

re: fclean all

kill_mlx:
	rm -rf $(MLX)
	cd 	"$(PWD)/$(MINILIB)" && rm -f $(MLX)

.PHONY: all clean fclean re kill_mlx