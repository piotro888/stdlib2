CC := g++
RELEASE_FLAGS := -O3
DEBUG_FLAGS := -g -Wall -Wextra -pedantic -fsanitize=address -fsanitize=undefined -fno-sanitize-recover
FLAGS := 

DEFAULT_GOAL := debug

debug: FLAGS := ${DEBUG_FLAGS}
debug: libstd2.a
release: FLAGS := ${DEBUG_FLAGS} 
release: ${DEBUG_FLAGS}

TARGETS := $(wildcard src/*.cpp)
TARGETOBJS := $(TARGETS:.cpp=.o)

libstd2.a: ${TARGETOBJS}
	@echo "[ARCHIVING TO LIBRARY]"
	ar -rvs build/libstd2.a build/$<
	@echo "    [COMPILED LIBRARY]"

%.o: %.cpp
	@mkdir -p build/src
	@echo "[COMPILING SRC] $<" 
	$(CC) $< -o build/$@ -c -Iinclude/ $(FLAGS) 

clean:
	@echo "Cleaning"
	rm -rf  build

TESTTARG := $(wildcard tests/*.cpp)
TESTOBJS := $(TESTTARG:.cpp=)
TESTOK := 1

test: ${TESTOBJS}
	@echo ***ALL TESTS PASSED***

tests/%: tests/%.cpp libstd2.a
	@mkdir -p build/tests
	@echo "[COMPILING TEST] $<"
	$(CC) $< -o build/$@ -Iinclude/ -Lbuild -lstd2 $(DEBUG_FLAGS)
	@echo "    [TEST RUN] Running test $@"
	@./build/$@ || (echo ***TEST FAILED*** return code: $$? && exit 1)
