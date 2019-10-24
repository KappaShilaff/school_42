all:
	gcc -fsanitize=address  -g get_next_line.c get_next_line.h main.c -I./libft/includes -L./libft -lft -o mda
	gcc -g  get_next_line.c get_next_line.h main.c -I./libft/includes -L./libft -lft
	./a.out test_data | wc
	./bench test_data | wc
	./a.out dudos.txt | wc
	./bench dudos.txt | wc
	./a.out mnog_n | wc
	./bench mnog_n | wc
	./mda Makefile
clean:
	rm get_next_line.h.gch
	rm a.out
fclean: clean
re: fclean all
