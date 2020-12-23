OBJS=main.c rand-ints.c sorting-algorithms.c

build: $(OBJS)
	gcc -g -o ../bin/sorting $(OBJS)

test: build
	echo quicksort
	bash test.sh 2
	echo mergesort
	bash test.sh 3

.PHONY: sorter
