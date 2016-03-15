CC = g++
CFLAGS = --std=c++0x -o
OBJS = src/*/*/*.cc # analizer/(parser|scanner)/*.cc

SRC_S = src/scarefault.cpp
SRC_H = src/*/*.hpp
SRC_I = src/*/*.cpp
LOG_H = log/Log.hpp
LOG_I = log/Log.cpp


all: parse.cc lex.cc scarefault

parse.cc:
	cd src/analizer/parser && $(MAKE)

lex.cc:
	cd src/analizer/scanner && $(MAKE)

scarefault:
	$(CC) $(CFLAGS) scarefault $(SRC_S) $(SRC_H) $(SRC_I) $(LOG_H) $(LOG_I) $(OBJS)

clean: parser_clean scanner_clean scarefault_clean

parser_clean:
	cd src/analizer/parser && $(MAKE) clean

scanner_clean:
	cd src/analizer/scanner && $(MAKE) clean

scarefault_clean:
	rm scarefault
