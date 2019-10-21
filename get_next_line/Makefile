all:
	gcc -fsanitize=address  -g get_next_line.c get_next_line.h main.c -I./libft/includes -L./libft -lft -o mda
	gcc  get_next_line.c get_next_line.h main.c -I./libft/includes -L./libft -lft
clean:
	rm get_next_line.h.gch
	rm a.out
lol:
	./a.out Makefile
fclean: clean
re: fclean all
