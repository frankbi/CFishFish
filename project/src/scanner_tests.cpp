/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#define _CXXTEST_ABORT_TEST_ON_FAIL
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "scanner_tests.h"

static ScannerTestSuite suite_ScannerTestSuite;

static CxxTest::List Tests_ScannerTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ScannerTestSuite( "scanner_tests.h", 8, "ScannerTestSuite", suite_ScannerTestSuite, Tests_ScannerTestSuite );

static class TestDescription_ScannerTestSuite_test_setup_code : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_setup_code() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 17, "test_setup_code" ) {}
 void runTest() { suite_ScannerTestSuite.test_setup_code(); }
} testDescription_ScannerTestSuite_test_setup_code;

static class TestDescription_ScannerTestSuite_test_make_token_nameKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_nameKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 50, "test_make_token_nameKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_nameKwd(); }
} testDescription_ScannerTestSuite_test_make_token_nameKwd;

static class TestDescription_ScannerTestSuite_test_make_token_platformKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_platformKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 54, "test_make_token_platformKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_platformKwd(); }
} testDescription_ScannerTestSuite_test_make_token_platformKwd;

static class TestDescription_ScannerTestSuite_test_make_token_initialKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_initialKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 57, "test_make_token_initialKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_initialKwd(); }
} testDescription_ScannerTestSuite_test_make_token_initialKwd;

static class TestDescription_ScannerTestSuite_test_make_token_stateKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_stateKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 60, "test_make_token_stateKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_stateKwd(); }
} testDescription_ScannerTestSuite_test_make_token_stateKwd;

static class TestDescription_ScannerTestSuite_test_make_token_gotoKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_gotoKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 63, "test_make_token_gotoKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_gotoKwd(); }
} testDescription_ScannerTestSuite_test_make_token_gotoKwd;

static class TestDescription_ScannerTestSuite_test_make_token_whenKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_whenKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 66, "test_make_token_whenKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_whenKwd(); }
} testDescription_ScannerTestSuite_test_make_token_whenKwd;

static class TestDescription_ScannerTestSuite_test_make_token_performingKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_performingKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 69, "test_make_token_performingKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_performingKwd(); }
} testDescription_ScannerTestSuite_test_make_token_performingKwd;

static class TestDescription_ScannerTestSuite_test_make_token_exitKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_exitKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 72, "test_make_token_exitKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_exitKwd(); }
} testDescription_ScannerTestSuite_test_make_token_exitKwd;

static class TestDescription_ScannerTestSuite_test_make_token_intKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_intKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 75, "test_make_token_intKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_intKwd(); }
} testDescription_ScannerTestSuite_test_make_token_intKwd;

static class TestDescription_ScannerTestSuite_test_make_token_floatKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_floatKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 78, "test_make_token_floatKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_floatKwd(); }
} testDescription_ScannerTestSuite_test_make_token_floatKwd;

static class TestDescription_ScannerTestSuite_test_make_token_booleanKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_booleanKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 81, "test_make_token_booleanKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_booleanKwd(); }
} testDescription_ScannerTestSuite_test_make_token_booleanKwd;

static class TestDescription_ScannerTestSuite_test_make_token_stringKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_stringKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 84, "test_make_token_stringKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_stringKwd(); }
} testDescription_ScannerTestSuite_test_make_token_stringKwd;

static class TestDescription_ScannerTestSuite_test_make_token_charKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_charKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 87, "test_make_token_charKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_charKwd(); }
} testDescription_ScannerTestSuite_test_make_token_charKwd;

static class TestDescription_ScannerTestSuite_test_make_token_trueKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_trueKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 90, "test_make_token_trueKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_trueKwd(); }
} testDescription_ScannerTestSuite_test_make_token_trueKwd;

static class TestDescription_ScannerTestSuite_test_make_token_falseKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_falseKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 93, "test_make_token_falseKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_falseKwd(); }
} testDescription_ScannerTestSuite_test_make_token_falseKwd;

