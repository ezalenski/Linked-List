qsort: llist.o qsort.c
	gcc qsort.c llist.o -o qsort

msort: llist.o msort.c
	gcc msort.c llist.o -o msort

rsort: llist.o rsort.c
	gcc rsort.c llist.o -o rsort

debug: dllist.o msort.c
	gcc -g msort.c llist.o -o msort

my_tester: llist.o my_tester.c
	gcc ll_tst.c llist.o -o my_tester

llist.o: list.h llist.c
	gcc -c llist.c

dllist.o: list.h llist.c
	gcc -g -c llist.c
