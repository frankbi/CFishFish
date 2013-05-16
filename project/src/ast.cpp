#include "ast.h"
#include <cassert>
#include <string>

#include <iostream>

Node::~Node() {}

Type::Type(enum TypeEnum type) :  t(type) {}

enum TypeEnum Type::getType() {
	return t;
}

Program::Program() {
	programName = "";
}

Program::Program(string name, Platform* platf, Decls* dec, States* st) : programName(name), platform(platf), decls(dec), states(st) {}

string Program::getName() {
	return programName;
}

int Program::getNumStates() {
	return states->getNumStates();
}

int Program::getNumVarDecls() {
	return decls->getNumVarDecls();
}

int Program::getNumVarUses() {
	return states->getNumVarUses();
}

string Program::cppCode_h() {
 	int count = states->getNumStates();
	string code_h;
	code_h.append("// Generated Machine.h for " + programName + " \n\n");
	code_h.append("#include \"RunTime.h\" \n\n");
	code_h.append("// Declarations of the State classes \n");
 	States *ptr = states;	
 	for (int i = 0; i < count; i++) {
 		code_h.append("class State_" + ptr->left->stringname + " ; \n"); 
 		ptr = ptr->right;
 	}
 	code_h.append("\n\n");
 	code_h.append("class " + programName + "_Machine ");
 	code_h.append("{\n   public:\n   " + programName + "_Machine( int argc, char **argv ) ; \n\n");
 	code_h.append("   void go() ; \n\n");
 	code_h.append("   " + platform->platformName + " *runTime ;\n\n");
 	code_h.append("   // Machine states \n");
	States *ptr1 = states;
	for (int i = 0; i < count; i++) {
 		code_h.append("   State_" + ptr1->left->stringname + " *state_" + ptr1->left->stringname + " ; \n");
 		ptr1 = ptr1->right;
 	}
 	code_h.append("\n} ; \n\n");
 	code_h.append("class " + programName + "State: public MachineState { \n");
	code_h.append("   public: \n");
	code_h.append("   " + programName + "_Machine *stateMachine ; \n");
	code_h.append("} ; \n\n"); 	
 	code_h.append("// Concrete machine states \n");
	States *ptr2 = states;
	for (int i = 0; i < count; i++) {
		code_h.append("class State_" + ptr2->left->stringname + " : public " + programName + "State { \n");
		code_h.append("   public: \n");
		code_h.append("   MachineState *enter() ; \n");
		code_h.append("   State_" + ptr2->left->stringname + " ( " + programName + "_Machine *m ) ; \n");
		code_h.append("} ; \n\n");
		ptr2 = ptr2->right;
	}
	return code_h; 
}



string Program::cppCode_cpp() { 
	int count = states->getNumStates();
	string code_cpp;
	code_cpp.append("// Generated Machine.cpp for " + programName + " \n\n");
	code_cpp.append("#include \"Machine.h\" \n");
	code_cpp.append("using namespace std ; \n");
	code_cpp.append(programName + "_Machine::" + programName + "_Machine (int argc, char **argv) { \n");
	code_cpp.append("   runTime = new " + platform->platformName + "(argc, argv) ; \n");
	code_cpp.append("   // Creating state objects \n");
	
	States *ptr = states;

	for (int i = 0; i < count; i++) {
		code_cpp.append("   state_" + ptr->left->stringname + " = new State_" + ptr->left->stringname + "(this) ; \n");
		ptr = ptr->right;
	}
	
	code_cpp.append("} \n\n");
	code_cpp.append("void " + programName + "_Machine::go() {\n");
	code_cpp.append("   runTime->run( state_" + states->left->stringname + " ); \n");
	code_cpp.append("} \n\n");
	code_cpp.append("// Concrete machine states \n");
	
	States *ptr1 = states; 
	
	for (int i = 0; i < count; i++) {
		code_cpp.append("MachineState *State_" + ptr1->left->stringname + "::enter() { \n");
		States *ptr2 = ptr1;		
		
		while (ptr2->left->tran->left != NULL) {
			string temp = ptr2->left->tran->left->toGoto;
			string statemachine;
			
			if (temp == "") statemachine = "NULL ;   } \n\n";
			else statemachine = "stateMachine->state_" + temp + " ;   \n   } \n\n";
			
			string output = ptr2->left->tran->left->toPerform->left->var->name;
			code_cpp.append("   if ( " + states->cppCode_expr() + " ) { \n");
			code_cpp.append("      stateMachine->runTime->" + output + " = \"" + states->cppCode_expr() + "\" ; \n\n");
			code_cpp.append("      return " + statemachine);
			ptr2->left->tran = ptr2->left->tran->right;	
		}
		
		code_cpp.append("}\n\n");
		code_cpp.append("State_" + ptr1->left->stringname + "::State_" + ptr1->left->stringname + " ( " + programName + "_Machine *m ) { \n");
		code_cpp.append("   stateMachine = m ; \n");
		code_cpp.append("}\n\n\n");	
		ptr1 = ptr1->right;
	}
	
	code_cpp.append("\n\n");
	code_cpp.append("// A 'main' program to run the state machine.\n");
	code_cpp.append("int main (int argc, char **argv) { \n");
	code_cpp.append("  " + programName + "_Machine *" + programName + " = new " + programName + "_Machine (argc, argv) ; \n");
	code_cpp.append("  " + programName + "->go() ; \n");
	code_cpp.append("} \n\n");


	Expr g;
	cout << g.returntext() << endl;
	
	return code_cpp; 
}





