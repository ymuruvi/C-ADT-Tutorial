
all: stack.o test.o test

stack.o: stack.c
	gcc -c stack.c

test.o: test.c
	gcc -c test.c

test: stack.o test.o
	gcc stack.o test.o -o test

clean:
	rm -fr stack.o test.o test
