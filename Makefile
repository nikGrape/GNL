all: 
	gcc -Werror -Wextra -Wall get_next_line.c -L. -lft
	./a.out
run:
	gcc get_next_line.c -L. -lft
	./a.out

debug:
	gcc -g get_next_line.c -L. -lft
	lldb a.out
check:
	gcc -c -Werror -Wextra -Wall get_next_line.c -L. -lft

re:
	-k -C /nfs/2019/v/vinograd/Desktop/GNL -L /nfs/2019/v/vinograd/Desktop/GNL/libft -lft
