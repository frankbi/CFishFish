#ifndef AST_H_INCLUDED
#define AST_H_INCLUDED

#include <cstdlib>
#include <string>
#include <vector>

//For the classes that make up the parser's abstract syntax tree
using namespace std;

class Platform;
class Decls;
class State;
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

    virtual ~Node()=0; //make destructor pure virtual so that Node remains abstract, only necessary if there are no other pure virtual functions here
	//virtual bool errorCheck() = 0;
	//virtual bool generateCode() = 0;
};

class Type : public Node{
    public:
        Type(){}
        Type(enum TypeEnum);
        enum TypeEnum getType();
    private:
        enum TypeEnum t;
	//bool errorCheck();
};

class Program : public Node {
	public:
	    Program(); //dummy
	    Program(string name, Platform* platf, Decls* dec, vector<State*>* states);
	    //virtual bool errorCheck();
	    string getName();
        int getNumStates() ;
        int getNumVarDecls() ;
        int getNumVarUses() ;
	protected:
	    string programName;
	    Platform* platform; //required
	    Decls* decls;  //required
	    vector<State*>* states;
	    //States* states; //required
};

class Platform : public Node {
	public:
	    Platform(); //dummy
	    Platform(string name);
	    string platformName;
	    //bool errorCheck();
        //int getNumVarDecls(); Not necessary I don't think
};

class Decl : public Node {
	public:
	    Decl(); //dummy
	    Decl(Type t, string varname);
	    Type declType;
	    string variableName;
	    //bool errorCheck(); // check for collisions in declarations

};


/*********************************************************/

class Decls : public Node {
	public:
	    Decls();
	    Decls(Decl* left, Decls* right);
	    Decl* left; //optional
	    Decls* right; //optional
	    //bool errorCheck();
	    int getNumVarDecls();
};


/*********************************************************/

class State : public Node {
	public:
	    State(); //dummy
	    State(Transitions* tran);
	    Transitions* tran; //required
	    bool errorCheck();
	    int getNumVarUses();
};

/*
class States : public Node {
	public:
	    States();
	    States(State* left, States* right);
	    State* left; //optional
	    States* right; //optional
	    //bool errorCheck();
        int getNumStates();
        int getNumVarUses();
};*/




class Expr : public Node { //abstract
    public:
 //       virtual void* value() = 0;
        Type getType();
        virtual int getNumVarUses();
    private:
        Type t;
};

class BinOp : public Expr { //abstract, do not construct
    public:
    BinOp(){};
    BinOp(Expr* left, Expr* right);
        virtual ~BinOp() = 0;
        Expr* left; //required
        Expr* right; //required
        int getNumVarUses();


};

class Plus : public BinOp {
    public:
        Plus(); //dummy
        Plus(Expr* left, Expr* right)  : BinOp(left, right) {};
   //     void* value();
};
class Minus : public BinOp {
    public:
        Minus(); //dummy
        Minus(Expr* left, Expr* right)  : BinOp(left, right) {};
   //     void* value();

};
class Mul : public BinOp {
    public:
        Mul(); //dummy
        Mul(Expr* left, Expr* right)  : BinOp(left, right) {};
  //      void* value();
};
class Div : public BinOp {
    public:
        Div(); //dummy
        Div(Expr* left, Expr* right)  : BinOp(left, right) {};
 //       void* value();
        //bool errorCheck(); //also check for div by 0
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




class Constant : public Expr {
    public:
        //bool errorCheck(); //always OK
        //Constant();
    private:

};

class IntConst : public Constant {
    public:
        IntConst(int x);
//        void* value();
    private:
        int val;
};

class FloatConst : public Constant {
    public:
        FloatConst(float f);
//        void* value();
    private:
        float val;
};


class CharConst : public Constant{
    public:
        CharConst(char c);
//        void* value();
    private:
        char val;
};

class StringConst : public Constant{
    public:
        StringConst(string s);
//        void* value();
    private:
        string val;
};

class BoolConst : public Constant {
    public:
        BoolConst(bool b);
//        void* value();
    private:
        bool val;
};

class VariableUse : public Expr {
    public:
        VariableUse(); //dummy
        VariableUse(string s);
        //bool errorCheck(); //check if previously declared or not
   //     void* value(); //always NULL, restructure maybe
        int getNumVarUses();
    private:
            string name;
};

class Stmt : public Node {
    public:
	    Stmt(); //dummy
	    Stmt(Expr* expr, VariableUse* var);
	    int getNumVarUses();
	    //bool errorCheck();
    private:
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
    //bool errorCheck();
    private:
    Stmt* left; //optional
    Stmts* right; //optional
};

class Transition : public Node {
    public:
    Transition(); //dummy
    Transition(Stmts*, Expr*); //when exiting
    Transition(string, Stmts*, Expr*); //normal case
    //bool errorCheck();
    int getNumVarUses();
    private:
    Stmts* toPerform; //required
    Expr* eval; //required
    //VariableUse* toGoto;
    string toGoto; //optional, if empty just exit

};

class Transitions : public Node {
    public:
    Transitions();
    //Transitions(Transition* tr);
    Transitions(Transition* tr, Transitions* next);
    //bool errorCheck();
    int getNumVarUses();
    private:
    Transition* left; //optional
    Transitions* right; //optional
};



#endif // AST_H_INCLUDED
