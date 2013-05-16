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
#include "parser_tests.h"

static ParserTestSuite suite_ParserTestSuite;

static CxxTest::List Tests_ParserTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ParserTestSuite( "parser_tests.h", 13, "ParserTestSuite", suite_ParserTestSuite, Tests_ParserTestSuite );

static class TestDescription_ParserTestSuite_test_setup_code : public CxxTest::RealTestDescription {
public:
 TestDescription_ParserTestSuite_test_setup_code() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 18, "test_setup_code" ) {}
 void runTest() { suite_ParserTestSuite.test_setup_code(); }
} testDescription_ParserTestSuite_test_setup_code;

static class TestDescription_ParserTestSuite_test_parse_bad_syntax : public CxxTest::RealTestDescription {
public:
 TestDescription_ParserTestSuite_test_parse_bad_syntax() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 23, "test_parse_bad_syntax" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_bad_syntax(); }
} testDescription_ParserTestSuite_test_parse_bad_syntax;

static class TestDescription_ParserTestSuite_test_parse_exprs : public CxxTest::RealTestDescription {
public:
 TestDescription_ParserTestSuite_test_parse_exprs() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 31, "test_parse_exprs" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_exprs(); }
} testDescription_ParserTestSuite_test_parse_exprs;

static class TestDescription_ParserTestSuite_test_parse_abstar : public CxxTest::RealTestDescription {
public:
 TestDescription_ParserTestSuite_test_parse_abstar() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 51, "test_parse_abstar" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_abstar(); }
} testDescription_ParserTestSuite_test_parse_abstar;

static class TestDescription_ParserTestSuite_test_parse_box : public CxxTest::RealTestDescription {
public:
 TestDescription_ParserTestSuite_test_parse_box() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 60, "test_parse_box" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_box(); }
} testDescription_ParserTestSuite_test_parse_box;

static class TestDescription_ParserTestSuite_test_parse_sumOfSquares : public CxxTest::RealTestDescription {
public:
 TestDescription_ParserTestSuite_test_parse_sumOfSquares() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 69, "test_parse_sumOfSquares" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_sumOfSquares(); }
} testDescription_ParserTestSuite_test_parse_sumOfSquares;

#include <cxxtest/Root.cpp>
