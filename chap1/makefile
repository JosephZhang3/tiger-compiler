all : test_FBBST test_persistentFBST main
.PHONY : clean

test_FBBST : test_FBBST.o FBBST.o util.o
	gcc -o test_FBBST -g test_FBBST.o FBBST.o util.o

test_FBBST.o : test_FBBST.c FBBST.h util.h
	gcc -g -c test_FBBST.c

FBBST.o : FBBST.c FBBST.h util.h
	gcc -g -c FBBST.c


test_persistentFBST : test_persistentFBST.o persistentFBST.o util.o
	gcc -o test_persistentFBST -g test_persistentFBST.o persistentFBST.o util.o

test_persistentFBST.o : test_persistentFBST.c persistentFBST.h util.h
	gcc -g -c test_persistentFBST.c

persistentFBST.o : persistentFBST.c persistentFBST.h
	gcc -g -c persistentFBST.c


main : main.o max_args.o prog1.o slp.o util.o
	gcc -o main -g main.o max_args.o prog1.o slp.o util.o

main.o : main.c max_args.h prog1.h
	gcc -g -c main.c

max_args.o : max_args.c slp.h
	gcc -g -c max_args.c

prog1.o : prog1.c slp.h
	gcc -g -c prog1.c

slp.o : slp.c slp.h util.h
	gcc -g -c slp.c

util.o : util.c util.h
	gcc -g -c util.c

clean: 
	del *.exe *.o