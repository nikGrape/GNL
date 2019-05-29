all:
	gcc -Werror -Wextra -Wall main.c get_next_line.c libft/libft.a -I get_next_line.h
debug:
	gcc -g main.c get_next_line.c libft/libft.a -I get_next_line.h
object:
	gcc -c -Werror -Wextra -Wall get_next_line.c
