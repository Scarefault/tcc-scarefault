all: parser.cc changes_parser.h changes_parser.ih

parser.cc:
	bisonc++ grammar.y -V

changes_parser.h:
	$(shell sed -i "17i \\\t Collector::CollectorFactory * factory;" Parser.h)
	$(shell sed -i "18i \\\t Collector::CollectorBase * collector;" Parser.h)
	$(shell sed -i "19i \\\t LogSystem::Log log;" Parser.h)
	$(shell sed -i "22i \\\t\t explicit Parser(Collector::Language, std::istream &in = std::cin, std::ostream &out = std::cout);" Parser.h)

changes_parser.ih:
	$(shell sed -i "8i Parser::Parser(Collector::Language language,std::istream &in, std::ostream &out)" Parser.ih)
	$(shell sed -i "9i {" Parser.ih)
	$(shell sed -i "10i \\\t d_scanner.switchStreams( in );" Parser.ih)
	$(shell sed -i "11i \\\t d_scanner.setSval(&d_val__);" Parser.ih)
	$(shell sed -i "12i \\\t factory = new Collector::CollectorFactory();" Parser.ih)
	$(shell sed -i "13i \\\t collector = factory->get_collector(language);" Parser.ih)
	$(shell sed -i "14i }" Parser.ih)

clean:
	rm parse.cc Parserbase.h Parser.h Parser.ih
