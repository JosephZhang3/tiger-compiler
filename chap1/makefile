# 注意 gcc 命令前一定要用tab，而不是4个空格

# define program executions
all : test_AVL_FBBST test_persistentFBST_bind test_persistentFBST main
.PHONY : clean

# test_AVL_FBBST
test_AVL_FBBST : test_AVL_FBBST.o AVL_FBBST.o util.o
	gcc -o test_AVL_FBBST -g test_AVL_FBBST.o AVL_FBBST.o util.o

test_AVL_FBBST.o : test_AVL_FBBST.c AVL_FBBST.h util.h
	gcc -g -c test_AVL_FBBST.c

AVL_FBBST.o : AVL_FBBST.c AVL_FBBST.h util.h
	gcc -g -c AVL_FBBST.c

# test_persistentFBST
test_persistentFBST_bind : test_persistentFBST_bind.o persistentFBST_bind.o util.o
	gcc -o test_persistentFBST_bind -g test_persistentFBST_bind.o persistentFBST_bind.o util.o

test_persistentFBST_bind.o : test_persistentFBST_bind.c persistentFBST_bind.h util.h
	gcc -g -c test_persistentFBST_bind.c

persistentFBST_bind.o : persistentFBST_bind.c persistentFBST_bind.h
	gcc -g -c persistentFBST_bind.c

# test_persistentFBST
test_persistentFBST : test_persistentFBST.o persistentFBST.o util.o
	gcc -o test_persistentFBST -g test_persistentFBST.o persistentFBST.o util.o

test_persistentFBST.o : test_persistentFBST.c persistentFBST.h util.h
	gcc -g -c test_persistentFBST.c

persistentFBST.o : persistentFBST.c persistentFBST.h
	gcc -g -c persistentFBST.c

# main
main : main.o interp.o max_args.o prog1.o slp.o util.o
	gcc -o main -g main.o interp.o max_args.o prog1.o slp.o util.o

main.o : main.c interp.h max_args.h prog1.h
	gcc -g -c main.c

interp.o : interp.c interp.h max_args.h
	gcc -g -c interp.c

max_args.o : max_args.c max_args.h slp.h
	gcc -g -c max_args.c

prog1.o : prog1.c slp.h
	gcc -g -c prog1.c

slp.o : slp.c slp.h util.h
	gcc -g -c slp.c

util.o : util.c util.h
	gcc -g -c util.c

# do clean oprate
clean: 
	del *.exe *.o