/* ExtToken: an extension of the Token class with new methods for parsing
   (led, nud, lbp) and describing the token.

   Author: Eric Van Wyk

   Last modified: March 4, 2013.
*/

#include "extToken.h"
#include "parser.h"

#include <string>

using namespace std ;

ExtToken *extendToken (Parser *p, Token *tokens) {
    switch ( tokens->terminal ) {

    // Keywords
    case nameKwd: return new ExtToken(p,tokens,"'name'") ;
    case platformKwd: return new ExtToken(p,tokens,"'platform'") ;
    case initialKwd: return new ExtToken(p,tokens,"'initial'") ;
    case stateKwd: return new ExtToken(p,tokens,"'state'") ;

    case gotoKwd: return new ExtToken(p,tokens,"'goto'") ;
    case whenKwd: return new ExtToken(p,tokens,"'when'") ;
    case performingKwd: return new ExtToken(p,tokens,"'performing'") ;
    case exitKwd: return new ExtToken(p,tokens,"'exit'") ;

    case trueKwd: return new TrueKwdToken(p,tokens);
    case falseKwd: return new FalseKwdToken(p,tokens);

    case intKwd: return new ExtToken(p,tokens,"'int'") ;
    case floatKwd: return new ExtToken(p,tokens,"'float'") ;
    case stringKwd: return new ExtToken(p,tokens,"'string'") ;
    case charKwd: return new ExtToken(p,tokens,"'char'") ;
    case booleanKwd: return new ExtToken(p,tokens,"'boolean'") ;

    // Constants
    case intConst: return new IntConstToken(p,tokens) ;
    case floatConst: return new FloatConstToken(p,tokens) ;
    case stringConst: return new StringConstToken(p,tokens) ;
    case charConst: return new CharConstToken(p,tokens) ;

    // Names
    case variableName: return new VariableNameToken(p,tokens) ;

    // Punctuation
    case leftParen: return new LeftParenToken(p,tokens) ;
    case rightParen: return new ExtToken(p,tokens,")") ;
    case leftCurly: return new ExtToken(p,tokens,"{") ;
    case rightCurly: return new ExtToken(p,tokens,"}") ;

    case colon: return new ExtToken(p,tokens,":") ;
    case comma: return new ExtToken(p,tokens,",") ;
    case semiColon: return new ExtToken(p,tokens,";") ;
    case assign: return new ExtToken(p,tokens,":=") ;

    case plusSign: return new PlusSignToken(p,tokens) ;
    case star: return new StarToken(p,tokens) ;
    case dash: return new DashToken(p,tokens) ;
    case forwardSlash: return new ForwardSlashToken(p,tokens) ;

    case leftAngle:
    case rightAngle:
    case equalsEquals:
    case lessThanEquals:
    case greaterThanEquals:
    case notEquals:
        return new RelationalOpToken(p, tokens, tokens->lexeme) ;

    case lexicalError: return new ExtToken(p,tokens,"lexical error") ;
    case endOfFile: return new EndOfFileToken(p,tokens) ;


    default:
        string msg = (string) "Unspecified terminal in extend." ;
        throw ( p->makeErrorMsg ( msg.c_str() ) ) ;
    }
}

ExtToken *extendTokenList (Parser *p, Token *tokens) {
    ExtToken *extTokens = NULL ;
    ExtToken *prevExtToken = NULL ;

    while (tokens != NULL) {
        ExtToken *currExtToken = extendToken(p, tokens) ;

        // Add new ExtToken et to the list
        if (extTokens != NULL) {
            prevExtToken->next = currExtToken ;
        }
        else {
            extTokens = currExtToken ;
        }
        prevExtToken = currExtToken ;

        tokens = tokens->next ;
    }

    return extTokens ;
}
