#include <cxxtest/TestSuite.h>
#include "readInput.h"
#include "scanner.h"
#include "regex.h"

using namespace std ;

class ScannerTestSuite : public CxxTest::TestSuite
{
public:
    /* A Scanner object is created in the test_setup_code method.
       This is a test, beginning with "test_", so that it is executed
       by the testing framework.  The scanner is used in some tests of
       the method "scan".
     */
    Scanner *s ;
    void test_setup_code ( ) {
        s = new Scanner() ;
    }


    // Tests for components and functions used by "scan"
    // --------------------------------------------------

    /* You may need to write several tests to adequately test the
       functions that are called from "scan".  Once you are confident
       that the components used by "scan" work properly, then you can
       run tests on the "scan" method itself.
    */

    // Here you should place tests for these other functions.


    /* Below is one of the tests for these components in the project
       solution created by your instructor..  It uses a helper
       function function called "tokenMaker_tester", which you have
       not been given.  You are expected to design your own components
       for "scan" and your own mechanisms for easily testing them.

       void xtest_TokenMaker_leftCurly ( ) {
           TS_ASSERT (tokenMaker_tester ("{ ", "^\\{", leftCurly, "{" ) );
       }

        Note that this test is here named "xtest_Token..." The leading
        "x" is so that cxxTest doesn't scan the line above and think
        it is an actual test that isn't commented out.  cxxTest is
        very simple and doesn't even process block comments.
    */

   void test_make_token_nameKwd(){
       //failing, returns variable name
      TS_ASSERT (s->make_token_tester ("name ", nameKwd, "name"));
   }
   void test_make_token_platformKwd(){
      TS_ASSERT (s->make_token_tester ("platform ", platformKwd, "platform"));
   }
   void test_make_token_initialKwd(){
      TS_ASSERT (s->make_token_tester ("initial ", initialKwd, "initial"));
   }
   void test_make_token_stateKwd(){
      TS_ASSERT (s->make_token_tester ("state ", stateKwd, "state"));
   }
   void test_make_token_gotoKwd(){
      TS_ASSERT (s->make_token_tester ("goto ", gotoKwd, "goto"));
   }
   void test_make_token_whenKwd(){
      TS_ASSERT (s->make_token_tester ("when ", whenKwd, "when"));
   }
   void test_make_token_performingKwd(){
      TS_ASSERT (s->make_token_tester ("performing ", performingKwd, "performing"));
   }
   void test_make_token_exitKwd(){
      TS_ASSERT (s->make_token_tester ("exit ", exitKwd, "exit"));
   }
   void test_make_token_intKwd(){
      TS_ASSERT (s->make_token_tester ("int ", intKwd, "int"));
   }
   void test_make_token_floatKwd(){
      TS_ASSERT (s->make_token_tester ("float ", floatKwd, "float"));
   }
   void test_make_token_booleanKwd(){
      TS_ASSERT (s->make_token_tester ("boolean ", booleanKwd, "boolean"));
   }
   void test_make_token_stringKwd(){
      TS_ASSERT (s->make_token_tester ("string ", stringKwd, "string"));
   }
   void test_make_token_charKwd(){
      TS_ASSERT (s->make_token_tester ("char ", charKwd, "char"));
   }
   void test_make_token_trueKwd(){
      TS_ASSERT (s->make_token_tester ("true ", trueKwd, "true"));
   }
   void test_make_token_falseKwd(){
      TS_ASSERT (s->make_token_tester ("false ", falseKwd, "false"));
   }

    void test_make_token_intConst(){
        TS_ASSERT (s->make_token_tester ("123 ", intConst, "123"));
    }
    void test_make_token_floatConst(){
        TS_ASSERT (s->make_token_tester ("10.1 ", floatConst, "10.1"));
    }
    void test_make_token_floatConst_initial_dot(){
        TS_ASSERT (s->make_token_tester (".123 ", floatConst, ".123"));
    }
    void test_make_token_stringConst(){
        TS_ASSERT (s->make_token_tester("\"string\" ", stringConst, "\"string\""));
    }
    void test_make_token_stringConst_empty(){
        TS_ASSERT (s->make_token_tester("\"\" ", stringConst, "\"\""));
    }
    void test_make_token_charConst(){
        TS_ASSERT (s->make_token_tester("'a' ", charConst, "'a'"));
    }