static class TestDescription_ScannerTestSuite_test_make_token_intConst : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_intConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 97, "test_make_token_intConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_intConst(); }
} testDescription_ScannerTestSuite_test_make_token_intConst;

static class TestDescription_ScannerTestSuite_test_make_token_floatConst : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_floatConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 100, "test_make_token_floatConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_floatConst(); }
} testDescription_ScannerTestSuite_test_make_token_floatConst;

static class TestDescription_ScannerTestSuite_test_make_token_floatConst_initial_dot : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_floatConst_initial_dot() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 103, "test_make_token_floatConst_initial_dot" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_floatConst_initial_dot(); }
} testDescription_ScannerTestSuite_test_make_token_floatConst_initial_dot;

static class TestDescription_ScannerTestSuite_test_make_token_stringConst : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_stringConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 106, "test_make_token_stringConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_stringConst(); }
} testDescription_ScannerTestSuite_test_make_token_stringConst;

static class TestDescription_ScannerTestSuite_test_make_token_stringConst_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_stringConst_empty() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 109, "test_make_token_stringConst_empty" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_stringConst_empty(); }
} testDescription_ScannerTestSuite_test_make_token_stringConst_empty;

static class TestDescription_ScannerTestSuite_test_make_token_charConst : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_charConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 112, "test_make_token_charConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_charConst(); }
} testDescription_ScannerTestSuite_test_make_token_charConst;

static class TestDescription_ScannerTestSuite_test_make_token_variableName_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_variableName_1() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 117, "test_make_token_variableName_1" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_variableName_1(); }
} testDescription_ScannerTestSuite_test_make_token_variableName_1;

static class TestDescription_ScannerTestSuite_test_make_token_variableName_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_variableName_2() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 120, "test_make_token_variableName_2" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_variableName_2(); }
} testDescription_ScannerTestSuite_test_make_token_variableName_2;

static class TestDescription_ScannerTestSuite_test_make_token_leftParen : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_leftParen() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 123, "test_make_token_leftParen" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_leftParen(); }
} testDescription_ScannerTestSuite_test_make_token_leftParen;

static class TestDescription_ScannerTestSuite_test_make_token_rightParen : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_rightParen() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 126, "test_make_token_rightParen" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_rightParen(); }
} testDescription_ScannerTestSuite_test_make_token_rightParen;

static class TestDescription_ScannerTestSuite_test_make_token_leftCurly : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_leftCurly() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 129, "test_make_token_leftCurly" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_leftCurly(); }
} testDescription_ScannerTestSuite_test_make_token_leftCurly;

static class TestDescription_ScannerTestSuite_test_make_token_rightCurly : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_rightCurly() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 132, "test_make_token_rightCurly" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_rightCurly(); }
} testDescription_ScannerTestSuite_test_make_token_rightCurly;

static class TestDescription_ScannerTestSuite_test_make_token_leftAngle : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_leftAngle() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 136, "test_make_token_leftAngle" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_leftAngle(); }
} testDescription_ScannerTestSuite_test_make_token_leftAngle;

static class TestDescription_ScannerTestSuite_test_make_token_rightAngle : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_rightAngle() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 139, "test_make_token_rightAngle" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_rightAngle(); }
} testDescription_ScannerTestSuite_test_make_token_rightAngle;

static class TestDescription_ScannerTestSuite_test_make_token_colon : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_colon() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 143, "test_make_token_colon" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_colon(); }
} testDescription_ScannerTestSuite_test_make_token_colon;

static class TestDescription_ScannerTestSuite_test_make_token_comma : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_comma() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 146, "test_make_token_comma" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_comma(); }
} testDescription_ScannerTestSuite_test_make_token_comma;

static class TestDescription_ScannerTestSuite_test_make_token_semiColon : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_semiColon() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 149, "test_make_token_semiColon" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_semiColon(); }
} testDescription_ScannerTestSuite_test_make_token_semiColon;

static class TestDescription_ScannerTestSuite_test_make_token_assign : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_assign() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 152, "test_make_token_assign" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_assign(); }
} testDescription_ScannerTestSuite_test_make_token_assign;

