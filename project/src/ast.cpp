#include "ast.h"
#include <cassert>

#include <string>

#include <iostream>

using namespace std;

Node::~Node() {
}

Type::Type(enum TypeEnum type) :  t(type) {}

enum TypeEnum Type::getType() { 
	return t; 
}

// Dummy
Program::Program() { 
	programName = ""; 
}

Program::Program(string name, Platform* platf, Decls* dec, vector<State*>* st) : programName(name), platform(platf), decls(dec), states(st) {} //assert(platf != NULL); assert(dec != NULL); assert(st != NULL);}

string Program::getName() { 
	return programName; 
}

int Program::getNumStates() { 
	return states->size(); 
}

int Program::getNumVarDecls() { 
	return decls->getNumVarDecls(); 
}

int Program::getNumVarUses() {
    int sum = 0;
    for (unsigned int i = 0; i < states->size(); i++) {
        sum += (*states)[i]->getNumVarUses();
    }
    return sum;
}



////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


string Program::cppCode_h() {

	string code_h;
	code_h.append("// Generated Machine.h for " + programName + " \n\n");
	code_h.append("#include \"RunTime.h\" \n\n");
	code_h.append("// Declarations of the State classes \n");
 	for (int i; i < states.size(); i++) {
 		code_h.append("class State_" + states[i] + " ; \n");
 	}
 	code_h.append("\n\n");
 	
 	code_h.append("class " + programName + "_Machine ");
 	code_h.append("{\n   public:\n   " + programName + "_Machine( int argc, char **argv ) ; \n\n");
 	code_h.append("   void go() ; \n\n");
 	code_h.append("   " + platform + " *runTime ;\n\n");
 	
 	code_h.append("   // Machine states");
 	for (int i; i < states.size(); i++) {
 		string temp = states[i];
 		temp.erase(0,6);
 		code_h.append("   State_" + states[i] + " *state_" + temp + " ; \n\n");
 	}
 	code_h.append("} ; \n\n");
 	
 	code_h.append("class " + programName + "State: public Machine State { \n");
	code_h.append("   public: \n");
	code_h.append("   " + programName + "_Machine *stateMachine ; \n");
	code_h.append("} ; \n\n"); 	
 	
 	code_h.append("// Concrete machine states \n");
 	for (int i; i < states.size(); i++) {
 		code_h.append("class State_" + states[i] + " : public " + programName + "State { \n");
 		code_h.append("   public: \n");
 		code_h.append("   MachineState *enter() ; \n");
 		code_h.append("   State_" + states[i] + " ( " + programName + "_Machine *m ) ; \n");
 		code_h.append("} ; \n\n");
	}
 	
	return code_h; 
}







string Program::cppCode_cpp() { 

	string code_cpp;
	code_cpp.append("// Generated Machine.cpp for " + programName + " \n\n");
	code_cpp.append("#include \"Machine.h\" \n");
	code_cpp.append("using namespace std ; \n");
	code_cpp.append(programName + "_Machine::" + programName + "_Machine (int argc, char **argv) ");
	
	return code_cpp; 
}


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////




Platform::Platform() {}

Platform::Platform(string name) : platformName(name) {}




Decl::Decl() {}

Decl::Decl(Type t, string s) : declType(t), variableName(s) {}

Decls::Decls() : left(NULL), right(NULL) {}

Decls::Decls(Decl* left, Decls* right) {
	this->left = left;
	this->right = right;
}

int Decls::getNumVarDecls() {
    int sum = 0;
    if (right != NULL) {
        sum = right->getNumVarDecls();
        sum++;
    }
    return sum;
}




State::State() : tran(NULL) {}

State::State(Transitions* t) : tran(t) { 
	assert(tran != NULL);
}


Stmt::Stmt(){} //dummy

Stmt::Stmt(Expr* e, VariableUse* v) : expr(e), var(v) {}

Stmts::Stmts() : left(NULL), right(NULL) { }

Stmts::Stmts(Stmt* s, Stmts* next) : left(s), right(next) {}