int Expr::getNumVarUses() {
    return 0;
}

string Expr::cppCode_return() {
	return "";
}

int BinOp::getNumVarUses() { // OVERRIDE
    if (left != NULL && right != NULL)
    return left->getNumVarUses() + right->getNumVarUses();
    else return 0;
}


int VariableUse::getNumVarUses() { 
	return 1; 
}







string States::cppCode_expr() {
	return "true";
}

int Decls::getNumVarDecls() {
    int sum = 0;
    if(right != NULL){
        sum = right->getNumVarDecls();
        sum++;
    }
    return sum;
}

Decls::Decls(Decl* left, Decls* right) {
	this->left = left;
	this->right = right;
}

int States::getNumStates() {
    int sum = 0;
    if (right != NULL) { 
    	sum = right->getNumStates();
    	sum++;
    }
    return sum;
}

int Stmt::getNumVarUses() {
	return expr->getNumVarUses() + var->getNumVarUses();
}

int Stmts::getNumVarUses() {
	if (right != NULL) {
		return left->getNumVarUses() + right->getNumVarUses();
	} else {
		return 0;
	}
}

int State::getNumVarUses() {
	return tran->getNumVarUses();
}

int States::getNumVarUses() {
	if (right != NULL) {
		return left->getNumVarUses() + right->getNumVarUses();
	} else {
		return 0;
	}
}

int Transitions::getNumVarUses() {
	if (right != NULL) {
		return left->getNumVarUses() + right->getNumVarUses();
	} else {
		return 0;
	}
}

int Transition::getNumVarUses() {
    	return toPerform->getNumVarUses() + eval->getNumVarUses();
}





/////////////////////////////////////
//        Initializer Lists
/////////////////////////////////////


// PLATFORM //////////////
Platform::Platform() {}

Platform::Platform(string name) : platformName(name) {}

// DECLARATIONS //////////

Decl::Decl() {}

Decl::Decl(Type t, string s) : declType(t), variableName(s) {}

Decls::Decls() : left(NULL), right(NULL) {}

// STATES ////////////////

State::State() : tran(NULL) {}

State::State(Transitions* t, string s) : tran(t), stringname(s) { assert(tran != NULL); }

States::States() : left(NULL), right(NULL) {}

States::States(State* st, States* next) : left(st), right(next) {}

// STATEMENTS ////////////

Stmt::Stmt() {}

Stmt::Stmt(Expr *e, VariableUse *v) : expr(e), var(v) {}

Stmts::Stmts() : left(NULL), right(NULL) {}

Stmts::Stmts(Stmt *s, Stmts *next) : left(s), right(next) {}

// TRANSITIONS ///////////

Transition::Transition() {}

Transition::Transition(Stmts *toperf, Expr *toeval) : toPerform(toperf), eval(toeval), toGoto("") {}

Transition::Transition(string go_to, Stmts *toperf, Expr *toeval) : toPerform(toperf), eval(toeval), toGoto(go_to) {}

Transitions::Transitions() : left(NULL), right(NULL) {}

Transitions::Transitions(Transition *tran, Transitions *next) : left(tran), right(next) {}

// BINOP /////////////////

//BinOp::~BinOp()

// VARIABLEUSE ///////////

VariableUse::VariableUse() { name = ""; }

VariableUse::VariableUse(string s) : name(s) {}

// EXPR AND CHILDREN /////

BinOp::BinOp(Expr *l, Expr *r, string s) : left(l), right(r), op(s) {}


BoolConst::BoolConst(bool b) { val = b; }

IntConst::IntConst(int x) { val = x; }

FloatConst::FloatConst(float x) { val = x; }

CharConst::CharConst(char c) { val = c; }

StringConst::StringConst(string s) { val = s; }

/*
Plus::Plus() {}
//Plus::Plus(Expr* l, Expr* r) { left = l; right = r;}

Mul::Mul() {}
//Mul::Mul(Expr* l, Expr* r) { left = l; right = r;}

Minus::Minus() {}
//Minus::Minus(Expr* l, Expr* r) { left = l; right = r;}

Div::Div() {}
//Div::Div(Expr* l, Expr* r) { left = l; right = r;}

//void* Plus::value(){return right->value() + left->value();}

void* VariableUse::value(){return NULL;}
void* BoolConst::value(){return &val;}
void* IntConst::value(){return &val;}
void* FloatConst::value(){return &val;}
void* CharConst::value(){return &val;}
void* StringConst::value(){return &val;}
*/
