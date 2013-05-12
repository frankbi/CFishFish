#include "parser.h"

#include <iostream>
#include <fstream>

using namespace std ;

int main () {

	Program *program = dynamic_cast<Program *>(pr.ast) ;

	ofstream test ;
	test.open("tester.txt") ;
	test << program->cppCode_h() ;
	test.close();
	
	return 0 ;
}

