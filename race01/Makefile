all: part_of_the_matrix

part_of_the_matrix:
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc -o part_of_the_matrix src/*.c

clean:
	rm -rf part_of_the_matrix

uninstall:
	rm -rf part_of_the_matrix

reinstall:
	make uninstall
	make
