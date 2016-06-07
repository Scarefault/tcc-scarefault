CC = g++
CFLAGS = --std=c++0x -o
OBJS = src/*/*/*.cc # identifier/(parser|scanner)/*.cc

SRC_S = src/scarefault.cpp
TST_H = src/*/tester/*.hpp
TST_I = src/*/tester/*.cpp
TCS_H = src/*/testcase/*.hpp
TCS_I = src/*/testcase/*.cpp
GEN_H = src/*/value_generator/*.hpp
GEN_I = src/*/value_generator/*.cpp
CLL_H = src/*/collector/*.hpp
CLL_I = src/*/collector/*.cpp
HLP_H = src/helper/*.hpp
HLP_I = src/helper/*.cpp
LOG_H = log/Log.hpp
LOG_I = log/Log.cpp


all: parse.cc lex.cc scarefault

parse.cc:
	cd src/identifier/parser && $(MAKE)

lex.cc:
	cd src/identifier/scanner && $(MAKE)

scarefault:
	$(CC) $(CFLAGS) scarefault $(SRC_S) $(TST_H) $(TST_I) $(TCS_H) $(TCS_I) $(GEN_H) $(GEN_I) $(CLL_H) $(CLL_I) $(HLP_H) $(HLP_I) $(LOG_H) $(LOG_I) $(OBJS)

clean: parser_clean scanner_clean scarefault_clean

parser_clean:
	cd src/identifier/parser && $(MAKE) clean

scanner_clean:
	cd src/identifier/scanner && $(MAKE) clean

scarefault_clean:
	rm scarefault
