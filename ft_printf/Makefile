all:
	gcc -fsanitize=address  -g *.c -I./libft/includes -L./libft -lft -o mda
	gcc -g  *.c -I./libft/includes -L./libft -lft
clean:
#	rm get_next_line.h.gch
	rm a.out
fclean: clean
re: fclean all
