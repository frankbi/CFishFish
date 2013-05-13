/* A recursive descent parser with operator precedence.

   Author: Eric Van Wyk

   This algorithm is based on the work of Douglas Crockford in "Top
   Down Operator Precedence", a chapter in the book "Beautiful Code".
   Mr. Crockford describes in his chapter how his work is based on an
   algorithm described Vaughan Pratt in "Top Down Operator
   Precedence", presented at the ACM Symposium on Principles of
   Programming Languages.

   Douglas Crockford's chapter is available at
    http://javascript.crockford.com/tdop/tdop.html

   Vaughan Pratt's paper is available at
    http://portal.acm.org/citation.cfm?id=512931

   These are both quite interesting works and worth reading if you
   find the problem of parsing to be an interesting one.

   Last modified: March 5, 2013.
*/

/*

    So that we did not have to implement everything before being able to run tests on the parser,
    we created dummy objects in each parse function with a constructor that took no arguments. This
    way running the tests would not result in a segmentation fault as a higher-level parse function
    attempted to call dynamic_cast on a NULL pointer.

    We wrote the parse functions from top to bottom, starting with Program and ending with the subclasses
    of Expr and BinOp. Because we created dummy objects in the lower-level parse functions, our parser
    could successfully return a Program and our tests could call getName() or getNumVarUses() on it before
    we wrote anything else, they just would not necessarily return the right value.

*/

#include "parser.h"
#include "scanner.h"
#include "extToken.h"
#include "ast.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std ;

Parser::Parser ( ) { }

ParseResult Parser::parse (const char *text) {
    assert (text != NULL) ;

    ParseResult pr ;
    try {
        Scanner *s = new Scanner() ;
        tokens = extendTokenList ( this, s->scan (text) ) ;

        assert (tokens != NULL) ;
        currToken = tokens ;
        pr = parseProgram( ) ;
    }
    catch (string errMsg) {
        pr.ok = false ;
        pr.errors = errMsg ;
        // pr.ast = NULL ;
    }
    return pr ;
}

/*
 * parse methods for non-terminal symbols
 * --------------------------------------
 */

// Program
ParseResult Parser::parseProgram () {
    ParseResult pr ;

    // Program ::= nameKwd colon variableName semiColon Platform Decls States

    match(nameKwd) ;
    match(colon) ;
    match(variableName) ;

    string s(prevToken->lexeme);
    match(semiColon) ;

    ParseResult platform_result = parsePlatform() ;

    Platform* plat = dynamic_cast<Platform*>(platform_result.ast); // will segfault because parsePlatform is not yet implemented, the returned parseResult's AST pointer will be NULL
    if (plat == NULL) cout << "Platform NULL\n";

    ParseResult decls_result = parseDecls() ;
    Decls* decl = dynamic_cast<Decls*>(decls_result.ast);
    assert(decl != NULL);

    ParseResult states_result = parseStates() ;
    States* state = dynamic_cast<States*>(states_result.ast);
    assert(state != NULL);

    Program* p = new Program(s, plat, decl, state);

    match(endOfFile) ;

	// put Program p into parseResult
	// TODO: error strings
	pr.ast = (Node*)p;
	pr.ok = true;

    return pr ;
}
















// State
ParseResult Parser::parseState () {
    ParseResult pr ;
    bool isInitial ;
    
    // State ::= stateKwd colon variableName
    //           leftCurly Transitions rightCurly
    // State ::= initialKwd stateKwd colon variableName
    //           leftCurly Transitions rightCurly

	
    if ( attemptMatch(initialKwd) ) {
        isInitial = true ;
    } else {
        isInitial = false ;
	}
	

    match(stateKwd) ;
    match(colon) ;
    match(variableName) ;
    string s(prevToken->lexeme);
    match(leftCurly) ;


    ParseResult parse_transitions = parseTransitions() ;
    Transitions* tran = dynamic_cast<Transitions*>(parse_transitions.ast);
    match(rightCurly) ;
    State* p = new State(tran, s);
    pr.ast = p;
    pr.ok = true;

    return pr ;
}



// States
ParseResult Parser::parseStates () {
    ParseResult pr ;

    if ( ! nextIs(endOfFile) ) {
        // States ::= State States
        
        ParseResult parse_state = parseState() ;
        State* left = dynamic_cast<State*>(parse_state.ast);
        
        ParseResult parse_states = parseStates() ;
        States* right = dynamic_cast<States*>(parse_states.ast);
        
        States* p = new States(left, right);

        pr.ast = p;
    }
    else {
        // States ::=
        // nothing to match.
        States* em = new States();
        pr.ast = em;
    }

    pr.ok = true;
    return pr ;
}













