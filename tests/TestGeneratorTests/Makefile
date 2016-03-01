CC = g++
CFLAGS = --std=c++0x -o
TARGET_HEADER = ../../src/generator/TestGenerator.hpp
TARGET_IMP = ../../src/generator/TestGenerator.cpp
TEST_HEADER = ../catch.hpp
TEST_MAIN = ../MainTests.cpp
TESTS = *.cpp

test:
	$(shell echo "#define private public" >> ../../src/generator/temp_TestGenerator.hpp)
	$(shell cat ../../src/generator/TestGenerator.hpp >> ../../src/generator/temp_TestGenerator.hpp)
	$(shell mv ../../src/generator/temp_TestGenerator.hpp ../../src/generator/TestGenerator.hpp)

	$(CC) $(CFLAGS) runSuiteTest $(TESTS) $(TEST_HEADER) $(TEST_MAIN) $(TARGET_HEADER) $(TARGET_IMP)

normalize:
	$(shell sed -i '1d' ./../../src/generator/TestGenerator.hpp)