    void test_make_token_variableName_1(){
        TS_ASSERT (s->make_token_tester ("fooBar ", variableName , "fooBar"));
    }
    void test_make_token_variableName_2(){
        TS_ASSERT (s->make_token_tester ("F00_bar-var ", variableName , "F00_bar-var"));
    }
    void test_make_token_leftParen(){
        TS_ASSERT (s->make_token_tester ("( ", leftParen, "("));
    }
    void test_make_token_rightParen(){
        TS_ASSERT (s->make_token_tester (") ", rightParen, ")"));
    }
    void test_make_token_leftCurly(){
        TS_ASSERT (s->make_token_tester ("{ ", leftCurly, "{"));
    }
    void test_make_token_rightCurly(){
        TS_ASSERT (s->make_token_tester ("} ", rightCurly, "}"));
    }

    void test_make_token_leftAngle(){
        TS_ASSERT (s->make_token_tester ("< ", leftAngle, "<"));
    }
    void test_make_token_rightAngle(){
        TS_ASSERT (s->make_token_tester ("> ", rightAngle, ">"));
    }

   void test_make_token_colon(){
      TS_ASSERT (s->make_token_tester (": ", colon, ":"));
   }
   void test_make_token_comma(){
      TS_ASSERT (s->make_token_tester (", ", comma, ","));
   }
   void test_make_token_semiColon(){
      TS_ASSERT (s->make_token_tester ("; ", semiColon, ";"));
   }
   void test_make_token_assign(){
      TS_ASSERT (s->make_token_tester (":= ", assign, ":="));
   }
   void test_make_token_plusSign(){
      TS_ASSERT (s->make_token_tester ("+ ", plusSign, "+"));
   }
   void test_make_token_star(){
      TS_ASSERT (s->make_token_tester ("* ", star, "*"));
   }
   void test_make_token_dash(){
      TS_ASSERT (s->make_token_tester ("- ", dash, "-"));
   }
   void test_make_token_forwardSlash(){
      TS_ASSERT (s->make_token_tester ("/ ", forwardSlash, "/"));
   }
   void test_make_token_equalsEquals(){
      TS_ASSERT (s->make_token_tester ("== ", equalsEquals, "=="));
   }
   void test_make_token_lessThanEquals(){
      TS_ASSERT (s->make_token_tester ("<= ", lessThanEquals, "<="));
   }
   void test_make_token_greaterThanEquals(){
      TS_ASSERT (s->make_token_tester (">= ", greaterThanEquals, ">="));
   }
   void test_make_token_notEquals(){
      TS_ASSERT (s->make_token_tester ("!= ", notEquals, "!="));
   }



    void test_consume_white_space_and_comments(){
        TS_ASSERT(s->consume_white_space_and_comments("/* */ name") == 6);
        TS_ASSERT(s->consume_white_space_and_comments("    \n  //   \n /* */ name") == 20);
    }
    void test_consume_white_space_and_comments_empty(){
        TS_ASSERT(s->consume_white_space_and_comments("   ") == 3);
    }
    /* You must have at least one separate test case for each terminal
       symbol.  Thus, you need a test that will pass or fail based
       solely on the regular expression (and its corresponding code)
       for each terminal symbol.

       This requires a test case for each element of the enumerated
       type tokenType.  This may look something like the sample test
       shown in the comment above.
    */


    // Tests for "scan"
    // --------------------------------------------------

    /* Below are some helper functions and sample tests for testing the
       "scan" method on Scanner.
    */

    // Test that a list of tokens has no lexicalError tokens.
    bool noLexicalErrors (Token *tks) {
        Token *currentToken = tks ;
        while (currentToken != NULL) {
            if (currentToken->terminal == lexicalError) {
                return false ;
            }
            else {
                currentToken = currentToken->next ;
            }
        }
        return true ;
    }

    /* A quick, but inaccurate, test for scanning files.  It only
       checks that no lexical errors occurred, not that the right
       tokens were returned.
    */
    void scanFileNoLexicalErrors ( const char* filename ) {
        char *text =  readInputFromFile ( filename )  ;
        TS_ASSERT ( text ) ;
        Token *tks = s->scan ( text ) ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT (noLexicalErrors(tks));
    }