// Decls
ParseResult Parser::parseDecls () {
    ParseResult pr ;

    if ( ! nextIs(initialKwd) && ! nextIs(stateKwd) ) {
        // Decls ::= Decl Decls

       ParseResult parse_decl = parseDecl() ;
       Decl* left =  dynamic_cast<Decl*>(parse_decl.ast);
       ParseResult parse_decls = parseDecls() ;
       Decls* right = dynamic_cast<Decls*>(parse_decls.ast);
       Decls* p = new Decls(left, right);

       pr.ast = p;

    }
    else {
        // Decls ::=
        // nothing to match.
        Decls* em = new Decls();
        pr.ast = em;

    }
       pr.ok = true;
    return pr ;
}

// Decl
ParseResult Parser::parseDecl () {
    ParseResult pr ;
    // Decl ::= Type variableName semiColon
    ParseResult parse_type = parseType() ;
    Type* t = dynamic_cast<Type*>(parse_type.ast);

    assert (dec != NULL);

    match(variableName) ;
    string s(prevToken->lexeme);

    match(semiColon) ;

    Decl* p = new Decl(*t, s);
    pr.ast = p;
    pr.ok = true;

    return pr ;
}






// Type
ParseResult Parser::parseType () {
    ParseResult pr ;
    Type* t;
    if ( attemptMatch(intKwd) ) {
        // Type ::= intKwd
        t = new Type(Int);
    }
    else if ( attemptMatch(floatKwd) ) {
        // Type ::= floatKwd
        t = new Type(Float);
    }
    else if ( attemptMatch(booleanKwd) ) {
        // Type ::= booleanKwd
        t = new Type(Boolean);
    }
    else if ( attemptMatch(stringKwd) ) {
        // Type ::= stringKwd
        t = new Type(String);
    }
    else {
        // Type ::= charKwd
        match(charKwd) ;
        t = new Type(Char);
    }

    pr.ast = (Node*)t;
    return pr ;
}












// Platform
ParseResult Parser::parsePlatform () {
    ParseResult pr ;

    // Platform ::= platformKwd colon variableName semiColon
    match(platformKwd) ;
    match(colon) ;
    match(variableName) ;
    string s(prevToken->lexeme);

    match(semiColon) ;

    Platform* p = new Platform(s);
    pr.ast = (Node*)p;
    pr.ok = true;

    return pr ;
}









/* ----------------------------------------------------------- */


// Transitions
ParseResult Parser::parseTransitions () {
    ParseResult pr ;
    Transitions* t;
    if ( ! nextIs(rightCurly) ) {
        // Transitions ::= Transition Transitions
        ParseResult tran_result = parseTransition();
        Transition* tran = dynamic_cast<Transition*>(tran_result.ast);
        ParseResult next_result = parseTransitions() ;
        Transitions* next =  dynamic_cast<Transitions*>(next_result.ast);
        t = new Transitions(tran, next);

    }
    else {
        // Transitions ::=
        // nothing to match.
        t = new Transitions();
    }

    pr.ast = (Node*)t;
    return pr ;
}


// Transition
ParseResult Parser::parseTransition () {
    ParseResult pr ;
    Transition* t;// = new Transition();
    if ( nextIs(gotoKwd) ) {
        // Transition ::= gotoKwd variableName whenKwd Expr
        //                performingKwd leftCurly Stmts rightCurly semiColon
        match(gotoKwd) ;
        match(variableName) ;
        string toGoto(prevToken->lexeme);
        match(whenKwd) ;
        ParseResult expr_result = parseExpr(0);
        Expr* expr = dynamic_cast<Expr*>(expr_result.ast);
        match(performingKwd) ;
        match(leftCurly) ;
        ParseResult statements_result = parseStmts() ;
        Stmts* statements = dynamic_cast<Stmts*>(statements_result.ast);
        match(rightCurly) ;
        match(semiColon) ;
        t = new Transition(toGoto, statements, expr);
    }
    else {
        // Transition ::= exitKwd whenKwd Expr
        //                performingKwd leftCurly Stmts rightCurly semiColon
        match(exitKwd) ;
        match(whenKwd) ;
        ParseResult expr_result = parseExpr(0) ;
        Expr* expr = dynamic_cast<Expr*>(expr_result.ast);
        match(performingKwd) ;
        match(leftCurly) ;
        ParseResult statements_result = parseStmts() ;
        Stmts* statements = dynamic_cast<Stmts*>(statements_result.ast);
        match(rightCurly) ;
        match(semiColon) ;
        t = new Transition(statements, expr);
    }
    pr.ast = (Node*)t;
    return pr ;
}


