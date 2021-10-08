NAME = fdf

CC = gcc

COPY = cp

RM = rm -f

LIBRARIES = ./libraries

LIBFT = ./libraries/libft

INCLUDES = includes

MINILIBXDIR = ./libraries/minilibx_macos

LINKERS = -L${LIBFT} -lft -L${MINILIBXDIR} -lmlx -framework OpenGL -framework AppKit

ifeq (,$(wildcard ${LIBFT}/libft.a))
	MAKELIBFT = ${MAKE} libft
endif

ifeq (,$(wildcard ${LIBRARIES}/libmlx.a))
	MAKEMINILIBX = ${MAKE} minilibx
endif

CFLAGS = -Wall -Wextra -Werror -I${INCLUDES}

FILES = $(shell find "./sources" -name "*.c")

OBJECTS = ${FILES:.c=.o}

all: ${NAME}

libft:
	${MAKE} -C ${LIBFT} re

minilibx:
	${MAKE} -C ${MINILIBXDIR}
	${COPY} ${MINILIBXDIR}/libmlx.a ${LIBRARIES}


${NAME}: ${OBJECTS}
	${MAKELIBFT}
	${MAKEMINILIBX}
	${CC} ${LINKERS} -o ${NAME} ${OBJECTS}

clean:
	${RM} ${OBJECTS}
	${MAKE} -C ${LIBFT} clean
	${MAKE} -C ${MINILIBXDIR} clean

fclean: clean
	${RM} ${NAME}
	${MAKE} -C ${LIBFT} fclean
	${RM} ${LIBRARIES}/libmlx.a

re:
	${RM} ${OBJECTS}
	${RM} ${NAME}
	${MAKE} all

.PHONY: all clean fclean re

