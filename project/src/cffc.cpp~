#include "parser.h"
#include "readInput.h"

#include <iostream>
#include <fstream>

using namespace std ;

int main ( int argc, char **argv ) {

    if ( argc < 2 ) { // require two or more arguments in command line or else returns error
        cout << "Usage: cffc <filename>" << endl ;
        return 1 ;
    }

    char *filename = argv[1] ; // first argument
    string filepath = "../samples/" + string(filename) ; // sets filepath string with file address
    char *text = readInputFromFile ( filepath.c_str() )  ; // converts filepath to string and 
    if ( ! text ) { // throw error from readInputFromFile failed
        cout << "File \"" << filepath << "\" not found." << endl ;
        return 2 ;
    }

    Parser *p = new Parser() ;
    ParseResult pr = p->parse(text) ;

    if ( ! pr.ok ) { // if returned anything but ok return error
        cout << "Syntax errors in CFishFish program: " << endl
             << pr.errors << endl ;
        return 3 ;
    }


    Program *program = dynamic_cast<Program *>(pr.ast) ;

    if ( ! program ) { // if abstract syntax tree fails return error
        cout << "Internal compiler error, failed to create AST." << endl ;
        return 4 ;
    }

    ofstream machine_h ; // output stream class to operate on files
    machine_h.open ( "../cffc/Machine.h" );
    machine_h << program->cppCode_h() ; // TODO
    machine_h.close();

    ofstream machine_cpp ;
    machine_cpp.open ( "../cffc/Machine.cpp" );
    machine_cpp << program->cppCode_cpp() ; // TODO
    machine_cpp.close();

    return 0;
}

