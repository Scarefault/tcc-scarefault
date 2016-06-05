all: parser.cc changes_parser.h changes_parser.ih

parser.cc:
	bisonc++ grammar.y -V

changes_parser.h:
	$(shell sed -i "17i \\\t Collector::CollectorBase * collector;" Parser.h)
	$(shell sed -i "18i \\\t LogSystem::Log log;" Parser.h)
	$(shell sed -i "21i \\\t\t explicit Parser(Collector::Language, std::istream &in = std::cin, std::ostream &out = std::cout);" Parser.h)

changes_parser.ih:
	$(shell sed -i "8i Parser::Parser(Collector::Language language,std::istream &in, std::ostream &out)" Parser.ih)
	$(shell sed -i "9i {" Parser.ih)
	$(shell sed -i "10i \\\t d_scanner.setSval(&d_val__);" Parser.ih)
	$(shell sed -i "11i \\\t collector = Collector::CollectorBase::get_collector(language);" Parser.ih)
	$(shell sed -i "12i }" Parser.ih)

clean:
	rm parse.cc Parserbase.h Parser.h Parser.ih
