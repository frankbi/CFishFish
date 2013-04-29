#include <cxxtest/TestSuite.h>

#include "readInput.h"
#include "scanner.h"
#include "extToken.h"
#include "parser.h"
#include "parseResult.h"
// One of the above has likely included the .h file with your
// definition of the Node and Program class.  It is not named
// here so that you can name your files as you see fit.

using namespace std ;

class AstTestSuite : public CxxTest::TestSuite
{
public:
    int DEBUG ;

    Scanner *s ;
    Parser *p ;
    void test_setup_code ( ) {
        s = new Scanner() ;
        p = new Parser() ;
        DEBUG = 0 ;
    }

    /*
    When we wrote the tests, we actually already had a few parse functions completed. But after we wrote our tests,
    we noticed that the tests were failing because the program name was returning a semicolon instead of the
    program name. We thought currToken was the last match when it was actually prevToken that was needed -- we fixed
    that in our exisitng parse functions.

    When I was looking at the squareMapper test to write the other three tests, I notcied that the toGoto member in the transition class
    did not count as a variableUse, therefore, we had to go back and change the class definition so that it was a string instead of an
    instance of variableUse.

    After we fixed our class definition, we completed our parse functions and finished writing our tests, we ran the tests
    but to our surprise, they failed. The error returned showed that the number counted for variableUses in each test
    was off by a few. To remedy that, we went through the sample programs and recounted the number of variableUses
    and found that we had miscounted. The number of variableUses that the program returned was in fact correct.

	Note: there is more text below
    */



	void test_ast_box ( ) {
		string file = "../samples/box.cff" ;
		const char *text = readInputFromFile ( file.c_str() ) ;
		TS_ASSERT ( text );

		ParseResult pr = p->parse ( text ) ;
		TSM_ASSERT ( "file \"" + file + "\" failed to parse. " + "It had errors: " + pr.errors, pr.ok ) ;

		TSM_ASSERT ( "\"" + file + "\" failed to generate an AST.", pr.ast != NULL );

		Program *p = dynamic_cast<Program *>(pr.ast) ;

	    TSM_ASSERT_EQUALS ( "file \"" + file + "\" returned wrong name", p->getName(), "Box" ) ;

		TSM_ASSERT ( "file \"" + file + "\" parser failed to return a Program AST", p );

        TSM_ASSERT_EQUALS ( "file \"" + file + "\" returned wrong number of states", p->getNumStates(), 5 ) ;

        TSM_ASSERT_EQUALS ( "file \"" + file + "\" returned wrong number of variable declarations", p->getNumVarDecls(), 1 ) ;

        TSM_ASSERT_EQUALS ( "file \"" + file + "\" returned wrong number of variable uses", p->getNumVarUses(), 18 ) ;
        // Per the example squareMapper where only three VarUses that didn't include Square, we changed the toGoto memeber
        // in transition class to a string instead of a variableUse

	}

	void test_ast_sumOfSquares ( ) {
		string file = "../samples/sumOfSquares.cff" ;
		const char *text = readInputFromFile ( file.c_str() ) ;
		TS_ASSERT ( text );

		ParseResult pr = p->parse ( text ) ;
		TSM_ASSERT ( "file \"" + file + "\" failed to parse. " + "It had errors: " + pr.errors, pr.ok ) ;

		TSM_ASSERT ( "\"" + file + "\" failed to generate an AST.", pr.ast != NULL );

		Program *p = dynamic_cast<Program *>(pr.ast) ;

	    TSM_ASSERT_EQUALS ( "file \"" + file + "\" returned wrong name", p->getName(), "SumOfSquares" ) ;

		TSM_ASSERT ( "file \"" + file + "\" parser failed to return a Program AST", p );

        TSM_ASSERT_EQUALS ( "file \"" + file + "\" returned wrong number of states", p->getNumStates(), 2 ) ;

        TSM_ASSERT_EQUALS ( "file \"" + file + "\" returned wrong number of variable declarations", p->getNumVarDecls(), 2 ) ;

        TSM_ASSERT_EQUALS ( "file \"" + file + "\" returned wrong number of variable uses", p->getNumVarUses(), 12 ) ;
	}