static class TestDescription_ScannerTestSuite_test_make_token_plusSign : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_plusSign() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 155, "test_make_token_plusSign" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_plusSign(); }
} testDescription_ScannerTestSuite_test_make_token_plusSign;

static class TestDescription_ScannerTestSuite_test_make_token_star : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_star() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 158, "test_make_token_star" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_star(); }
} testDescription_ScannerTestSuite_test_make_token_star;

static class TestDescription_ScannerTestSuite_test_make_token_dash : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_dash() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 161, "test_make_token_dash" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_dash(); }
} testDescription_ScannerTestSuite_test_make_token_dash;

static class TestDescription_ScannerTestSuite_test_make_token_forwardSlash : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_forwardSlash() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 164, "test_make_token_forwardSlash" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_forwardSlash(); }
} testDescription_ScannerTestSuite_test_make_token_forwardSlash;

static class TestDescription_ScannerTestSuite_test_make_token_equalsEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_equalsEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 167, "test_make_token_equalsEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_equalsEquals(); }
} testDescription_ScannerTestSuite_test_make_token_equalsEquals;

static class TestDescription_ScannerTestSuite_test_make_token_lessThanEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_lessThanEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 170, "test_make_token_lessThanEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_lessThanEquals(); }
} testDescription_ScannerTestSuite_test_make_token_lessThanEquals;

static class TestDescription_ScannerTestSuite_test_make_token_greaterThanEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_greaterThanEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 173, "test_make_token_greaterThanEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_greaterThanEquals(); }
} testDescription_ScannerTestSuite_test_make_token_greaterThanEquals;

static class TestDescription_ScannerTestSuite_test_make_token_notEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_make_token_notEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 176, "test_make_token_notEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_make_token_notEquals(); }
} testDescription_ScannerTestSuite_test_make_token_notEquals;

static class TestDescription_ScannerTestSuite_test_consume_white_space_and_comments : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_consume_white_space_and_comments() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 182, "test_consume_white_space_and_comments" ) {}
 void runTest() { suite_ScannerTestSuite.test_consume_white_space_and_comments(); }
} testDescription_ScannerTestSuite_test_consume_white_space_and_comments;

static class TestDescription_ScannerTestSuite_test_consume_white_space_and_comments_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_consume_white_space_and_comments_empty() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 186, "test_consume_white_space_and_comments_empty" ) {}
 void runTest() { suite_ScannerTestSuite.test_consume_white_space_and_comments_empty(); }
} testDescription_ScannerTestSuite_test_consume_white_space_and_comments_empty;

static class TestDescription_ScannerTestSuite_test_scan_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_empty() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 273, "test_scan_empty" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_empty(); }
} testDescription_ScannerTestSuite_test_scan_empty;

static class TestDescription_ScannerTestSuite_test_scan_empty_comment : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_empty_comment() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 282, "test_scan_empty_comment" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_empty_comment(); }
} testDescription_ScannerTestSuite_test_scan_empty_comment;

static class TestDescription_ScannerTestSuite_test_scan_lexicalErrors : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_lexicalErrors() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 291, "test_scan_lexicalErrors" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_lexicalErrors(); }
} testDescription_ScannerTestSuite_test_scan_lexicalErrors;

static class TestDescription_ScannerTestSuite_test_scan_nums_vars : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_nums_vars() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 314, "test_scan_nums_vars" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_nums_vars(); }
} testDescription_ScannerTestSuite_test_scan_nums_vars;

static class TestDescription_ScannerTestSuite_test_scan_bad_syntax_good_tokens : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_bad_syntax_good_tokens() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 328, "test_scan_bad_syntax_good_tokens" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_bad_syntax_good_tokens(); }
} testDescription_ScannerTestSuite_test_scan_bad_syntax_good_tokens;

static class TestDescription_ScannerTestSuite_test_scan_sample_abstar : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_sample_abstar() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 371, "test_scan_sample_abstar" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_sample_abstar(); }
} testDescription_ScannerTestSuite_test_scan_sample_abstar;

#include <cxxtest/Root.cpp>
