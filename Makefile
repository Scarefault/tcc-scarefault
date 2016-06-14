CC = g++
CFLAGS = --std=c++0x -o
OBJS = src/*/*/*.cc # identifier/(parser|scanner)/*.cc


SCAREFAULT = src/scarefault.cpp

GEN = src/generator/*/*.hpp src/generator/*/*.cpp

HLP = src/helper/*.hpp src/helper/*.cpp

CLL = src/identifier/collector/*.hpp src/identifier/collector/*.cpp
FLE = src/identifier/file/*.hpp src/identifier/file/*.cpp
IDT = $(CLL) $(FLE)

LOG = log/*.hpp log/*.cpp
SRC = $(GEN) $(HLP) $(IDT)


all: parse.cc lex.cc scarefault

parse.cc:
	cd src/identifier/parser && $(MAKE)

lex.cc:
	cd src/identifier/scanner && $(MAKE)

scarefault:
	$(CC) $(CFLAGS) scarefault $(SCAREFAULT) $(LOG) $(SRC) $(OBJS)

clean: parser_clean scanner_clean scarefault_clean

parser_clean:
	cd src/identifier/parser && $(MAKE) clean

scanner_clean:
	cd src/identifier/scanner && $(MAKE) clean

scarefault_clean:
	rm scarefault