	void test_ast_abstar ( ) {
		string file = "../samples/abstar.cff" ;
		const char *text = readInputFromFile ( file.c_str() ) ;
		TS_ASSERT ( text );

		ParseResult pr = p->parse ( text ) ;
		TSM_ASSERT ( "file \"" + file + "\" failed to parse. " + "It had errors: " + pr.errors, pr.ok ) ;

		TSM_ASSERT ( "\"" + file + "\" failed to generate an AST.", pr.ast != NULL );

		Program *p = dynamic_cast<Program *>(pr.ast) ;
		TSM_ASSERT ( "file \"" + file + "\" parser failed to return a Program AST", p );

		TSM_ASSERT_EQUALS ( "file \"" + file + "\" returned wrong name", p->getName(), "ABStar" ) ;

        TSM_ASSERT_EQUALS ( "file \"" + file + "\" returned wrong number of states", p->getNumStates(), 3 ) ;

        TSM_ASSERT_EQUALS ( "file \"" + file + "\" returned wrong number of variable declarations", p->getNumVarDecls(), 0 ) ;

        TSM_ASSERT_EQUALS ( "file \"" + file + "\" returned wrong number of variable uses", p->getNumVarUses(), 16 ) ;
	}

    void test_ast_squareMapper ( ) {
        string file = "../samples/squareMapper.cff" ;
        const char *text =  readInputFromFile ( file.c_str() ) ;
        TS_ASSERT ( text ) ;

        // 1. Test that the file can be parsed.
        ParseResult pr = p->parse ( text ) ;
        TSM_ASSERT ( "file \"" + file + "\" failed to parse. " + "It had errors: " + pr.errors, pr.ok ) ;

        // 2. Verify that the ast field is not null
        TSM_ASSERT ( "\"" + file + "\" failed to generate an AST.", pr.ast != NULL );

        // 3. Verify that the parser AST is an Expr.
        Program *p = dynamic_cast<Program *>(pr.ast) ;
        TSM_ASSERT ( "file \"" + file + "\" parser failed to return a Program AST", p ) ;

        // 4. Verify that the correct name is reported.
        TSM_ASSERT_EQUALS ( "file \"" + file + "\" returned wrong name", p->getName(), "SquareMapper" ) ;

        // 5. Verify that the correct number of states.
        TSM_ASSERT_EQUALS ( "file \"" + file + "\" returned wrong number of states", p->getNumStates(), 1 ) ;

        // 6. Verify that the correct number variable declarations.
        TSM_ASSERT_EQUALS ( "file \"" + file + "\" returned wrong number of variable declarations", p->getNumVarDecls(), 0 ) ;

        // 7. Verify that the correct number variable uses.
        TSM_ASSERT_EQUALS ( "file \"" + file + "\" returned wrong number of variable uses", p->getNumVarUses(), 3 ) ;
    }


    /*

        We wrote test_Program_getName right after we completed Program. Program::getName() was already written, and the test passed right away.

    Next we wrote the getNumVarDecls tests, starting from the bottom with Decls and moving to the top with Program. Both passed.

    Third we wrote the getNumVarUses tests. There were a lot more methods to test in this one because the method goes much deeper
    into the AST than the others. I originally wrote a single test, constructed an AST from the bottom, and tested getNumVarUses at each step,
    but this violated the principle of unit tests testing a single thing so I split it up into many tests, saving each piece of the AST as I went
    along.

    I needed to write constructors for Plus, Mul, and the related classes as I went along. I realized there was a lot of code duplication in the
    constructors for those classes so I made a note to use the superclass BinOp's constructor instead, which Frank and I later did.

    I encountered the first error in the test for Stmts, where it segfaulted. I found the cause to be that pointers that should have been NULL
    were not initialized to NULL properly, with the bug duplicated across all of our list classes (Decls, Stmts, Transitions, States).

    I continued all the way up to Program::getNumVarUses(), writing constructors as I went.

    Finally there are the tests for getNumStates which passed right after I wrote them.

	After all tests were passing and the parser completed, we decided to switch the implementation of collections of State from using a linked list using classes States and State to having Program maintain a vector of State*. The tests passed the first time after compiling the new changes.
	
	
    */


    //getName tests
    void test_Program_getName(){
        string s("name");
        Program p(s, NULL,NULL,NULL);
        TS_ASSERT(p.getName().compare(s) == 0);
    }

    //getNumVarDecls tests
        //writing tests from bottom to top
    void test_Decls_getNumVarDecls(){
        Decl a, b, c;
        Decls bottom(NULL, NULL);
        Decls first(&a, &bottom);
        Decls second(&b, &first);
        TS_ASSERT(second.getNumVarDecls() == 2);
        TS_ASSERT(first.getNumVarDecls() == 1);
        TS_ASSERT(bottom.getNumVarDecls() == 0);
    }


