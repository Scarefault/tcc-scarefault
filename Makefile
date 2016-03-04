CC = g++
CFLAGS = --std=c++0x -o
OBJS = src/*/*/*.cc # analizer/parser | scanner/*.cc
HEADERS = src/*/*.hpp # generator/*.hpp
IMPS = src/*/*.cpp # generator/*.cpp

all: parse.cc lex.cc scarefault

parse.cc:
	cd src/analizer/parser && $(MAKE)

lex.cc:
	cd src/analizer/scanner && $(MAKE)

scarefault: src/scarefault.cpp
	$(CC) $(CFLAGS) scarefault src/scarefault.cpp $(HEADERS) $(IMPS) $(OBJS)

clean: parser_clean scanner_clean scarefault_clean

parser_clean:
	cd src/analizer/parser && $(MAKE) clean

scanner_clean:
	cd src/analizer/scanner && $(MAKE) clean

scarefault_clean:
	rm scarefault
