CC = g++
CFLAGS = --std=c++0x -o
OBJS = */*.cc

all: parser.cc lex.cc scarefault
	
parser.cc:
	cd parser && $(MAKE)

lex.cc:
	cd scanner && $(MAKE)

scarefault: scarefault.cpp
	$(CC) $(CFLAGS) scarefault scarefalt.cpp $(OBJS)

clean: parser_clean scanner_clean scarefault_clean

parser_clean:
	cd parser && $(MAKE) clean

scanner_clean:
	cd scanner && $(MAKE) clean

scarefault_clean:
	rm scarefault
