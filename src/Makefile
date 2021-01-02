OBJS=main.c rand-ints.c sorting-algorithms.c

build: $(OBJS)
	gcc -g -o ../bin/sorting $(OBJS)

test: build
	bash test.sh

.PHONY: sorter
