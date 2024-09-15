CC = cc
NAME = cube3d

CFLAGS =  -Wall -Wextra -Werror -fsanitize=address -g3
source =   cube.c


obj = $(source:.c=.o)



all:$(NAME)



$(NAME): $(obj)
	$(CC) $(CFLAGS) $(obj) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean	:
	rm -fr $(obj) 
fclean	: clean
	rm -fr $(NAME)

re: fclean all


.SECONDARY : $(obj) 
