all: fuzz-target-parse fuzz-target-multiply

fuzz-target-parse: lib-static solution_parse_command.c
	AFL_HARDEN=1 afl-gcc solution_parse_command.c libtest.a -o fuzz-target-parse

fuzz-target-multiply: lib-static solution_optimized_multiply.c
	AFL_HARDEN=1 afl-gcc solution_optimized_multiply.c libtest.a -o fuzz-target-multiply

lib-static: mylibrary.c
	AFL_HARDEN=1 afl-gcc -c mylibrary.c -o mylibrary.o
	ar rcs libtest.a mylibrary.o

lib-shared: mylibrary.c
	AFL_HARDEN=1 afl-gcc -fPIC -shared mylibrary.c -o libMylib.so

PHONY: clean
clean:
	rm -f fuzz-target-* *.o *.a *.so