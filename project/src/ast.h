#ifndef AST_H_INCLUDED
#define AST_H_INCLUDED

#include <cstdlib>
#include <string>

using namespace std;

class Platform;
class Decls;
class States;
class Transition;
class Transitions;
class Stmt;
class Stmts;
class VariableUse;

enum TypeEnum {
    Int, Float, Boolean, String, Char
};

class Node {
	public:
		virtual ~Node() = 0;
};

class Type : public Node {
	public:
		Type() {}
		Type(enum TypeEnum);
		enum TypeEnum getType();
	private:
		enum TypeEnum t;
};

class Program : public Node {
	public:
		Program();
		Program(string name, Platform* platf, Decls* dec, States* st);
		string getName();
		int getNumStates() ;
		int getNumVarDecls() ;
		int getNumVarUses() ;
		string cppCode_h();
		string cppCode_cpp();
	protected:
		string programName;
		Platform *platform;
		Decls *decls;
		States *states;
};

class Platform : public Node {
	public:
	    Platform();
	    Platform(string name);
	    string platformName;
};


/*///////////////////////////////////////////////////////////////
	DECLARATIONS
*///////////////////////////////////////////////////////////////

class Decl : public Node {
	public:
	    Decl();
	    Decl(Type t, string varname);
	    Type declType;
	    string variableName;
};

class Decls : public Node {
	public:
	    Decls();
	    Decls(Decl* left, Decls* right);
	    Decl* left;
	    Decls* right;
	    int getNumVarDecls();
};


/*///////////////////////////////////////////////////////////////
	STATES
*///////////////////////////////////////////////////////////////

class State : public Node {
	public:
		State();
		State(Transitions* tran, string sname);
		Transitions *tran;
		int getNumVarUses();
		bool isInitial;
		string stringname;
};

class States : public Node {
	public:
		States();
		States(State *left, States *right);
		State *left;
		States *right;
		int getNumStates();
		int getNumVarUses();
		string cppCode_states();
		string cppCode_expr();
};

class Expr : public Node { //abstract
	public:
		Type getType();
		virtual int getNumVarUses();
		virtual string cppCode_return();
		virtual string returntext() { return "FRANK"; }
		Type t;
};

class BinOp : public Expr { //abstract, do not construct
	public:
		BinOp() {};
		BinOp(Expr *left, Expr *right, string op);
		Expr *left;
		Expr *right;
		string op;
		 int getNumVarUses();
		 string cppCode_return() { return "CHOPS"; }
		 string returntext() { return "CHOPS"; }
};


class VariableUse : public Expr {
	public:
		VariableUse(); //dummy
		VariableUse(string s);
		//bool errorCheck(); //check if previously declared or not
		//void* value(); //always NULL, restructure maybe
		virtual int getNumVarUses();

		string name;
};



/*
class Constant : public Expr {
	public:
		//Constant();
};
*/





class IntConst : public Expr {
	public:
		IntConst(int x);
		//void* value();
	private:
		int val;
};

class FloatConst : public Expr {
	public:
		FloatConst(float f);
		//void* value();
	private:
		float val;
};


class CharConst : public Expr {
	public:
		CharConst(char c);
		//void* value();
	private:
		char val;
};

class StringConst : public Expr {
	public:
		StringConst(string s);
		//void* value();
//	private:
		string val;
};

class BoolConst : public Expr {
	public:
		BoolConst(bool b);
		//void* value();
	private:
		bool val;
};


/*///////////////////////////////////////////////////////////////
	STATEMENTS
*///////////////////////////////////////////////////////////////


class Stmt : public Node {
	public:
		Stmt();
		Stmt(Expr* expr, VariableUse* var);
		int getNumVarUses();

		Expr* expr; //required
		VariableUse* var; //required
		Type* t; //required
};

class Stmts : public Node {
	public:
		Stmts();
		Stmts(Stmt* s);
		Stmts(Stmt* s, Stmts* next);
		int getNumVarUses();

		Stmt* left;
		Stmts* right;
};

/*///////////////////////////////////////////////////////////////
	TRANSITIONS
*///////////////////////////////////////////////////////////////

class Transition : public Node {
	public:
		Transition();
		Transition(Stmts*, Expr*); //when exiting
		Transition(string, Stmts*, Expr*); //normal case
		int getNumVarUses();

		Stmts *toPerform;
		Expr *eval;
		string toGoto; //optional, if empty just exit

};

class Transitions : public Node {
	public:
		Transitions();
		Transitions(Transition* tr, Transitions* next);
		int getNumVarUses();

		Transition* left;
		Transitions* right;
};


#endif // AST_H_INCLUDED

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

/*
class Plus : public BinOp {
	public:
		Plus();

		Plus(Expr* left, Expr* right)  : BinOp(left, right) {};

};

class Minus : public BinOp {

	public:

		Minus();

		Minus(Expr* left, Expr* right)  : BinOp(left, right) {};

};

class Mul : public BinOp {
	public:

		Mul();
		Mul(Expr* left, Expr* right)  : BinOp(left, right) {};
};


class Div : public BinOp {
	public:
		Div();
		Div(Expr* left, Expr* right)  : BinOp(left, right) {};

};

class equalEquals : public BinOp{
	public:

		equalEquals(Expr* left, Expr* right) : BinOp(left, right) {}
};

class lThanEquals : public BinOp{ //FIXME:

	public:
		lThanEquals(Expr* left, Expr* right) : BinOp(left, right) {}
};


class gThanEquals : public BinOp{ //FIXME:
	public:
		gThanEquals(Expr* left, Expr* right) : BinOp(left, right) {}
};


class nEquals : public BinOp{ //FIXME:
	public:
		nEquals(Expr* left, Expr* right) : BinOp(left, right) {}

};


class lessThan : public BinOp{

	public:
		lessThan(Expr* left, Expr* right) : BinOp(left, right) {}
};



class greaterThan : public BinOp{
	public:
		greaterThan(Expr* left, Expr* right) : BinOp(left, right) {}

};
*/


////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
