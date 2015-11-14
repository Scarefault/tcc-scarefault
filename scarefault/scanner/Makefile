PARSER_PATH = ../parser/Parserbase.h

lex.cc:
	flexc++ lexer.l

	$(shell echo "// \$$insert class_h" >> Scanner.ih)
	$(shell echo "#include \"Scanner.h\"" >> Scanner.ih)
	$(shell echo "#include \"$(PARSER_PATH)\"" >> Scanner.ih)

clean:
	rm lex.cc Scannerbase.h Scanner.h Scanner.ih
