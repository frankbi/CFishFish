CXX_DIR = ../lib/cxxtest
CXXTEST = $(CXX_DIR)/cxxtestgen.pl
CXXFLAGS = --error-printer --abort-on-fail --have-eh

FLAGS   = -Wall -g
CFFCDIR = ../cffc

PFILES  =   readInput.o     regex.o     scanner.o   parser.o    \
            parseResult.o   extToken.o  ast.o

cffc:   $(PFILES) cffc.o
	g++ $(FLAGS) -o $(CFFCDIR)/cffc $^


readInput.o:        readInput.cpp   readInput.h
	g++ $(FLAGS) -c readInput.cpp 

regex.o:            regex.cpp       regex.h
	g++ $(FLAGS) -c regex.cpp 

scanner.o:          scanner.cpp     scanner.h   regex.h
	g++ $(FLAGS) -c scanner.cpp 

parser.o:           parser.cpp      parser.h    scanner.h       \
	                extToken.h      ast.h       parseResult.h
	g++ $(FLAGS) -c parser.cpp

parseResult.o:      parseResult.cpp parseResult.h               \
	                ast.h
	g++ $(FLAGS) -c parseResult.cpp

extToken.o:         extToken.cpp    extToken.h  parser.h
	g++ $(FLAGS) -c extToken.cpp

ast.o:              ast.cpp         ast.h
	g++ $(FLAGS) -c ast.cpp

cffc.o:             cffc.cpp        parser.h    readInput.h     \
	                scanner.h       parseResult.h   ast.h
	g++ $(FLAGS) -c cffc.cpp

run-tests:          regex_tests     scanner_tests   parser_tests\
	                ast_tests
	./regex_tests
	./scanner_tests
	./parser_tests
	./ast_tests

regex_tests:        regex_tests.cpp regex.o
	g++ $(FLAGS) -I$(CXX_DIR) -o regex_tests                    \
		$^

regex_tests.cpp:    regex_tests.h
	$(CXXTEST) $(CXXFLAGS)    -o regex_tests.cpp                \
		regex_tests.h

scanner_tests:      scanner_tests.cpp   scanner.o   regex.o     \
			readInput.o
	g++ $(FLAGS) -I$(CXX_DIR) -o scanner_tests                  \
		$^

scanner_tests.cpp:  scanner_tests.h
	$(CXXTEST) $(CXXFLAGS)    -o scanner_tests.cpp              \
		scanner_tests.h

parser_tests:       parser_tests.cpp    $(PFILES)
	g++ $(FLAGS) -I$(CXX_DIR) -o parser_tests                   \
		$^

parser_tests.cpp:   parser_tests.h      $(PFILES)
	$(CXXTEST) $(CXXFLAGS)    -o parser_tests.cpp               \
		parser_tests.h

ast_tests:          ast_tests.cpp       $(PFILES)
	g++ $(FLAGS) -I$(CXX_DIR) -o ast_tests                      \
		$^

ast_tests.cpp:      ast_tests.h         $(PFILES)
	$(CXXTEST) $(CXXFLAGS)    -o ast_tests.cpp                  \
		ast_tests.h

#codeGen_tests:      codeGen_tests.cpp   $(PFILES)
	#g++ $(FLAGS) -I$(CXX_DIR) -o codeGen_tests                  \
		#$^

#codeGen_tests.cpp:  codeGen_tests.h     $(PFILES)
	#$(CXXTEST) $(CXXFLAGS)    -o codeGen_tests.cpp              \
		#codeGen_tests.h

clean:
	rm -Rf                                                      \
		*.o             *.exe                                   \
		regex_tests     regex_tests.cpp                         \
		scanner_tests   scanner_tests.cpp                       \
		parser_tests    parser_tests.cpp                        \
		ast_tests       ast_tests.cpp                           \
		codeGen_tests   codeGen_tests.cpp                       \
		$(CFFCDIR)/cffc $(CFFCDIR)/Machine.h                    \
		$(CFFCDIR)/Machine.cpp
