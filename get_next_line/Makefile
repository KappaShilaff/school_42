all:
	clear
	gcc -g -fsanitize=address get_next_line.c get_next_line.h main.c -I./libft/includes -L./libft -lft
	./a.out
clean:
	rm get_next_line.h.gch
	rm a.out
fclean: clean
re: fclean all
