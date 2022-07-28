CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = inc
LIBNAME = minilibmx.a

SRC = $(SRC_DIR)/*.c

ROOT_OBJS = *.o

OBJS = $(OBJ_DIR)/*.o 

all:
	make MINILIBMX

MINILIBMX:
	mkdir obj
	$(CC) $(CFLAGS) -c $(SRC)
	mv $(ROOT_OBJS) $(OBJ_DIR)
	ar rcs $(LIBNAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -df obj

uninstall:
	make clean
	rm -f $(LIBNAME)

reinstall:
	make uninstall
	make all