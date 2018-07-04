all: afl libfuzzer libfuzzer-unsanitized afl-persistent

afl: fuzzme.cc fuzz_fuzzme_afl.cc
	afl-g++ -O0 -c -g fuzzme.cc -o fuzzme.o
	afl-g++ -O0 -g fuzzme.o fuzz_fuzzme_afl.cc -o demo-afl

afl-persistent: fuzzme.cc fuzz_fuzzme_afl_persistent.cc
	AFL_USE_ASAN=1 afl-clang-fast++ -c -g fuzzme.cc -o fuzzme.o
	AFL_USE_ASAN=1 afl-clang-fast++ -g fuzzme.o fuzz_fuzzme_afl_persistent.cc -o demo-afl-persistent

libfuzzer: fuzzme.cc
	clang++-6.0 -c -fsanitize=address -fsanitize-coverage=trace-pc-guard fuzzme.cc -g -o fuzzme.o
	clang++-6.0 -fsanitize=address,fuzzer fuzzme.o fuzz_fuzzme_libfuzzer.cc -g -o demo-libfuzzer

libfuzzer-unsanitized: fuzzme.cc
	clang++-6.0 -c fuzzme.cc -g -o fuzzme.o
	clang++-6.0 -fsanitize=fuzzer fuzzme.o fuzz_fuzzme_libfuzzer.cc -g -o demo-libfuzzer-unsanitized

PHONY: clean
clean:
	rm -f *.o demo-afl demo-afl-persistent demo-libfuzzer demo-libfuzzer-unsanitized
