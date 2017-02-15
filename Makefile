NAME=		fdf

CC=			gcc

OS=			$(shell uname)

HOME=		$(shell cat /etc/passwd | grep `id -u -n` | cut -d: -f6)

SRC=		main.c \
			error.c \
			open.c \
			parse.c \
			fdf.c \
			printmap.c \

SRCS=		$(foreach S, $(SRC), src/$(S))

OBJ=		$(SRCS:.c=.o)

CCFLAGS=	-Wall -Werror -Wextra

INCLUDE=	-I include -I libft/includes

LIBS=		-Llibft/ -l ft

ifeq ($(OS), Linux)
	LIBS+=		-L$(HOME)/minilibx -l mlx_Linux -L/usr/include/../lib -lXext -lX11 -lm -lbsd
	INCLUDE+=	-I $(HOME)/minilibx
else
	LIBS+=		-L$(HOME)/minilibx -l mlx
	INCLUDE+=	-I $(HOME)/minilibx
endif

all: lib $(NAME)

lib: 
	@make -C libft/

$(NAME): $(OBJ)
	$(CC) $^ $(LIBS) -o $@ $(INCLUDE)

%.o: %.c
	$(CC) -c $< $(LIBS) -o $@ $(INCLUDE)

clean:
	@make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