    void test_Program_getNumVarDecls(){
        Decl a;
        Decls bottom(NULL, NULL);
        Decls first(&a, &bottom);
        Program p("", NULL, &first, NULL);
        TS_ASSERT(p.getNumVarDecls() == 1);
    }

    //getNumVarUses tests
        //assembles an abstract syntax tree from bottom to top
            //I reuse some objects but it shouldn't matter

    void test_Expr_getNumVarUses(){
        Expr r;
        TS_ASSERT_EQUALS(r.getNumVarUses(), 0);
    }

    VariableUse a, b, c, d, e;

    void test_variableUse_getNumVarUses(){
        TS_ASSERT_EQUALS(a.getNumVarUses(), 1);
    }

    Plus* plus;
    Mul* m;

    void test_BinOp_getNumVarUses(){
        plus = new Plus(&a, &b);
        TS_ASSERT_EQUALS(plus->getNumVarUses(), 2);    //for this one needed to create the constructor for Plus and fix errors with BinOp being abstract
        m = new Mul(plus, &c);
        TS_ASSERT_EQUALS(m->getNumVarUses(), 3);    //wrote Mul constructor
                //NOTE: can we use BinOp's constructor instead? They all do the same thing
    }

    Stmt* stmt;
    void test_Stmt_getNumVarUses(){
        stmt = new Stmt(m, &d);
        TS_ASSERT_EQUALS(stmt->getNumVarUses(), 4); //wrote Stmt::getNumVarUses()
    }
    Stmts* bottom_stmts;
    Stmts* stmts;
    void test_Stmts_getNumVarUses(){
        bottom_stmts = new Stmts();
        TS_ASSERT_EQUALS(bottom_stmts->getNumVarUses(), 0); //wrote Stmts::getNumVarUses() // segfaulted here, Stmt::getNumVarUses was being called on an uninitialized Stmt* when it should have been NULL

        stmts = new Stmts(stmt, bottom_stmts);     //wrote Stmts constructor, fixed bug where Stmts had two Stmt* points and not one Stmt* one Stmts*
        TS_ASSERT_EQUALS(stmts->getNumVarUses(), 4);
        }

        Transition* tran; //intermediate variable so I do not have to keep reconstructing the same thing

    void test_Transition_getNumVarUses(){

        Transition trans1(stmts, plus);
        TS_ASSERT_EQUALS(trans1.getNumVarUses(), 6);//wrote Transition::getNumVarUses()

        tran = new Transition("", stmts, plus);
        TS_ASSERT_EQUALS(tran->getNumVarUses(), 6);
    }
    Transitions* trans;
    Transitions* bottom_trans;
    void test_Transitions_getNumVarUses(){
        bottom_trans = new Transitions(); //wrote Transitions::getNumVarUses() and Transitions() constructor
        trans = new Transitions(tran, bottom_trans); //noticing there's a lot of code duplication for Transitions, Stmts, and States
        TS_ASSERT_EQUALS(trans->getNumVarUses(), 6);
    }
    State* st;
    void test_State_getNumVarUses(){
        st = new State(trans);
        TS_ASSERT_EQUALS(st->getNumVarUses(), 6);
    }

    /*States* states;
    States* bottom_states;
    States* first_states;

    void xtest_States_getNumVarUses(){   //Split up the test into many, now getting a segfault here
        bottom_states = new States();
        first_states = new States(st, bottom_states);   //fixed, was the same reason as the earlier segfault, States::left and right were not being initialized to NULL properly
        states = new States(st, first_states);
        TS_ASSERT_EQUALS(states->getNumVarUses(), 12);
    }*/


    Program *prog;
    void test_Program_getNumVarUses(){
        vector<State*>* states = new vector<State*>;
        states->push_back(st);
        states->push_back(st);
        prog = new Program("", NULL, NULL, states);
        TS_ASSERT_EQUALS(prog->getNumVarUses(), 12);
    }


    //getNumStates tests
        //wrote getNumStates(), then wrote tests, passed right away
    /*void xtest_States_getNumStates(){
        TS_ASSERT_EQUALS(bottom_states->getNumStates(), 0);
        TS_ASSERT_EQUALS(first_states->getNumStates(), 1);
         TS_ASSERT_EQUALS(states->getNumStates(), 2);
    }*/

    void test_Program_getNumStates(){
        TS_ASSERT_EQUALS(prog->getNumStates(), 2);
    }



} ;
