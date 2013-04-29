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
#include "ast_tests.h"

static AstTestSuite suite_AstTestSuite;

static CxxTest::List Tests_AstTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_AstTestSuite( "ast_tests.h", 14, "AstTestSuite", suite_AstTestSuite, Tests_AstTestSuite );

static class TestDescription_AstTestSuite_test_setup_code : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_setup_code() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 21, "test_setup_code" ) {}
 void runTest() { suite_AstTestSuite.test_setup_code(); }
} testDescription_AstTestSuite_test_setup_code;

static class TestDescription_AstTestSuite_test_ast_box : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_ast_box() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 38, "test_ast_box" ) {}
 void runTest() { suite_AstTestSuite.test_ast_box(); }
} testDescription_AstTestSuite_test_ast_box;

static class TestDescription_AstTestSuite_test_ast_sumOfSquares : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_ast_sumOfSquares() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 63, "test_ast_sumOfSquares" ) {}
 void runTest() { suite_AstTestSuite.test_ast_sumOfSquares(); }
} testDescription_AstTestSuite_test_ast_sumOfSquares;

static class TestDescription_AstTestSuite_test_ast_abstar : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_ast_abstar() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 86, "test_ast_abstar" ) {}
 void runTest() { suite_AstTestSuite.test_ast_abstar(); }
} testDescription_AstTestSuite_test_ast_abstar;

static class TestDescription_AstTestSuite_test_ast_squareMapper : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_ast_squareMapper() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 108, "test_ast_squareMapper" ) {}
 void runTest() { suite_AstTestSuite.test_ast_squareMapper(); }
} testDescription_AstTestSuite_test_ast_squareMapper;

static class TestDescription_AstTestSuite_test_Program_getName : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_Program_getName() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 139, "test_Program_getName" ) {}
 void runTest() { suite_AstTestSuite.test_Program_getName(); }
} testDescription_AstTestSuite_test_Program_getName;

static class TestDescription_AstTestSuite_test_Decls_getNumVarDecls : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_Decls_getNumVarDecls() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 147, "test_Decls_getNumVarDecls" ) {}
 void runTest() { suite_AstTestSuite.test_Decls_getNumVarDecls(); }
} testDescription_AstTestSuite_test_Decls_getNumVarDecls;

static class TestDescription_AstTestSuite_test_Program_getNumVarDecls : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_Program_getNumVarDecls() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 158, "test_Program_getNumVarDecls" ) {}
 void runTest() { suite_AstTestSuite.test_Program_getNumVarDecls(); }
} testDescription_AstTestSuite_test_Program_getNumVarDecls;

static class TestDescription_AstTestSuite_test_Expr_getNumVarUses : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_Expr_getNumVarUses() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 170, "test_Expr_getNumVarUses" ) {}
 void runTest() { suite_AstTestSuite.test_Expr_getNumVarUses(); }
} testDescription_AstTestSuite_test_Expr_getNumVarUses;

static class TestDescription_AstTestSuite_test_variableUse_getNumVarUses : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_variableUse_getNumVarUses() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 177, "test_variableUse_getNumVarUses" ) {}
 void runTest() { suite_AstTestSuite.test_variableUse_getNumVarUses(); }
} testDescription_AstTestSuite_test_variableUse_getNumVarUses;

static class TestDescription_AstTestSuite_test_BinOp_getNumVarUses : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_BinOp_getNumVarUses() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 184, "test_BinOp_getNumVarUses" ) {}
 void runTest() { suite_AstTestSuite.test_BinOp_getNumVarUses(); }
} testDescription_AstTestSuite_test_BinOp_getNumVarUses;

static class TestDescription_AstTestSuite_test_Stmt_getNumVarUses : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_Stmt_getNumVarUses() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 193, "test_Stmt_getNumVarUses" ) {}
 void runTest() { suite_AstTestSuite.test_Stmt_getNumVarUses(); }
} testDescription_AstTestSuite_test_Stmt_getNumVarUses;

static class TestDescription_AstTestSuite_test_Stmts_getNumVarUses : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_Stmts_getNumVarUses() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 199, "test_Stmts_getNumVarUses" ) {}
 void runTest() { suite_AstTestSuite.test_Stmts_getNumVarUses(); }
} testDescription_AstTestSuite_test_Stmts_getNumVarUses;

static class TestDescription_AstTestSuite_test_Transition_getNumVarUses : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_Transition_getNumVarUses() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 209, "test_Transition_getNumVarUses" ) {}
 void runTest() { suite_AstTestSuite.test_Transition_getNumVarUses(); }
} testDescription_AstTestSuite_test_Transition_getNumVarUses;

static class TestDescription_AstTestSuite_test_Transitions_getNumVarUses : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_Transitions_getNumVarUses() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 219, "test_Transitions_getNumVarUses" ) {}
 void runTest() { suite_AstTestSuite.test_Transitions_getNumVarUses(); }
} testDescription_AstTestSuite_test_Transitions_getNumVarUses;

static class TestDescription_AstTestSuite_test_State_getNumVarUses : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_State_getNumVarUses() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 225, "test_State_getNumVarUses" ) {}
 void runTest() { suite_AstTestSuite.test_State_getNumVarUses(); }
} testDescription_AstTestSuite_test_State_getNumVarUses;

static class TestDescription_AstTestSuite_test_States_getNumVarUses : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_States_getNumVarUses() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 234, "test_States_getNumVarUses" ) {}
 void runTest() { suite_AstTestSuite.test_States_getNumVarUses(); }
} testDescription_AstTestSuite_test_States_getNumVarUses;

static class TestDescription_AstTestSuite_test_Program_getNumVarUses : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_Program_getNumVarUses() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 243, "test_Program_getNumVarUses" ) {}
 void runTest() { suite_AstTestSuite.test_Program_getNumVarUses(); }
} testDescription_AstTestSuite_test_Program_getNumVarUses;

static class TestDescription_AstTestSuite_test_States_getNumStates : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_States_getNumStates() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 252, "test_States_getNumStates" ) {}
 void runTest() { suite_AstTestSuite.test_States_getNumStates(); }
} testDescription_AstTestSuite_test_States_getNumStates;

static class TestDescription_AstTestSuite_test_Program_getNumStates : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_Program_getNumStates() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 258, "test_Program_getNumStates" ) {}
 void runTest() { suite_AstTestSuite.test_Program_getNumStates(); }
} testDescription_AstTestSuite_test_Program_getNumStates;

#include <cxxtest/Root.cpp>
