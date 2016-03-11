CC = g++
CFLAGS = --std=c++0x -o
TARGET_HEADER = ../src/generator/TestGenerator.hpp
TARGET_IMP = ../src/generator/TestGenerator.cpp
TEST_HEADER = catch.hpp
TEST_MAIN = MainTests.cpp
TESTS = */*.cpp

all: test normalize

test:
	$(shell sed -i "1i #define private public" ../src/generator/TestGenerator.hpp)

	$(CC) $(CFLAGS) runAllTest $(TESTS) $(TEST_HEADER) $(TEST_MAIN) $(TARGET_HEADER) $(TARGET_IMP)


normalize:
	$(shell sed -i '1d' ../src/generator/TestGenerator.hpp)

clean:
	rm runAllTest
