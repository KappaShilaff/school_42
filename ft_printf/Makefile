all:
	@gcc -fsanitize=address  -g *.c -I./libft/includes -L./libft -lft -o mda
	@gcc -g  *.c -I./libft/includes -L./libft -lft
	@./a.out
clean:
	rm get_next_line.h.gch
	rm a.out
fclean: clean
re: fclean all