    /* This function checks that the terminal fields in the list of
       tokens matches a list of terminals.
    */
    bool sameTerminals (Token *tks, int numTerms, tokenType *ts) {
        bool same = true;
        Token *currentToken = tks ;
        int termIndex = 0 ;
        while (termIndex < numTerms ) {
            if (currentToken == NULL){
                cout << "Terminal " << termIndex << "not present" << endl;
                same = false;
            }
            else if (currentToken->terminal != ts[termIndex]) {
                same = false;
                cout << "Terminal " << termIndex << " should be " << ts[termIndex] << ", got " << currentToken->terminal << endl;
                currentToken = currentToken->next;
            }
            else {
                currentToken = currentToken->next ;
            }
            ++ termIndex ;
        }
        while(currentToken != NULL){cout << "Extra terminal " << currentToken->terminal << endl; currentToken = currentToken->next;}
        return same;
    }


    /* Below are the provided test files that your code should also
       pass.

       You may initially want to rename these tests to "xtest_..." so
       that the CxxTest framework does not see it as a test and won't
       run it as one.  This way you can focus on the tests that you'll
       write above for the individual terminal types first. Then focus
       on these tests.

    */

    // The "endOfFile" token is always the last one in the list of tokens.
    void test_scan_empty ( ) {
        Token *tks = s->scan ("  ") ;

        TS_ASSERT (tks != NULL) ;

        TS_ASSERT_EQUALS (tks->terminal, endOfFile) ;
        TS_ASSERT (tks->next == NULL) ;
    }

    void test_scan_empty_comment ( ) {
        Token *tks = s->scan (" /* a comment */ ") ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, endOfFile) ;
        TS_ASSERT (tks->next == NULL) ;
    }

    // When a lexical error occurs, the scanner creates a token with a
    // single-character lexeme and lexicalError as the terminal.
    void test_scan_lexicalErrors ( ) {
        Token *tks = s->scan ("$&1  ") ;

        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, lexicalError) ;
        TS_ASSERT_EQUALS (tks->lexeme, "$");
        tks = tks->next ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, lexicalError) ;
        TS_ASSERT_EQUALS (tks->lexeme, "&");
        tks = tks->next ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, intConst) ;
        TS_ASSERT_EQUALS (tks->lexeme, "1");
        tks = tks->next ;
        TS_ASSERT (tks != NULL) ;

        TS_ASSERT_EQUALS (tks->terminal, endOfFile) ;
        TS_ASSERT (tks->next == NULL) ;
    }


    // A test for scanning numbers and a variable.
    void test_scan_nums_vars ( ) {
        Token *tks = s->scan (" 123 x 12.34 ") ;
        TS_ASSERT (tks != NULL) ;
        tokenType ts[] = { intConst, variableName, floatConst, endOfFile } ;
        TS_ASSERT ( sameTerminals ( tks, 4, ts ) ) ;
    }



    /* This test checks that the scanner returns a list of tokens with
       the correct terminal fields.  It doesn't check that the lexeme
       are correct.
     */

    void test_scan_bad_syntax_good_tokens ( ) {
        const char *filename = "../samples/bad_syntax_good_tokens.stm" ;
        char *text =  readInputFromFile ( filename )  ;
        TS_ASSERT ( text ) ;
        Token *tks = s->scan ( text ) ;
        TS_ASSERT (tks != NULL) ;
        tokenType ts[] = {
            intConst, intConst, intConst, intConst,

            stringConst, stringConst, stringConst,

            floatConst, floatConst, floatConst,

            charConst, charConst, charConst, charConst,
            charConst, charConst, charConst,

            trueKwd, falseKwd,


            colon, semiColon, comma,
            leftCurly, leftParen, rightCurly, rightParen,

            plusSign, star, dash, forwardSlash,
            rightAngle, leftAngle,

            equalsEquals, lessThanEquals,
            greaterThanEquals, notEquals,
            assign,

            variableName, variableName, variableName, variableName,
            variableName, variableName, variableName,

            nameKwd, platformKwd, initialKwd, stateKwd,
            gotoKwd, whenKwd, exitKwd, performingKwd,

            intKwd, floatKwd, booleanKwd, stringKwd, charKwd,

            endOfFile
        } ;
        int count = 58;
        TS_ASSERT ( sameTerminals ( tks, count, ts ) ) ;
    }

    void test_scan_sample_abstar ( ) {
        scanFileNoLexicalErrors ("../samples/abstar.stm") ;
    }


} ;
