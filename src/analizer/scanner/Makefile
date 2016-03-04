PARSER_PATH = ../parser/Parserbase.h

all: lex.cc changes_scanner.ih changes_scanner.h

lex.cc:
	flexc++ lexer.l

changes_scanner.ih:
	$(shell echo "// \$$insert class_h" >> Scanner.ih)
	$(shell echo "#include \"Scanner.h\"" >> Scanner.ih)
	$(shell echo "#include \"$(PARSER_PATH)\"" >> Scanner.ih)

changes_scanner.h:
	$(shell sed -i "8i #include \"../parser/Parserbase.h\"" Scanner.h)
	$(shell sed -i "22i \\\t\t\t void setSval(Parser::STYPE__* d_val__);" Scanner.h)
	$(shell sed -i "25i \\\t\t\t Parser::STYPE__* d_val;" Scanner.h)
	$(shell sed -i "38i inline void Scanner::setSval(Parser::STYPE__* d_val__)" Scanner.h)
	$(shell sed -i "39i {" Scanner.h)
	$(shell sed -i "40i \\\t d_val = d_val__;" Scanner.h)
	$(shell sed -i "41i }" Scanner.h)

clean:
	rm lex.cc Scannerbase.h Scanner.h Scanner.ih
