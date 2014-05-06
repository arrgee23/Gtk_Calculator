cfile = main.c #type with a .c extension

all: 
	gcc $(cfile) calculator.c  -o calculator `pkg-config --cflags --libs gtk+-2.0`
