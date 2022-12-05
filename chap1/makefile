a.out: main.o max_args.o prog1.o slp.o util.o
	gcc -g main.o max_args.o prog1.o slp.o util.o

main.o: main.c max_args.h prog1.h
	gcc -g -c main.c

max_args.o: max_args.c slp.h
	gcc -g -c max_args.c

prog1.o: prog1.c slp.h
	gcc -g -c prog1.c

slp.o: slp.c slp.h util.h
	gcc -g -c slp.c

util.o: util.c util.h
	gcc -g -c util.c

clean: 
	del a.exe *.o