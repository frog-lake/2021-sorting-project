OBJS=main.c rand-ints.c sorting-algorithms.c

build: $(OBJS)
	gcc -g -o ../bin/sorting $(OBJS)

test: build
	bash test.sh 1
	bash test.sh 2
	bash test.sh 3

.PHONY: sorter
