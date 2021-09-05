.PHONY: clean
all: main.o ctest/test.o
	gcc main.o ctest/test.o -o ./bin/zyjx
main.o: main.c ctest/test.h
	gcc -I./ -c main.c
ctest/test.o: ctest/test.c ctest/test.h
	gcc -I./ -c ctest/test.c -o ctest/test.o
clean:
	rm -rf ./bin/zyjx  main.o ctest/test.o
