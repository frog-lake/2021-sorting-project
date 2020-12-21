OBJS=main.c rand-ints.c sorting-algorithms.c

sorter.exe: $(OBJS)
	gcc $(OBJS)


random: $(OBJS)
	gcc -g -o ../bin/funy $(OBJS)

main: main.c
	gcc -g -o ../bin/main main.c

rm-file:
	rm ../bin/rand
	rm ../bin/main
