CC = g++
CFLAGS = --std=c++0x -o
OBJS = */*.cc

all: parser.cc lexer.cc scarefault
	
parser.cc:
	cd parser && $(MAKE)

lexer.cc:
	cd scanner && $(MAKE)

scarefault: scarefault.cpp
	$(CC) $(CFLAGS) scarefault scarefault.cpp $(OBJS)

clean: parser_clean scanner_clean scarefault_clean

parser_clean:
	cd parser && $(MAKE) clean

scanner_clean:
	cd scanner && $(MAKE) clean

scarefault_clean:
	rm scarefault
