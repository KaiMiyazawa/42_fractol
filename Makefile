NAME = fractol
INCDIR = include/
SRC = fractol.c ft_atof.c hook.c main.c fractol_utils.c utils.c
OBJ = ${SRC:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -Imlx -o $@ -c $< -I ${INCDIR}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} $(OBJ) -L /usr/X11R6/lib -lmlx -lXext -lX11 -framework OpenGL -framework AppKit -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re