// Stmts
ParseResult Parser::parseStmts () {
    ParseResult pr ;
    Stmts* statements;

    if ( ! nextIs(rightCurly) ) {
        // Stmts ::= Stmt Stmts
        ParseResult left_result = parseStmt() ;
        Stmt* left = dynamic_cast<Stmt*>(left_result.ast);
        ParseResult right_result = parseStmts() ;
        Stmts* right = dynamic_cast<Stmts*>(right_result.ast);
        statements = new Stmts(left, right);
    }
    else {
        // Stmts ::=
        // nothing to match.
        statements = new Stmts();
    }
    pr.ast = (Node*)statements;
    return pr ;
}


// Stmt
ParseResult Parser::parseStmt () {
    ParseResult pr ;

    // Stmt ::= variableName assign Expr semiColon
    match(variableName) ;
    VariableUse* v = new VariableUse(prevToken->lexeme);
    match(assign) ;
    ParseResult expr_result = parseExpr(0) ;
    Expr* expr = dynamic_cast<Expr*>(expr_result.ast);
    match(semiColon) ;
	Stmt* s = new Stmt(expr, v);
    pr.ast = (Node*)s;
    return pr ;
}

// Expr
ParseResult Parser::parseExpr (int rbp) {
    /* Examine current token, without consuming it, to call its
       associated parse methods.  The ExtToken objects have 'nud' and
       'led' methods that are dispatchers that call the appropriate
       parse methods.*/
    ParseResult left = currToken->nud() ;

    while (rbp < currToken->lbp() ) {
        left = currToken->led(left) ;
    }

    return left ;
}


/*
 * parse methods for Expr productions
 * ----------------------------------
 */

// Expr ::= trueKwd
ParseResult Parser::parseTrueKwd ( ) {
    ParseResult pr ;
    match ( trueKwd ) ;
    pr.ast = new BoolConst(true);
    return pr ;
}

// Expr ::= falseKwd
ParseResult Parser::parseFalseKwd ( ) {
    ParseResult pr ;
    match ( falseKwd ) ;
    pr.ast = new BoolConst(false);
    return pr ;
}

// Expr ::= intConst
ParseResult Parser::parseIntConst ( ) {
    ParseResult pr ;
    match ( intConst ) ;
    int x;
    istringstream(prevToken->lexeme) >> x;
    pr.ast = new IntConst(x);
    return pr ;
}

// Expr ::= floatConst
ParseResult Parser::parseFloatConst ( ) {
    ParseResult pr ;
    match ( floatConst ) ;
    float x;
    istringstream(prevToken->lexeme) >>x;
    pr.ast = new FloatConst(x);
    return pr ;
}

// Expr ::= stringConst
ParseResult Parser::parseStringConst ( ) {
    ParseResult pr ;
    match ( stringConst ) ;
    pr.ast = (Node*)new StringConst(prevToken->lexeme);
    return pr ;
}

// Expr ::= charConst
ParseResult Parser::parseCharConst ( ) {
    ParseResult pr ;
    match ( charConst ) ;
    pr.ast = (Node*)new CharConst(prevToken->lexeme[1]);
    return pr ;
}

// Expr ::= variableName
ParseResult Parser::parseVariableName ( ) {
    ParseResult pr ;
    match ( variableName ) ;
    pr.ast = (Node*)new VariableUse();
    return pr ;
}


// Expr ::= leftParen Expr rightParen
ParseResult Parser::parseNestedExpr ( ) {
    ParseResult pr ;
    match ( leftParen ) ;
    pr = parseExpr(0) ;
    match(rightParen) ;
    return pr ;
}

// Expr ::= Expr plusSign Expr
ParseResult Parser::parseAddition ( ParseResult left ) {
    // parser has already matched left expression
    ParseResult pr ;

    match ( plusSign ) ;
    ParseResult right = parseExpr( prevToken->lbp() );
    Expr *leftexpr, *rightexpr;
    leftexpr = dynamic_cast<Expr*>(left.ast);
    rightexpr = dynamic_cast<Expr*>(right.ast);

    Plus* p = new Plus(leftexpr, rightexpr);
    pr.ast = (Node*)p;
    return pr ;
}

// Expr ::= Expr star Expr
ParseResult Parser::parseMultiplication ( ParseResult left ) {
    // parser has already matched left expression
    ParseResult pr ;

    match ( star ) ;
    ParseResult right = parseExpr( prevToken->lbp() );
    Expr *leftexpr, *rightexpr;
    leftexpr = dynamic_cast<Expr*>(left.ast);
    rightexpr = dynamic_cast<Expr*>(right.ast);


    Mul* m = new Mul(leftexpr, rightexpr);
    pr.ast = (Node*)m;
    return pr ;
}

// Expr ::= Expr dash Expr
ParseResult Parser::parseSubtraction ( ParseResult left ) {
    // parser has already matched left expression
    ParseResult pr ;

    match ( dash ) ;
    ParseResult right = parseExpr( prevToken->lbp() );
    Expr *leftexpr, *rightexpr;
    leftexpr = dynamic_cast<Expr*>(left.ast);
    rightexpr = dynamic_cast<Expr*>(right.ast);

    Minus* m = new Minus(leftexpr, rightexpr);
    pr.ast = (Node*)m;
    return pr ;
}

