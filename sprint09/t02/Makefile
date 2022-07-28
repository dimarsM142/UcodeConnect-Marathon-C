CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = inc
LIBNAME = minilibmx.a

SRC = $(SRC_DIR)/mx_atoi.c $(SRC_DIR)/mx_isdigit.c $(SRC_DIR)/mx_isspace.c $(SRC_DIR)/mx_printchar.c $(SRC_DIR)/mx_printstr.c $(SRC_DIR)/mx_printint.c $(SRC_DIR)/mx_strcmp.c $(SRC_DIR)/mx_strcpy.c $(SRC_DIR)/mx_strlen.c

ROOT_OBJS = mx_atoi.o mx_isdigit.o mx_isspace.o mx_printchar.o mx_printstr.o mx_printint.o mx_strcmp.o mx_strcpy.o mx_strlen.o

OBJS = $(OBJ_DIR)/mx_atoi.o $(OBJ_DIR)/mx_isdigit.o $(OBJ_DIR)/mx_isspace.o $(OBJ_DIR)/mx_printchar.o $(OBJ_DIR)/mx_printstr.o $(OBJ_DIR)/mx_printint.o $(OBJ_DIR)/mx_strcmp.o $(OBJ_DIR)/mx_strcpy.o $(OBJ_DIR)/mx_strlen.o

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
