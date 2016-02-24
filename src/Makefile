CC = g++
CFLAGS = --std=c++0x -o
OBJS = */*/*.cc # analizer/parser | scanner/*.cc
HEADERS = */*.hpp # generator/*.hpp
IMPS = */*.cpp # generator/*.cpp

all: parse.cc lex.cc scarefault.out

parse.cc:
	cd analizer/parser && $(MAKE)

lex.cc:
	cd analizer/scanner && $(MAKE)

scarefault.out: scarefault.cpp
	$(CC) $(CFLAGS) scarefault scarefault.cpp $(HEADERS) $(IMPS) $(OBJS)

clean: parser_clean scanner_clean scarefault_clean

parser_clean:
	cd analizer/parser && $(MAKE) clean

scanner_clean:
	cd analizer/scanner && $(MAKE) clean

scarefault_clean:
	rm scarefault