// Expr ::= Expr forwardSlash Expr
ParseResult Parser::parseDivision ( ParseResult left ) {
    // parser has already matched left expression
    ParseResult pr ;

    match ( forwardSlash ) ;
    ParseResult right = parseExpr( prevToken->lbp() );
    Expr *leftexpr, *rightexpr;
    leftexpr = dynamic_cast<Expr*>(left.ast);
    rightexpr = dynamic_cast<Expr*>(right.ast);

    Div* d = new Div(leftexpr, rightexpr);
    pr.ast = (Node*)d;
    return pr ;
}


// Expr ::= Expr equalEquals Expr
// Expr ::= Expr lessThanEquals Expr
// Expr ::= Expr greaterThanEquals Expr
// Expr ::= Expr notEquals Expr
// Expr ::= Expr leftAngle Expr
// Expr ::= Expr rightAngle Expr
/* Notice that for relational operators we use just one parse
   function.  This shows another possible means for implementing
   expressions, as opposed to the method used for arithmetic
   expressions in which each operation has its own parse method.  It
   will depend on what we do in iteration 3 in building an abstract
   syntax tree to decide which method is better.
 */
ParseResult Parser::parseRelationalExpr ( ParseResult left ) {
    // parser has already matched left expression
    ParseResult pr ;

    nextToken( ) ;
    // just advance token, since examining it in parseExpr caused
    // this method being called.
    string op(prevToken->lexeme);

    ParseResult right = parseExpr( prevToken->lbp() );

    Expr *leftexpr, *rightexpr;
    leftexpr = dynamic_cast<Expr*>(left.ast);
    rightexpr = dynamic_cast<Expr*>(right.ast);


    Expr* e;

    //examine the operator string
    // x ==
    if (op.compare("==") == 0) {
        equalEquals* expr = new equalEquals(leftexpr, rightexpr);
        e = (Expr*) expr;
    }
    else if (op.compare("<=") == 0) {
        lThanEquals* expr = new lThanEquals(leftexpr, rightexpr); //ERROR
        e = (Expr*) expr;
    }
    else if (op.compare(">=") == 0) {
        gThanEquals* expr = new gThanEquals(leftexpr, rightexpr); //ERROR
        e = (Expr*) expr;
    }
    else if (op.compare("!=") == 0) {
        nEquals* expr = new nEquals(leftexpr, rightexpr); //ERROR
        e = (Expr*) expr;
    }
    else if (op.compare("<") == 0) {
        lessThan* expr = new lessThan(leftexpr, rightexpr);
        e = (Expr*) expr;
    }
    else if (op.compare(">") == 0) {
         greaterThan* expr = new greaterThan(leftexpr, rightexpr);
         e = (Expr*) expr;
    }
    else e = new Expr(); //dummy
    //switch and create the appropriate object
    //cast to Node and return






    pr.ast = (Node*)e;
    return pr ;
}


// Helper function used by the parser.

void Parser::match (tokenType tt) {
    if (! attemptMatch(tt)) {
        throw ( makeErrorMsgExpected ( tt ) ) ;
    }
}

bool Parser::attemptMatch (tokenType tt) {
    if (currToken->terminal == tt) {
        nextToken() ;
        return true ;
    }
    return false ;
}

bool Parser::nextIs (tokenType tt) {
    return currToken->terminal == tt ;
}

void Parser::nextToken () {
    if (currToken->terminal == endOfFile && currToken->next == NULL) {
        prevToken = currToken ;
    } else if (currToken->terminal != endOfFile && currToken->next == NULL) {
        throw ( makeErrorMsg ( "Error: tokens end with endOfFile" ) ) ;
    } else {
        prevToken = currToken ;
        currToken = currToken->next ;
    }
}

string Parser::terminalDescription ( tokenType terminal ) {
    Token *dummyToken = new Token (terminal, NULL, "") ;
    ExtToken *dummyExtToken = extendToken (this, dummyToken) ;
    string s = dummyExtToken->description() ;
    delete dummyToken ;
    delete dummyExtToken ;
    return s ;
}

string Parser::makeErrorMsgExpected ( tokenType terminal ) {
    string s = (string) "Expected " + terminalDescription (terminal) +
        " but found " + currToken->description() ;
    return s ;
}

string Parser::makeErrorMsg ( tokenType terminal ) {
    string s = "Unexpected symbol " + terminalDescription (terminal) ;
    return s ;
}

string Parser::makeErrorMsg ( const char *msg ) {
    return msg ;
}