Transition::Transition() {}

Transition::Transition(Stmts* toperf, Expr* toeval) : toPerform(toperf), eval(toeval), toGoto("") {}

Transition::Transition(string go_to, Stmts* toperf, Expr* toeval) : toPerform(toperf), eval(toeval) ,toGoto(go_to) {}

Transitions::Transitions() : left(NULL), right(NULL) {}

Transitions::Transitions(Transition* tran, Transitions* next) : left(tran), right(next) {}


int Stmt::getNumVarUses() {
	return expr->getNumVarUses() + var->getNumVarUses();
}

int Stmts::getNumVarUses() {
    if (right != NULL) {
    	return left->getNumVarUses() + right->getNumVarUses();
    }
    else return 0;
}

int State::getNumVarUses() {
    return tran->getNumVarUses();
}

int Transitions::getNumVarUses() {
    if (right != NULL) {
        return left->getNumVarUses() + right->getNumVarUses();
    }
    else return 0;
}

int Transition::getNumVarUses() {
    return toPerform->getNumVarUses() + eval->getNumVarUses();

}

int Expr::getNumVarUses() {
    //TODO:
    return 0;
}

BinOp::~BinOp() {}

int BinOp::getNumVarUses() { //override
    if(left != NULL && right != NULL)
    return left->getNumVarUses() + right->getNumVarUses();
    else return 0;
}

int VariableUse::getNumVarUses() {
	return 1;
}

VariableUse::VariableUse() {
	name = "";
}

VariableUse::VariableUse(string s) : name(s) {}


//Expr and children

BinOp::BinOp(Expr* l, Expr* r) : left(l), right(r) {}

Plus::Plus(){} // dummy
//Plus::Plus(Expr* l, Expr* r) { left = l; right = r;}
Mul::Mul(){} // dummy
//Mul::Mul(Expr* l, Expr* r) { left = l; right = r;}
Minus::Minus(){} // dummy
//Minus::Minus(Expr* l, Expr* r) { left = l; right = r;}
Div::Div(){} // dummy
//Div::Div(Expr* l, Expr* r) { left = l; right = r;}


//void* Plus::value(){return right->value() + left->value();}

BoolConst::BoolConst(bool b) {
	val = b;
}

IntConst::IntConst(int x) {
	val = x;
}

FloatConst::FloatConst(float x) {
	val = x;
}

CharConst::CharConst(char c){
	val = c;
}

StringConst::StringConst(string s) {
	val = s;
}

/*

int States::getNumVarUses(){
    if(right != NULL){
    return left->getNumVarUses() + right->getNumVarUses();
    }
    else return 0;
}

States::States() : left(NULL), right(NULL) {}
States::States(State* st, States* next) : left(st), right(next){}
int States::getNumStates(){ //NOTE: Add to classes in header
    int sum = 0; //also is this code duplication unavoidable?
    if(right != NULL){ sum = right->getNumStates();
    sum++;
    }
    return sum;
}

void* VariableUse::value(){return NULL;}
void* BoolConst::value(){return &val;}
void* IntConst::value(){return &val;}
void* FloatConst::value(){return &val;}
void* CharConst::value(){return &val;}
void* StringConst::value(){return &val;}

bool Type::errorCheck(){ return true;} //This is stupid
bool Program::errorCheck(){ return true;} //TODO:
bool Platform::errorCheck(){ return true;} //TODO:
bool Decls::errorCheck(){ return true;} //TODO:
bool Decl::errorCheck(){ return true;} //TODO:
bool Transition::errorCheck(){return true;} //TODO:
bool Transitions::errorCheck(){return true;} //TODO:
bool Stmt::errorCheck(){return true;} //TODO:
bool Stmts::errorCheck(){return true;} //TODO:

bool States::errorCheck(){ return true;} //TODO:
bool State::errorCheck(){ return true;} //TODO:
bool VariableUse::errorCheck(){ return true;} //TODO:
bool Constant::errorCheck(){return true;}
*/
